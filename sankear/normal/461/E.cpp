#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second
#define next _next
#define prev _prev
#define rank _rank
#define link _link
#define hash _hash
#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef complex<double> tc;
typedef long double ld;

const int inf = int(1e9);
const double pi = 4 * atan(double(1.0));
const double eps = 1e-9;
const int N = int(1e5) + 100;

struct node {
    
    int len, link;
    int next[4];
    
};

int sz, last;
ll len;
node v[2 * N];
bool used[2 * N];
ll d[2 * N][4];
ll can[10][10];
char s[N];
vector<pii> g[2 * N];

inline void init() {
    sz = last = 0;
    v[0].len = 0;
    v[0].link = -1;
    for (int i = 0; i < 4; ++i) {
        v[0].next[i] = -1;
    }
}

inline void add(int c) {
    int nlast = ++sz;
    v[nlast].len = v[last].len + 1;
    for (int i = 0; i < 4; ++i) {
        v[nlast].next[i] = -1;
    }
    int p = last;
    while (p != -1 && v[p].next[c] == -1) {
        v[p].next[c] = nlast;
        p = v[p].link;
    }
    if (p == -1) {
        v[nlast].link = 0;
    } else {
        int q = v[p].next[c];
        if (v[p].len + 1 == v[q].len) {
            v[nlast].link = q;
        } else {
            int clone = ++sz;
            for (int i = 0; i < 4; ++i) {
                v[clone].next[i] = v[q].next[i];
            }
            v[clone].link = v[q].link;
            v[clone].len = v[p].len + 1;
            while (p != -1 && v[p].next[c] == q) {
                v[p].next[c] = clone;
                p = v[p].link;
            }
            v[nlast].link = v[q].link = clone;
        }
    }
    last = nlast;
}

void calc(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    for (int i = 0; i < 4; ++i) {
        d[v][i] = len + 10;
    }
    for (int i = 0; i < sz(g[v]); ++i) {
        if (g[v][i].fs == 0) {
            d[v][g[v][i].sc] = min(d[v][g[v][i].sc], 1LL);
        } else {
            calc(g[v][i].fs);
            for (int j = 0; j < 4; ++j) {
                d[v][j] = min(d[v][j], d[g[v][i].fs][j] + 1);
            }
        }
    }
}

ll mat[10][10], tmp[10][10];

void calc_mat(ll step) {
    if (step == 1) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mat[i][j] = can[i][j];
            }
        }
        return;
    }
    if (step % 2 == 0) {
        calc_mat(step / 2);
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                tmp[i][j] = len + 10;
                for (int z = 0; z < 4; ++z) {
                    tmp[i][j] = min(tmp[i][j], mat[i][z] + mat[z][j]);
                }
            }
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                mat[i][j] = tmp[i][j];
            }
        }
        return;
    }
    calc_mat(step - 1);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tmp[i][j] = len + 10;
            for (int z = 0; z < 4; ++z) {
                tmp[i][j] = min(tmp[i][j], mat[i][z] + can[z][j]);
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            mat[i][j] = tmp[i][j];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf(LLD, &len);
    scanf("%s", s);
    int n = (int) strlen(s);
    init();
    for (int i = 0; i < n; ++i) {
        add(s[i] - 'A');
    }
    for (int i = 0; i <= sz; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (v[i].next[j] != -1) {
                g[v[i].next[j]].pb(mp(i, j));
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            can[i][j] = len + 10;
        }
    }
    for (int i = 1; i <= sz; ++i) {
        calc(i);
        for (int j = 0; j < 4; ++j) {
            if (v[i].next[j] == -1) {
                for (int z = 0; z < 4; ++z) {
                    can[z][j] = min(can[z][j], 1LL * d[i][z]);
                }
            }
        }
    }
    ll ans = 1, l = 2, r = len;
    while (l <= r) {
        ll mid = (l + r) / 2;
        calc_mat(mid - 1);
        bool fl = false;
        for (int i = 0; i < 4 && !fl; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (mat[i][j] < len) {
                    fl = true;
                    break;
                }
            }
        }
        if (fl) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}