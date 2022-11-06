//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 1e4+5;

int n, fa[N], s;
void init() {rep(i, 1, n) fa[i] = i;}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
bool merge(int x, int y) {int u = find(x), v = find(y); if(u != v) fa[u] = v; return u != v;}

int main() {
	scanf("%d", &n); s = n; init();
	rep(i, 1, n) {
		int j; scanf("%d", &j);
		s -= merge(i, j);
	}
	printf("%d\n", s);
	return 0;
}