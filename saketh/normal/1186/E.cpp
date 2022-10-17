#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

#define FOR(i, a, b)    for (int i = (a); i < (b); i++)
#define F0R(i, a)       for (int i = 0; i < (a); i++)
#define FORd(i, a, b)   for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a)      for (int i = (a)-1; i >= 0; i--)
#define trav(a, x)      for (auto& a : x)

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace __input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T, size_t SZ> void re(array<T,SZ>& a);

    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
        re(first); re(rest...);
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
    template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
using namespace __input;

namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);

    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.f,", ",x.s,"}");
    }
    template<class T> void prContain(const T& x) {
        pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
        pr("}");
    }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, Q; re(N, M, Q);
    vs grid(N); re(grid);

    vvi pref(N + 1, vi(M + 1));
    F0R (i, N)
        F0R (j, M)
            pref[i+1][j+1] = grid[i][j] - '0'
            + pref[i+1][j] + pref[i][j+1] - pref[i][j];

    auto get = [&](ll i, ll j, ll x, ll y) {
        assert(x <= N); assert(y <= M);
        ll res = pref[x][y];
        if (__builtin_popcountll(i^j)&1) res = x * y - res;
        return res;
    };

    auto sum = [&](ll x, ll y) {
        ll i = x / N, j = y / M;
        ll res = N * M * (i * j / 2);
        if ((i * j)&1) res += get(i-1, j-1, N, M);

        res += (i/2) * N * (y % M);
        if (i&1) res += get(i-1, j, N, y % M);
        res += (j/2) * M * (x % N);
        if (j&1) res += get(i, j-1, x % N, M);

        res += get(i, j, x%N, y%M);
        return res;
    };

    F0R (q, Q) {
        int x1, y1, x2, y2;
        re(x1, y1, x2, y2);
        ps(sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1));
    }

    return 0;
}