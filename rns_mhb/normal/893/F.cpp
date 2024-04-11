#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 100005
#define f1(i, a, b) for (int i = a; i <= b; i ++)
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define K 18

vector <int> v[N], w[N];
vector <int> :: iterator it;
void chkmin(int &a, int b) {if (a > b) a = b;}

int n, rt, a[N], st[N], fs[N], G, dp[N];
int rg[N][K], lg[N][K], b[N];
int mn[N][K][K];
const int inf = 0x3f3f3f3f;

void dfs(int k, int pa = 0) {
    dp[k] = dp[pa] + 1;
    st[k] = ++ G;
    w[dp[k]].pb(k);
    for (auto x : v[k]) {
		if (x == pa) continue;
        dfs(x, k);
    }
    fs[k] = ++ G;
    return;
}

bool cmp1(int x, int y) {
    return st[x] < st[y];
}
bool cmp2(int x, int y) {
	return fs[x] < fs[y];
}

int find_min(int l, int r, int k) {
	if (!l || !r) return inf;
    int ll = b[l], rr = b[r];
    if (ll > rr) return inf;
    int m = 31 - __builtin_clz(rr - ll + 1);
    r = w[dp[l]][rr-(1<<m)+1];
    return min(mn[l][k][m], mn[r][k][m]);
}

void build() {
    for (int i = n; i; i --) {
        if (w[i].empty()) continue;
        int sz = w[i].size();
        for (auto x : w[i]) mn[x][0][0] = a[x];
        f0(j, 1, K) {
			if (sz < (1 << j)) break;
            for (auto x : w[i]) {
                if (b[x] + (1<<j) > sz) break;
                mn[x][0][j] = min(mn[x][0][j-1], mn[w[i][b[x]+(1<<j-1)]][0][j-1]);
            }
        }

        for (auto x : w[i]) {
            f0(j, 1, K) {
                f0(jj, 0, K) {
                    if (b[x] + (1<<jj) > sz) break;
                    mn[x][j][jj] = mn[x][j-1][jj];
                    chkmin(mn[x][j][jj], find_min(lg[x][j], rg[w[i][b[x]+(1<<jj)-1]][j], j-1));
                }
            }
        }
    }
    return;
}

int query(int x, int y) {
    y ++;
    int res = inf, l = x, r = x;
    for (int i = K - 1; i >= 0; i --) {
		if (y >= (1 << i)) {
            chkmin(res, find_min(l, r, i));
            l = lg[l][i+1], r = rg[r][i+1];
            if (!l || !r) return res;
            y -= (1 << i);
		}
    }
    return res;
}

int main() {
    scanf("%d %d", &n, &rt);
    f1(i, 1, n) scanf("%d", &a[i]);
    int x, y;
    f0(i, 1, n) {
		scanf("%d %d", &x, &y);
		v[x].pb(y); v[y].pb(x);
    }
    memset(mn, 0x3f, sizeof mn);
    dfs(rt, 0);
    st[0] = n+1;
    f1(i, 0, n) {
    	lg[i][0] = i; rg[i][0] = i;
        f0(j, 1, K) {
			x = dp[i] + (1 << j - 1);
			if (x > n) break;
            if (w[x].empty()) break;
            it = lower_bound(w[x].begin(), w[x].end(), i, cmp1);
            if (it != w[x].end()) lg[i][j] = *it;
            it = lower_bound(w[x].begin(), w[x].end(), i, cmp2);
            if (it != w[x].begin()) -- it, rg[i][j] = *it;
        }
    }
    f0(i, 0, n) {
        f0(j, 0, w[i].size()) {
            b[w[i][j]] = j;
        }
    }
    build();
    int q, lst = 0;
    for (scanf("%d", &q); q --; ) {
		scanf("%d %d", &x, &y);
		x = (x + lst) % n + 1;
		y = (y + lst) % n;
        lst = query(x, y);
        printf("%d\n", lst);
    }
	return 0;
}