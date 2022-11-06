//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int T, n, fa[N];
char s[N], t[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void init(int x) {rep(i, 1, x) fa[i] = i;}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
bool merge(int x, int y) {
	int u = find(x), v = find(y);
	if(u == v) return 0;
	fa[u] = v;
	return 1;
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%s%s", &n, s+1, t+1);
		init(26);
		int ans = 0;
		rep(i, 1, n) {
			if(s[i] > t[i]) {
				puts("-1");
				goto noSolution;
			}
			ans += merge(s[i]-'a'+1, t[i]-'a'+1);
		}
		printf("%d\n", ans);
		noSolution: ;
	}
	return 0;
}