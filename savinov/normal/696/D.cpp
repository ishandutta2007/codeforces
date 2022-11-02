#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define in(x) int (x); input((x));
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
typedef int itn;
using namespace std;
using vi = vector<int>;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

long long pw(long long a, long long n, long long m) {
    ll res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

ll mod = 1000000007;

const int K = 26;

struct vertex {
    int next[K];
    ll w;
    int p;
    int pch;
    int link;
    int go[K];
};

vertex t[300+1];
int sz;

void init() {
    t[0].p = t[0].link = -1;
    t[0].w = 0;
    memset (t[0].next, 255, sizeof t[0].next);
    memset (t[0].go, 255, sizeof t[0].go);
    sz = 1;
}

void add_string (const string & s, int w) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        int c = s[i]-'a';
        if (t[v].next[c] == -1) {
            memset (t[sz].next, 255, sizeof t[sz].next);
            memset (t[sz].go, 255, sizeof t[sz].go);
            t[sz].link = -1;
            t[sz].w = 0;
            t[sz].p = v;
            t[sz].pch = c;
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].w += w;
}

int go (int v, int c);

int get_link (int v) {
    if (t[v].link == -1)
    if (v == 0 || t[v].p == 0)
        t[v].link = 0;
    else
        t[v].link = go (get_link (t[v].p), t[v].pch);
    return t[v].link;
}

int go (int v, int c) {
    if (t[v].go[c] == -1)
    if (t[v].next[c] != -1)
        t[v].go[c] = t[v].next[c];
    else
        t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
    return t[v].go[c];
}

void solve(int test) {
    init();
    int n = nxt();

    ll l = nxt<ll>();


    ll a[n];
    forn(i, n) a[i] = nxt();

    forn(i, n) {
        string s;
        cin >> s;
        add_string(s, a[i]);
    }

    vector <ll> w(sz);

    forn (i, sz) {
        int x = i;
        ll s = 0;
        while (x) {
            s += t[x].w;
            x = get_link(x);
        }
        w[i] = s;
    }

    ll m[sz][sz];

    memset(m, 0x80, sizeof(m));

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < 26; ++j) {
            int t = go(i, j);
            m[i][t] = w[t];
        }
    }

    ll st[sz];

    memset(st, 0x80, sizeof(st));

    st[0] = 0;

    ll T[sz][sz];
    ll mm[sz][sz];

    ll tt[sz];

    while (l) {
        if (l & 1) {
            memset(tt, 0x80, sizeof(tt));

            for (int i = 0; i < sz; ++i) {
                if (st[i] < 0) continue;
                for (int j = 0; j < sz; ++j) {
                    if (m[i][j] < 0) continue;
                    tt[j] = max(tt[j], st[i] + m[i][j]);
                }
            }
            memcpy(st, tt, sizeof(st));
        }
        memset(T, 0x80, sizeof(T));
        forn(i, sz) forn(j, sz) mm[j][i] = m[i][j];
        forn(i, sz) forn(j, sz) forn(k, sz) {
                    if (m[i][k] >= 0 && mm[j][k] >= 0) {
                        T[i][j] = max(T[i][j], m[i][k] + mm[j][k]);
                    }
                }
        memcpy(m, T, sizeof(m));

        l >>= 1;
    }

    cout << *max_element(st, st + sz) << "\n";


}

int main(int argc, char **argv) {

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#else
#endif
#ifdef LOCAL
#else
#endif
//    init();
    int c = 0;
    int t = 1;
    while (t--) {
        solve(c++);
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}