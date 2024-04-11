#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <complex>
#include <queue>
#include <deque>
#include <stack>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(s) int((s).size())
#define next _next

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 55;
const int M = 20;
const ll X = ll(2e5) + 3;
const int MOD = (1 << 16);

int step = 0, sz = 0;
ll p[M + 10];
char s[N][M + 10];
ll pref_h[N][(1 << (M / 2))];
ll suff_h[N][(1 << (M / 2))];
ll good[(1 << M)];
int used[MOD], first[MOD];
ll mem_h[N];
bool del[N];
int mem_cnt[N], next[N];
double prob[M + 10];

inline ll get_h(int num, int pref, int mask) {
    ll res = pref_h[num][mask & ((1 << pref) - 1)];
    res += suff_h[num][(mask >> pref)];
    return res;
}

inline void add(ll cur_h, int mask, int num) {
    int need = (cur_h & (MOD - 1));
    if (used[need] != step) {
        used[need] = step;
        first[need] = 0;
    }
    for (int i = first[need]; i > 0; i = next[i]) {
        if (mem_h[i] == cur_h) {
            if (!del[i]) {
                good[mask] ^= (1LL << mem_cnt[i]);
                del[i] = true;
            }
            return;
        }
    }
    mem_h[++sz] = cur_h;
    mem_cnt[sz] = num;
    del[sz] = false;
    good[mask] |= (1LL << num);
    next[sz] = first[need];
    first[need] = sz;
}

inline int get_sz(ll mask) {
    return __builtin_popcountll(mask);
    /*int res = 0;
    while (mask > 0) {
        res += (mask % 2);
        mask /= 2;
    }
    return res;*/
}

inline void gen() {
    cout << 50 << endl;
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 20; ++j) {
            cout << char('a' + rand() % 26);
        }
        cout << endl;
    }
    exit(0);
}

int main() {
    //gen();
    //cerr << (sizeof(p) + sizeof(s) + sizeof(pref_h) + sizeof(suff_h) + sizeof(good) + sizeof(used) + sizeof(first) + sizeof(mem_h) + sizeof(mem_cnt) + sizeof(next)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    int m = (int) strlen(s[0]), pref = m / 2, suff = m - pref;
    p[0] = 1;
    for (int i = 1; i < m; ++i) {
        p[i] = p[i - 1] * X;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << pref); ++j) {
            for (int z = 0; z < pref; ++z) {
                if ((j & (1 << z)) != 0) {
                    pref_h[i][j] += p[z] * s[i][z];
                }
            }
        }
        for (int j = 0; j < (1 << suff); ++j) {
            for (int z = 0; z < suff; ++z) {
                if ((j & (1 << z)) != 0) {
                    suff_h[i][j] += p[pref + z] * s[i][pref + z];
                }
            }
        }
    }
    for (int i = 0; i < (1 << m); ++i) {
        ++step;
        sz = 0;
        for (int j = 0; j < n; ++j) {
            ll cur_h = get_h(j, pref, i);
            add(cur_h, i, j);
        }
    }
    for (int i = 0; i < m; ++i) {
        prob[i] = 1;
        for (int j = 0; j < i; ++j) {
            prob[i] *= double(i - j) / (m - j);
        }
    }
    double ans = 0;
    for (int i = 1; i < (1 << m); ++i) {
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if ((i & (1 << j)) != 0) {
                ++cnt;
            }
        }
        for (int j = 0; j < m; ++j) {
            if ((i & (1 << j)) != 0) {
                ll diff = (good[i] ^ (good[i] & good[i ^ (1 << j)]));
                int sz = get_sz(diff);
                ans += prob[cnt - 1] / (m - cnt + 1) * cnt * sz / n;
            }
        }
    }
    printf("%.18lf\n", ans);
    return 0;
}