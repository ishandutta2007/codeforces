#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
template <class T> void chkmin(T &a, T b) {if (a > b) a = b;}

const int inf = 0x3f3f3f3f;

#define N 1000005

int n, q, a[N] = {inf};
bool c[N];
int p[N];
vector <int> v[N];

void dfs(int k, int pa) {
    p[k] = pa;
    a[k] = min(k, a[pa]);
    f0(i, 0, v[k].size()) {
		if (v[k][i] == pa) continue;
        dfs(v[k][i], k);
	}
    return;
}

int main() {
    scanf("%d %d", &n, &q);
	int x, y;
    f0(i, 1, n) {
        scanf("%d %d", &x, &y);
        v[x].pb(y);
        v[y].pb(x);
    }
    scanf("%d %d", &x, &y);
    int lst = 0, ans = inf;
    y = (y + lst) % n + 1;
    dfs(y, 0); c[y] = 1;
    f0(i, 1, q) {
		scanf("%d %d", &x, &y);
        y = (y + lst) % n + 1;
        if (x == 1) {
            while (!c[y]) {
				c[y] = 1;
				chkmin(ans, y);
				y = p[y];
            }
        }
        else {
			lst = min(ans, a[y]);
			printf("%d\n", lst);
        }
    }
	return 0;
}