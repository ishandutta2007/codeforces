#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <complex>

using namespace std;

#define pb push_back
#define mp make_pair
#define sz(s) int((s).size())
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = int(1e9);
const double eps = 1e-9;
const double pi = 4 * atan(double(1));
const int N = 2020;

struct node {
  
    int l, r, ls, rs, p, ans;
    short up[N], down[N];
    
};

struct queue {
  
    struct st {
      
        int val1, val2, min_val1, min_val2;
        
    };
    
    int k1, k2;
    st s1[N], s2[N];
    
    inline void init() {
        k1 = k2 = 0;
        s1[0].min_val1 = s1[0].min_val2 = inf;
        s2[0].min_val1 = s2[0].min_val2 = inf;
    }
    
    inline void add(int val1, int val2) {
        s2[++k2].val1 = val1;
        s2[k2].val2 = val2;
        s2[k2].min_val1 = min(s2[k2 - 1].min_val1, val1);
        s2[k2].min_val2 = min(s2[k2 - 1].min_val2, val2);
    }
    
    inline void del() {
        if (k1 == 0) {
            while (k2 > 0) {
                s1[++k1].val1 = s2[k2].val1;
                s1[k1].val2 = s2[k2].val2;
                s1[k1].min_val1 = min(s1[k1 - 1].min_val1, s2[k2].val1);
                s1[k1].min_val2 = min(s1[k1 - 1].min_val2, s2[k2].val2);
                --k2;
            }
        }
        assert(k1 > 0);
        --k1;
    }
    
    inline int get_min1() {
        return min(s1[k1].min_val1, s2[k2].min_val1);
    }
    
    inline int get_min2() {
        return min(s1[k1].min_val2, s2[k2].min_val2);
    }
    
};

int ptr = 0, m;
char a[N][N];
short up[N][N], down[N][N];
node ver[4 * N];
queue q;

inline void calc(int v) {
    if (ver[v].l == ver[v].r) {
        ver[v].ans = 0;
        for (int i = 0; i < m; ++i) {
            if (a[ver[v].l][i] == '.') {
                ver[v].ans = 1;
                break;
            }
        }
        return;
    }
    ver[v].ans = max(ver[ver[v].ls].ans, ver[ver[v].rs].ans);
    q.init();
    for (int i = 0; i < ver[v].ans; ++i) {
        q.add(ver[v].up[i], ver[v].down[i]);
    }
    for (int i = 0; i + ver[v].ans - 1 < m; ++i) {
        if (q.get_min1() + q.get_min2() >= ver[v].ans) {
            for (;;) {
                int j = i + ver[v].ans;
                if (j >= m) {
                    break;
                }
                if (min(q.get_min1(), int(ver[v].up[j])) + min(q.get_min2(), int(ver[v].down[j])) >= ver[v].ans + 1) {
                    q.add(ver[v].up[j], ver[v].down[j]);
                    ++ver[v].ans;
                } else {
                    break;
                }
            }
        }
        if (ver[v].ans > 0) {
            q.del();
            if (i + ver[v].ans < m) {
                q.add(ver[v].up[i + ver[v].ans], ver[v].down[i + ver[v].ans]);
            }
        }
    }
}

inline int build(int l, int r, int p) {
    int res = ptr++;
    ver[res].l = l;
    ver[res].r = r;
    ver[res].p = p;
    if (l < r) {
        int mid = (l + r) / 2;
        ver[res].ls = build(l, mid, res);
        ver[res].rs = build(mid + 1, r, res);
        for (int i = 0; i < m; ++i) {
            ver[res].up[i] = min(mid - up[mid][i], mid - l + 1);
            ver[res].down[i] = min(down[mid + 1][i] - (mid + 1), r - mid);
        }
    } else {
        ver[res].ls = ver[res].rs = -1;
    }
    calc(res);
    return res;
}

void update(int v, int x, int y) {
    if (ver[v].l == ver[v].r) {
        a[ver[v].l][y] = 'X';
        calc(v);
        return;
    }
    int mid = (ver[v].l + ver[v].r) / 2;
    if (x <= mid) {
        update(ver[v].ls, x, y);
        ver[v].up[y] = min(ver[v].up[y], short(mid - x));
    } else {
        update(ver[v].rs, x, y);
        ver[v].down[y] = min(ver[v].down[y], short(x - (mid + 1)));
    }
    calc(v);
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cerr << (sizeof(a) + sizeof(up) + sizeof(down) + sizeof(ver) + sizeof(q)) / 1024 / 1024 << endl;
    int n, k;
    scanf("%d %d %d", &n, &m, &k);
    gets(a[0]);
    for (int i = 0; i < n; ++i) {
        gets(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') {
                up[i][j] = i;
            } else {
                up[i][j] = (i > 0 ? up[i - 1][j] : -1);
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') {
                down[i][j] = i;
            } else {
                down[i][j] = (i + 1 < n ? down[i + 1][j] : n);
            }
        }
    }
    int root = build(0, n - 1, -1);
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        update(root, x, y);
        printf("%d\n", ver[root].ans);
    }
    return 0;
}