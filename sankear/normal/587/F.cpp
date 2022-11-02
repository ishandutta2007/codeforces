#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <complex>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define pbk pop_back
#define sz(s) ((int) (s).size())
#define len(s) ((int) (s).size())
#define all(x) (x).begin(), (x).end()
#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#define cerr if (0) cerr
#endif
#if _WIN32 || __WIN32__ || _WIN64 || __WIN64__
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
#define next _next
#define prev _prev
#define link _link
#define rank _rank
#define hash _hash

typedef long long ll;
typedef long long llong;
typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef unsigned long long ullong;
typedef unsigned long long lint;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double ld;

const int inf = 1e9;
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e5) + 100;
const int K = 333;

int n, sz;
char buf[N];
int len[N], link[N], pv[N], pc[N], val[N], qu[N];
char* s[N];
int next[N][26], go[N][26];
ll ans[N];
vi lst[N], fin[N], g[N];
vector<pair<pii, int> > q[N];
ll blocks[N], in_block[N];

inline void init() {
    sz = 1;
    for (int i = 0; i < 26; ++i) {
        next[0][i] = -1;
    }
}

inline void solve_big(int num) {
    for (int i = 0; i < sz; ++i) {
        val[i] = 0;
    }
    int cur = 0;
    for (int i = 0; i < len[num]; ++i) {
        cur = next[cur][s[num][i] - 'a'];
        ++val[cur];
    }
    for (int i = sz - 1; i >= 0; --i) {
        if (qu[i] != 0) {
            val[link[qu[i]]] += val[qu[i]];
        }
    }
    for (int i = 0; i < n; ++i) {
        blocks[i] = (i > 0 ? blocks[i - 1] : 0);
        cur = 0;
        for (int j = 0; j < len[i]; ++j) {
            cur = next[cur][s[i][j] - 'a'];
        }
        blocks[i] += val[cur];
    }
    for (int i = 0; i < sz(q[num]); ++i) {
        int l = q[num][i].fs.fs, r = q[num][i].fs.sc, j = q[num][i].sc;
        ans[j] += blocks[r] - (l > 0 ? blocks[l - 1] : 0);
    }
}

inline void add(int a, int b) {
    for (int i = a; i < min(n, (a / K) * K + K); ++i) {
        in_block[i] += b;
    }
    for (int i = a / K + 1; i * K < n; ++i) {
        blocks[i] += b;
    }
}

inline ll get(int a) {
    return in_block[a] + blocks[a / K];
}

void dfs(int v) {
    for (int i = 0; i < sz(fin[v]); ++i) {
        add(fin[v][i], 1);
    }
    for (int i = 0; i < sz(lst[v]); ++i) {
        int num = lst[v][i];
        for (int j = 0; j < sz(q[num]); ++j) {
            int l = q[num][j].fs.fs, r = q[num][j].fs.sc, z = q[num][j].sc;
            ans[z] += get(r) - (l > 0 ? get(l - 1) : 0);
        }
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        dfs(g[v][i]);
    }
    for (int i = 0; i < sz(fin[v]); ++i) {
        add(fin[v][i], -1);
    }
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m;
    cin >> n >> m;
    gets(buf);
    init();
    for (int i = 0; i < n; ++i) {
        gets(buf);
        len[i] = strlen(buf);
        s[i] = new char[len[i] + 1];
        strcpy(s[i], buf);
        int cur = 0;
        for (int j = 0; j < len[i]; ++j) {
            int c = s[i][j] - 'a';
            if (next[cur][c] == -1) {
                for (int z = 0; z < 26; ++z) {
                    next[sz][z] = -1;
                }
                pv[sz] = cur;
                pc[sz] = c;
                next[cur][c] = sz++;
            }
            cur = next[cur][c];
            if (len[i] < K) {
                lst[cur].pb(i);
            }
        }
        fin[cur].pb(i);
    }
    int l = 0, r = 1;
    qu[0] = 0;
    while (l < r) {
        int v = qu[l++];
        if (v == 0 || pv[v] == 0) {
            link[v] = 0;
        } else {
            link[v] = go[link[pv[v]]][pc[v]];
        }
        for (int i = 0; i < 26; ++i) {
            if (next[v][i] != -1) {
                go[v][i] = next[v][i];
                qu[r++] = next[v][i];
            } else {
                if (v == 0) {
                    go[v][i] = 0;
                } else {
                    go[v][i] = go[link[v]][i];
                }
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        --l;
        --r;
        --k;
        q[k].pb(mp(mp(l, r), i));
    }
    for (int i = 0; i < n; ++i) {
        if (len[i] >= K) {
            solve_big(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        blocks[i] = 0;
    }
    for (int i = 1; i < sz; ++i) {
        g[link[i]].pb(i);
    }
    dfs(0);
    for (int i = 0; i < m; ++i) {
        printf(LLD "\n", ans[i]);
    }
    return 0;
}