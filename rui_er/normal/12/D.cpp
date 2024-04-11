//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1.5e6+5;

int n, buc[N], tot, ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Node {
	int a, b, c, w, f;
}a[N], b[N];
struct BIT {
	int c[N];
	BIT() {memset(c, 0, sizeof(c));}
	~BIT() {}
	int lowbit(int x) {return x & (-x);}
	void add(int x, int k) {
		for(;x<N;x+=lowbit(x)) c[x] += k;
	}
	int ask(int x) {
		int k = 0;
		for(;x;x-=lowbit(x)) k += c[x];
		return k;
	}
}bit;
struct CDQ {
	void merge(int L, int M, int R) {
		int l = L, r = M + 1, now = l;
		while(l <= M && r <= R) {
			if(a[l].b > a[r].b) {
				bit.add(a[l].c, 1);
				b[now++] = a[l++];
			}
			else {
				a[r].f += bit.ask(N-1) - bit.ask(a[r].c);
				b[now++] = a[r++];
			}
		}
		while(l <= M) {
			bit.add(a[l].c, 1);
			b[now++] = a[l++];
		}
		while(r <= R) {
			a[r].f += bit.ask(N-1) - bit.ask(a[r].c);
			b[now++] = a[r++];
		}
		rep(i, L, M) bit.add(a[i].c, -1);
		rep(i, L, R) a[i] = b[i];
	}
	void divide(int L, int R) {
		if(L == R) return;
		int M = (L + R) >> 1;
		divide(L, M); divide(M+1, R);
		merge(L, M, R);
	} 
}cdq;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) a[i].w = 1, a[i].f = 0;
	rep(i, 1, n) scanf("%d", &a[i].a);
	rep(i, 1, n) scanf("%d", &a[i].b);
	rep(i, 1, n) {
		scanf("%d", &a[i].c);
		buc[++tot] = a[i].c;
	}
	sort(buc+1, buc+1+tot);
	tot = unique(buc+1, buc+1+tot) - buc - 1;
	rep(i, 1, n) a[i].c = lower_bound(buc+1, buc+1+tot, a[i].c) - buc;
	sort(a+1, a+1+n, [](const Node& a, const Node& b) {
		if(a.a != b.a) return a.a > b.a;
		if(a.c != b.c) return a.c < b.c;
		return a.b > b.b;
	});
	tot = 1;
	rep(i, 2, n) {
		if(a[i].a == a[tot].a && a[i].b == a[tot].b && a[i].c == a[tot].c) ++a[tot].w;
		else a[++tot] = a[i];
	}
	cdq.divide(1, tot);
	rep(i, 1, tot) ans += (!!a[i].f) * a[i].w;
	printf("%d\n", ans);
	return 0;
}