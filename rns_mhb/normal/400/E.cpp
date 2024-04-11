#include <stdio.h>
#define N 100100
#define M 17

int a[N], n;
int b[17][N];
int fen1[17][N], fen2[17][N];
__int64 ans, cnt;
int pre, next;

void add1(int k, int pos, int v) {
	int i;
	for (i=pos; i<=n; i+=i&-i) fen1[k][i]+=v;
}

void add2(int k, int pos, int v) {
	int i;
	for (i=pos; i<=n; i+=i&-i) fen2[k][i]+=v;
}

int prev0(int k, int pos) {
	int lo=0, hi=pos, mid;
	while (hi-lo>1) {
		mid=hi-(hi&-hi);
		if (fen1[k][hi]==hi-mid) {
			if (!b[k][mid]) return mid;
			hi=mid-1;
		} else {
			if (!b[k][hi]) return hi;
			hi--, lo=mid;
		}
	}
	if (hi && b[k][hi]==0) return hi;
	return lo;
}

int next0(int k, int pos) {
	int lo=0, hi=pos, mid;
	while (hi-lo>1) {
		mid=hi-(hi&-hi);
		if (fen2[k][hi]==hi-mid) {
			if (!b[k][n+1-mid]) return mid;
			hi=mid-1;
		} else {
			if (!b[k][n+1-hi]) return hi;
			hi--, lo=mid;
		}
	}
	if (hi && b[k][n+1-hi]==0) return hi;
	return lo;
}

int main() {
	int q, i, j, tmp, k;
	int x, y, z, pre, bf;
//	freopen ("big.in", "r", stdin);
	scanf("%d %d", &n, &q);
	for (i=1; i<=n; i++) {
		scanf("%d", a+i);
		tmp=a[i];
		for (j=0; j<M; j++) {
			b[j][i]=tmp&1, tmp>>=1;
			if (b[j][i]) add1(j, i, 1), add2(j, n+1-i, 1);
		}
	}
	ans=0;
	for (j=0; j<M; j++) {
		cnt=pre=0;
		for (i=1; i<=n; i++) {
			if (b[j][i]) {
				if (i==1 || (i>1 && !b[j][i-1])) pre=i;
			} else {
				if (i>1 && b[j][i-1]) cnt+=1LL*(i-pre)*(i-pre+1)/2;
			}
		}
		if (b[j][n]) cnt+=1LL*(n-pre+1)*(n-pre+2)/2;
		ans+=cnt<<j;
	}
	while (q--) {
		scanf("%d %d", &i, &tmp);
		for (j=0; j<M; j++) {
			k=tmp&1, tmp>>=1;
			if (k==b[j][i]) continue;
			pre=prev0(j, i-1);
			next=n+1-next0(j, n-i);
			if (k==1) bf=1; else bf=-1;
			if (pre<i-1 && next>i+1) {
				x=i-pre-1, y=next-i-1, z=x+y+1;
				ans+=bf*(((1LL*z*(z+1)-1LL*x*(x+1)-1LL*y*(y+1))/2)<<j);
			} else if (pre<i-1) {
				x=i-pre-1, y=x+1;
				ans+=bf*(((1LL*y*(y+1)-1LL*x*(x+1))/2)<<j);
			} else if (next>i+1) {
				x=next-i-1, y=x+1;
				ans+=bf*(((1LL*y*(y+1)-1LL*x*(x+1))/2)<<j);
			} else ans+=bf*(1<<j);
			b[j][i]=k;
			if (k) add1(j, i, 1), add2(j, n+1-i, 1);
			else add1(j, i, -1), add2(j, n+1-i, -1);
		}
		printf("%I64d\n", ans);
	}
}