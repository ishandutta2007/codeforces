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
#define SZ(x) ((int)(x).size())

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

int nxt[30], prv[30];
bool e[30];

int main() {
    int n;
    cin >> n;
    memset(nxt, -1, sizeof(nxt));
    memset(prv, -1, sizeof(prv));
    rep(i, n) {
        string s;
        cin >> s;
        for (auto c : s) {
            e[c - 'a'] = 1;
        }
        rep(j, SZ(s) - 1) {
            int a = s[j] - 'a', b = s[j + 1] - 'a';
            if (nxt[a] != -1 && nxt[a] != b) {
                puts("NO");
                return 0;
            }
            if (prv[b] != -1 && prv[b] != a) {
                puts("NO");
                return 0;
            }
            nxt[a] = b, prv[b] = a;
        }
    }

    V<string> cand;
    rep(i, 30) {
        if (e[i] && prv[i] == -1) {
            int v = i;
            string a;
            while (v != -1) {
                e[v] = 0;
                a.pb('a' + v);
                v = nxt[v];
            }
            cand.pb(a);
        }
    }
    rep(i, 30) if (e[i]) {
        puts("NO");
        return 0;
    }
    sort(ALL(cand));
    for (auto s : cand) {
        cout << s;
    }
    cout << endl;
    return 0;
}