#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

int main() {
    int N;
    cin >> N;
    V<int> v(N), t(N);
    rep(i, N) cin >> v[i];
    rep(i, N) cin >> t[i];
    V<ll> u(N + 1);
    rep(i, N) { u[i + 1] = u[i] + t[i]; }

    multiset<pair<ll, int>> st;

    ll sum = 0;

    rep(i, N) {
        ll ans = 0;
        sum += t[i];
        while (st.size()) {
            auto dat = *st.begin();
            ll vol, id;
            tie(vol, id) = dat;
            if (vol <= sum) {
                st.erase(st.begin());
                ans += (v[id] + u[id] - u[i]);
            } else {
                break;
            }
        }
        ans += st.size() * t[i];
        if (v[i] > t[i]) {
            st.insert(mp(v[i] + u[i], i));
            ans += t[i];
        } else {
            ans += v[i];
        }
        printf("%lld%c", ans, i == N - 1 ? '\n' : ' ');
    }

    return 0;
}