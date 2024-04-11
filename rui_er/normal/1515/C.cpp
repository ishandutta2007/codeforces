//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 1e5+5, inf = 0x3f3f3f3f;

int n, m, k, pos[N];
struct Node {
	int a, id;
	Node(int a=0, int b=0) : a(a), id(b) {}
	friend bool operator < (const Node &a, const Node &b) {return a.a > b.a;}
}a[N];
priority_queue<Node> h;

int main() {
	mulT0 {
		scanf("%d%d%d", &n, &m, &k);
		rep(i, 1, n) scanf("%d", &a[i].a), a[i].id = i;
		while(!h.empty()) h.pop();
		sort(a+1, a+1+n);
		rep(i, 1, m) h.push(Node(a[i].a, i)), pos[a[i].id] = i;
		rep(i, m+1, n) {
			Node now = h.top(); h.pop();
			now.a += a[i].a; pos[a[i].id] = now.id;
			h.push(now);
		}
		int mi = inf, ma = -inf;
		rep(i, 1, m) {
			int now = h.top().a; h.pop();
			mi = min(mi, now); ma = max(ma, now);
		}
		if(ma - mi <= k) {
			puts("YES");
			rep(i, 1, n) printf("%d%c", pos[i], " \n"[i==n]);
		}
		else puts("NO");
	}
	return 0;
}