#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
class Seg{
	public:
		LL minval, val;
		Seg(LL _val=0) { val=_val; }
} seg[800005];
void pull(int x) {
	seg[x].minval = min(seg[x*2].minval, seg[x*2+1].minval) + seg[x].val;
}
int a[200005];
void init(int x, int L, int R) {
	if(L==R) {seg[x].minval=seg[x].val=a[L];return;}
	seg[x].val=0;
	int M=(L+R)/2;
	init(x*2, L, M);
	init(x*2+1, M+1, R);
	pull(x);
}

void add(int x, int L, int R, int lf, int rg, int v) {
	if(lf<=L && rg>=R) {seg[x].val += v; seg[x].minval += v; return; }
	int M=(L+R)/2;
	if(lf<=M) add(x*2, L, M, lf, rg, v);
	if(rg>M) add(x*2+1, M+1, R, lf, rg, v);
	pull(x);
}

LL ask(int x, int L, int R, int lf, int rg) {
	if(lf<=L && rg>=R) return seg[x].minval;
	int M=(L+R)/2;
	LL ret=1LL<<60;
	if(lf<=M) ret=min(ret, ask(x*2, L, M, lf, rg));
	if(rg>M) ret=min(ret, ask(x*2+1, M+1, R, lf, rg));
	ret += seg[x].val;
	return ret;
}

char s[1000];
int main(void) {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	init(1, 0, n-1);
	int m;
	scanf("%d", &m);
	gets(s);
	while(m--) {
		gets(s);
		int lf, rg, v;
		if(sscanf(s, "%d%d%d", &lf, &rg, &v)==3) {
			if(rg < lf) {
				add(1, 0, n-1, lf, n-1, v);
				add(1, 0, n-1, 0, rg, v);
			} else {
				add(1, 0, n-1, lf, rg, v);
			}
		} else {
			sscanf(s, "%d%d", &lf, &rg);
			LL ans;
			if(rg < lf) {
				ans = ask(1, 0, n-1, lf, n-1);
				ans = min(ans, ask(1, 0, n-1, 0, rg));
			} else {
				ans = ask(1, 0, n-1, lf, rg);
			}
			printf("%I64d\n", ans);
		}
	}
	return 0;
}