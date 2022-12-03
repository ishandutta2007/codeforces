#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back

using ll = long long;
using i_i = tuple<int, int>;

template <typename F>
struct FixPoint : F {
    FixPoint(F&& f) : F(forward<F>(f)) {}
    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return F::operator()(*this, forward<Args>(args)...);
    }
};

template <typename F>
FixPoint<F> fp(F&& f) {
    return FixPoint<F>(forward<F>(f));
}

template <typename F>
vector<int> smawk(int N, int M, F&& f) {
    using T = result_of_t<F(int, int)>;
    vector<int> cols(M);
    iota(all(cols), 0);
    vector<int> argmin(N, -1);
    fp(
        [&] (auto&& rec, int s, vector<int> cols) -> void {
            int R = (N + s - 1) / s;
            if (R < cols.size()) {
                vector<int> S;
                for (int j: cols) {
                    while (!S.empty()) {
                        int i = (S.size() - 1) * s;
                        int _j = S.back();
                        if (f(i, _j) > f(i, j)) S.pop_back();
                        else break; 
                    }
                    if (S.size() < R) S.push_back(j);
                }
                cols = move(S);
            }
            if (R == 1) {
                argmin[0] = cols[0];
                return;
            }
            rec(s * 2, cols);
            int k = 0;
            for (int i = s; i < N; i += s * 2) {
                T mi;
                for (; k < cols.size(); k++) {
                    int j = cols[k];
                    T x = f(i, j);
                    if (argmin[i] == -1 || x < mi) {
                        argmin[i] = j;
                        mi = x;
                    }
                    if (i + s < N && j == argmin[i + s]) break;
                }
            }
        }
    )(1, cols);
    return argmin;
}

template <typename F>
vector<int> monotone_minima(int N, int M, F&& f) {
    using T = result_of_t<F(int, int)>;
    vector<int> argmin(N, -1);
    for (int s = 1<<(31 - __builtin_clz(N)); s >= 1; s /= 2) {
        for (int i = s - 1; i < N; i += s * 2) {
            int jl = (i - s >= 0) ? argmin[i - s] : 0;
            int jr = (i + s < N) ? argmin[i + s] : (M - 1);
            T mi;
            for (int j = jl; j <= jr; j++) {
                T x = f(i, j);
                if (argmin[i] == -1 || x < mi) {
                    argmin[i] = j;
                    mi = x;
                }
            }
        }
    }
    return argmin;
}

template <typename F>
vector<int> monotone_minima_fast(int N, int M, F&& f) {
    using T = result_of_t<F(int, int)>;
    vector<int> argmin(N, -1);
    for (int s = 1<<(31 - __builtin_clz(N)); s >= 1; s /= 2) {
        int j = 0;
        for (int i = s - 1; i < N; i += s * 2) {
            T mi;
            for (; j < M; j++) {
                T x = f(i, j);
                if (argmin[i] == -1 || x < mi) {
                    argmin[i] = j;
                    mi = x;
                }
                if (i + s < N && argmin[i + s] == j) break;
            }
        }
    }
    return argmin;
}

int main() {
    int N; cin >> N;
    vector<tuple<int, int, ll>> xya(N);
    rep(i, N) {
        int x, y; ll a;
        scanf("%d%d%lld", &x, &y, &a);
        xya[i] = make_tuple(x, y, a);
    }
    sort(all(xya));
    vector<int> x(N + 1), y(N + 1);
    vector<ll> a(N + 1);
    rep(i, N) tie(x[i + 1], y[i + 1], a[i + 1]) = xya[i];
    vector<ll> dp(N + 1, LLONG_MAX / 2);
    dp[0] = 0;
    fp(
        [&] (auto&& rec, int l, int r) -> void {
            if (r - l == 1) return;
            int m = (l + r) / 2;
            rec(l, m);
            auto f = [&] (int k1, int k2) -> ll {
                int i1 = m + k1;
                int i2 = l + k2;
                return dp[i2] - (ll)(x[i1] - x[i2]) * y[i1] + a[i1];
            };
            vector<int> argmin = monotone_minima(r - m, m - l, f);
            rep(k, r - m) {
                int i = m + k;
                dp[i] = min(dp[i], f(k, argmin[k]));
            }
            rec(m, r);
        }
    )(0, N + 1);
    ll ans = *min_element(all(dp));
    cout << -ans << endl;
}