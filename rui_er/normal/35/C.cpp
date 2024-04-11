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
const int N = 2e3+5;

int n, m, k, x, y, vis[N][N];
struct Dot {
	int x, y;
	Dot(int a=0, int b=0) : x(a), y(b) {}
	~Dot() {}
	friend Dot operator + (const Dot &a, const Dot &b) {return Dot(a.x+b.x, a.y+b.y);}
	bool ok() {return x >= 1 && x <= n && y >= 1 && y <= m;}
	bool at() {return vis[x][y];}
	bool set() {bool res = at(); vis[x][y] = 1; return res;}
}a[4] = {Dot(0, 1), Dot(1, 0), Dot(0, -1), Dot(-1, 0)}, ans;
queue<Dot> q;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	while(k--) {
		scanf("%d%d", &x, &y);
		q.push(Dot(x, y));
		Dot(x, y).set();
	}
	while(!q.empty()) {
		Dot u = q.front(); q.pop();
		ans = u;
		rep(i, 0, 3) {
			Dot v = u + a[i];
			if(v.ok() && !v.set()) q.push(v);
		}
	}
	printf("%d %d\n", ans.x, ans.y);
	return 0;
}