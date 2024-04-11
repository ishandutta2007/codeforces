//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e3+5;

int n, m1, m2, fa[2][N];
vector<pair<int, int> > ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void init(int x) {rep(i, 1, x) fa[0][i] = fa[1][i] = i;}
int find(int r, int x) {return x == fa[r][x] ? x : fa[r][x] = find(r, fa[r][x]);}
void merge(int r, int x, int y) {
	int u = find(r, x), v = find(r, y);
	fa[r][u] = v;
}
bool check(int x, int y) {
	return find(0, x) != find(0, y) && find(1, x) != find(1, y);
}

int main() {
	scanf("%d%d%d", &n, &m1, &m2);
	init(n);
	rep(i, 1, m1) {
		int u, v;
		scanf("%d%d", &u, &v);
		merge(0, u, v);
	}
	rep(i, 1, m2) {
		int u, v;
		scanf("%d%d", &u, &v);
		merge(1, u, v);
	}
	rep(i, 1, n) rep(j, i+1, n) if(check(i, j)) {
		ans.push_back(make_pair(i, j));
		merge(0, i, j); merge(1, i, j);
	}
	int sz = ans.size();
	printf("%d\n", sz);
	rep(i, 0, sz-1) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}