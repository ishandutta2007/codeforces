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
const int N = 1<<22|5;

int k, n, q, tot, cnt, lg2[N], pos2[N], pos[N], pos3[N];
char c[N], s[N];
struct Node {
	int l, r, dfn, mxdfn, w;
	Node(int a=0, int b=0, int c=0, int d=0, int e=0) : l(a), r(b), dfn(c), mxdfn(d), w(e) {}
	~Node() {}
}t[N];
#define lc(u) (u<<1)
#define rc(u) (u<<1|1)
void pushup(int u) {
	if(!t[u].dfn) return;
	char c = s[t[u].dfn];
	if(c == '0') t[u].w = t[lc(u)].w;
	else if(c == '1') t[u].w = t[rc(u)].w;
	else t[u].w = t[lc(u)].w + t[rc(u)].w;
}
void build(int u, int l, int r) {
	t[u].l = l; t[u].r = r;
	if(l == r) {t[u].w = 1; return;}
	t[u].dfn = ++tot;
	pos[tot] = pos2[u];
//	pos[(1<<(k-lg2[r-l+1]))+(r/(r-l+1))-1] = t[u].dfn;
//	fprintf(stderr, "%d %d %d %d\n", r-l+1, lg2[r-l+1], k-lg2[r-l+1], (1<<(k-lg2[r-l+1]))+(r/(r-l+1))-1);
	int mid = (l + r) >> 1;
	build(lc(u), l, mid);
	build(rc(u), mid+1, r);
}
void build2(int u, int l, int r) {
	if(l == r) return;
	int mid = (l + r) >> 1;
	build2(lc(u), l, mid);
	build2(rc(u), mid+1, r);
	pushup(u);
}
void modify(int u, int l, int r, int pos) {
//	fprintf(stderr, "MODIFY %d : [%d, %d] -> DFN = %d; EXPECTED POS = %d\n", u, l, r, t[u].dfn, pos);
	if(t[u].dfn == pos) {pushup(u); return;}
	int mid = (l + r) >> 1;
	if(t[rc(u)].dfn > pos) modify(lc(u), l, mid, pos);
	else modify(rc(u), mid+1, r, pos);
	pushup(u);
}
void print(int u, int l, int r) {
	fprintf(stderr, "NODE %d : [%d, %d] -> DFN = %d; W = %d\n", u, l, r, t[u].dfn, t[u].w);
	if(l == r) return;
	int mid = (l + r) >> 1;
	print(lc(u), l, mid);
	print(rc(u), mid+1, r);
}

int main() {
	lg2[0] = -1;
	rep(i, 1, N-1) lg2[i] = lg2[i>>1] + 1;
	scanf("%d%s%d", &k, c+1, &q);
	n = 1 << k;
	rep(i, 1, k) {
		for(int l=1,r=(1<<i);r<=n;l+=(1<<i),r+=(1<<i)) {
//			fprintf(stderr, "[%d, %d] -> %d\n", l, r, cnt+1);
			pos2[(1<<(k-lg2[r-l+1]))+(r/(r-l+1))-1] = ++cnt;
		}
	}
	build(1, 1, n);
	rep(i, 1, n-1) pos3[pos[i]] = i;
	rep(i, 1, n-1) s[i] = c[pos[i]];
	build2(1, 1, n);
//	fprintf(stderr, "%s\n", s+1);
//	rep(i, 1, n-1) fprintf(stderr, "%d\n", pos[i]);
//	exit(0);
	while(q--) {
		int p; char c[2];
		scanf("%d%s", &p, c);
		s[pos3[p]] = c[0];
//		fprintf(stderr, "%s\n", s+1);
		modify(1, 1, n, pos3[p]);
		printf("%d\n", t[1].w);
//		print(1, 1, n);
	}
	return 0;
}