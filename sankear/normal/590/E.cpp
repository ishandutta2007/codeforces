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
const int N = 800;
const int LEN = int(1e7) + 10;

int n, sz;
bool used[N], used_left[N], used_right[N];
int res_left[N], res_right[N], len[N], ver[N];
char* s[N];
char buf[LEN];
int link[LEN], pv[LEN], pc[LEN], num[LEN], q[LEN];
int next[LEN][2], go[LEN][2];
bool can[N][N];
vi ans;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int i = 0; i < n; ++i) {
        if (can[v][i] && (res_right[i] == -1 || dfs(res_right[i]))) {
            res_left[v] = i;
            res_right[i] = v;
            return true;
        }
    }
    return false;
}

void dfs2(int v) {
    used[v] = true;
    for (int i = 0; i < n; ++i) {
        if (can[v][i]) {
            if (!used_right[i] && !used[res_right[i]]) {
                dfs2(res_right[i]);
                used_right[i] = true;
                used_left[res_right[i]] = false;
            }
        }
    }
}

inline void init() {
    sz = 1;
    next[0][0] = next[0][1] = -1;
    num[0] = -1;
}

inline void aho() {
    int l = 0, r = 1;
    q[0] = 0;
    while (l < r) {
        int v = q[l++];
        if (v == 0 || pv[v] == 0) {
            link[v] = 0;
        } else {
            link[v] = go[link[pv[v]]][pc[v]];
        }
        if (num[v] != -1) {
            pv[v] = v;
        } else {
            pv[v] = pv[link[v]];
        }
        for (int i = 0; i < 2; ++i) {
            if (next[v][i] != -1) {
                go[v][i] = next[v][i];
                q[r++] = next[v][i];
            } else {
                if (v == 0) {
                    go[v][i] = 0;
                } else {
                    go[v][i] = go[link[v]][i];
                }
            }
        }
    }
}

int main() {
    cerr << (sizeof(link) + sizeof(pv) + sizeof(pc) + sizeof(next) + sizeof(go)) / 1024 / 1024 << endl;
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n;
    init();
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        len[i] = strlen(buf);
        s[i] = new char[len[i] + 1];
        strcpy(s[i], buf);
        int cur = 0;
        for (int j = 0; j < len[i]; ++j) {
            int c = buf[j] - 'a';
            if (next[cur][c] == -1) {
                next[sz][0] = next[sz][1] = -1;
                pv[sz] = cur;
                pc[sz] = c;
                num[sz] = -1;
                next[cur][c] = sz++;
            }
            cur = next[cur][c];
        }
        num[cur] = i;
        ver[i] = cur;
    }
    aho();
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < len[i]; ++j) {
            cur = next[cur][s[i][j] - 'a'];
            int v = pv[cur];
            if (v > 0) {
                if (num[v] == i) {
                    v = pv[link[v]];
                }
                if (v > 0) {
                    can[i][num[v]] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int z = 0; z < n; ++z) {
                can[j][z] |= (can[j][i] && can[i][z]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        res_left[i] = res_right[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            used[j] = false;
        }
        dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        if (res_right[i] != -1) {
            used_left[res_right[i]] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        used[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        if (res_left[i] == -1) {
            dfs2(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!used_left[i] && !used_right[i]) {
            ans.pb(i);
        }
    }
    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); ++i) {
        printf("%d ", ans[i] + 1);
    }
    puts("");
    return 0;
}