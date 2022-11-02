#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f0(i, a, b) for (int i = a; i < b; i ++)
#define f1(i, a, b) for (int i = a; i <= b; i ++)
typedef vector <int> vi;

#define N 200005
#define M 800

int n, m, c[N], g[M];

vi w[N], v[M];

int comb(int x, int y) {
    if (v[x].size() > v[y].size()) swap(x, y);
    for (auto z : v[x]) v[y].pb(z), c[z] = y;
    v[x].clear();
    return y;
}

int main() {
	scanf("%d %d", &n, &m);
	int x, y;
	f1(i, 1, m) {
		scanf("%d %d", &x, &y);
		if (x < y) swap(x, y);
        w[x].pb(y);
	}
    int sz = 0;
    f1(i, 1, n) {
		memset(g, 0, sizeof g);
        for (auto x : w[i]) g[c[x]] ++;
        int p;
        f0(i, 0, M) if (v[i].empty()) {p = i; break;}
        v[p].pb(i); c[i] = p;
        f0(i, 0, M) if (v[i].size() > g[i] && p != i) p = comb(i, p);
    }
    f0(i, 0, M) if (v[i].size() > 0) g[sz ++] = v[i].size();
    sort(g, g + sz);
    printf("%d\n", sz);
    f0(i, 0, sz) printf("%d ", g[i]);
	return 0;
}