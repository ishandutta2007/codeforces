#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1<<19;
int n,q; LL a[N];
int S;
struct Nod {
	LL sum; int dep;
} nod[N<<2];
void build(int l,int r,int rt,int d){
	nod[rt].sum = 0; nod[rt].dep = d;
	if(l==r){
		nod[rt].sum = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,rt<<1, d-1);
	build(mid+1,r,rt<<1|1, d-1);
	nod[rt].sum = nod[rt<<1].sum + nod[rt<<1|1].sum;
}

void update(int l,int r,int rt,int pos,int x) {
	if (l==r) {
		nod[rt].sum = x; return;
	}
	int mid = (l+r)>>1;
	int lson = rt<<1;
	int rson = rt<<1|1;
	if (S >> nod[lson].dep & 1) swap(lson, rson);
	if(pos<=mid) update(l,mid,lson,pos,x);
	else update(mid+1,r,rson,pos,x);
	nod[rt].sum = nod[lson].sum + nod[rson].sum;
}
LL query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R) {
		//printf("[%d,%d] %d\n", l,r,nod[rt].sum);
		return nod[rt].sum;
	}
	int mid = (l+r)>>1;
	int lson = rt<<1;
	int rson = rt<<1|1;
	if (S >> nod[lson].dep & 1) swap(lson, rson);
	LL ans=0;
	//printf("rt = %d, lson = %d, rson = %d\n", rt, nod[rt].lson, nod[rt].rson);
	if(L<=mid) ans+=query(l,mid,lson,L,R);
	if(R >mid) ans+=query(mid+1,r,rson,L,R);
	return ans;
}
int main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=1<<n;i++){
		scanf("%lld",&a[i]);
	}
	build(1,1<<n,1,n);
	while(q--){
		int op; int x,k,l,r;
		scanf("%d",&op);
		if(op==1) {
			scanf("%d%d",&x,&k);
			update(1,1<<n,1,x,k);
		}
		if(op==2){
			scanf("%d",&k);
			int mask=0;
			for(int i=0;i<=k-1;i++) mask|=1<<i;
			S ^= mask;
		}
		if(op==3){
			scanf("%d",&k);
			S ^= 1<<k;
		}
		if(op==4){
			scanf("%d%d",&l,&r);
			printf("%lld\n", query(1,1<<n,1,l,r));
		}
		// for(int i=1;i<=1<<n;i++) query(1,1<<n,1,i,i);
	}
}