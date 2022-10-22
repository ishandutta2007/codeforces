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

void solve(int n, const string& _s, const string& _t) {
    V<int> s(n), t(n);
    rep(i, n) {
        s[i] = (_s[i] == '1');
        t[i] = (_t[i] == '1');
    }

    V<int> vec;
    bool r = 0;
    int p = 0, q = n - 1;
    per(i, n) {
        char a = (r ? s[p] ^ 1 : s[q]);
        char b = t[i];

        if (a == b) {
            if (r)
                p++;
            else
                q--;
            continue;
        }
        char c = (r ? s[q] ^ 1 : s[p]);
        if (c == b) {
            vec.pb(0);
        }
        vec.pb(i);
        if (r)
            q--;
        else
            p++;
        r ^= 1;
    }
    cout << vec.size() << ' ';
    for (int x : vec) cout << x + 1 << ' ';
    cout << '\n';
    /*
        for (int x : vec) {
            rep(i, x + 1) { s[i] ^= 1; }
            reverse(s.begin(), s.begin() + x + 1);
        }
        debug(s, t);*/
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}