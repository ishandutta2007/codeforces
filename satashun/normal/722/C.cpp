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
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
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
    int n;
    cin >> n;
    V<int> a(n);
    rep(i, n) cin >> a[i];
    V<int> p(n);
    rep(i, n) cin >> p[i], --p[i];

    V<ll> s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i];
    set<int> ps;
    multiset<ll> ss;
    ps.insert(-1);
    ps.insert(n);
    ss.insert(s[n]);

    rep(i, n) {
        auto itr = ps.lower_bound(p[i]);
        auto itl = prev(itr);
        ss.erase(ss.find(s[*itr] - s[*itl + 1]));
        ss.insert(s[p[i]] - s[*itl + 1]);
        ss.insert(s[*itr] - s[p[i] + 1]);
        ps.insert(p[i]);
        cout << *rbegin(ss) << '\n';
    }

    return 0;
}