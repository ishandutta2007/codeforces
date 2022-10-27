#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int n; char s[N];
int pre[N];
struct Nod {
	LL sum, mx, lz;
	Nod operator+(const Nod&o)const{
		Nod ans;
		ans.sum=sum+o.sum;
		ans.lz=0;
		ans.mx=max(mx,o.mx);
		return ans;
	}
} nod[N<<2];
void pushdown(int rt,int l,int r){
	int mid=(l+r)>>1;
	if(nod[rt].lz > 0){
		nod[rt<<1].mx += nod[rt].lz;
		nod[rt<<1].sum += nod[rt].lz * (mid-l+1);
		nod[rt<<1].lz += nod[rt].lz;

		nod[rt<<1|1].mx += nod[rt].lz;
		nod[rt<<1|1].sum += nod[rt].lz * (r-mid);
		nod[rt<<1|1].lz += nod[rt].lz;

		nod[rt].lz=0;
	}
}
void update(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R) {
		//printf("l=%d,r=%d,rt = %d\n", l,r,rt);
		//printf("[%d, %d], rt = %d\n", l,r,rt);
		nod[rt].sum += r-l+1; nod[rt].lz ++; nod[rt].mx ++; return;
	}
	int mid=(l+r)>>1; pushdown(rt,l,r);
	if(L<=mid) update(l,mid,rt<<1,L,R);
	if(R >mid) update(mid+1,r,rt<<1|1,L,R);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
Nod query(int l,int r,int rt,int L,int R){
	if(L<=l&&r<=R){
		//printf("Q [%d,%d], rt=%d\n", l,r,rt);
		return nod[rt];
	}
	int mid=(l+r)>>1; pushdown(rt,l,r);
	if(L>mid) return query(mid+1,r,rt<<1|1,L,R);
	if(R<=mid) return query(l,mid,rt<<1,L,R);
	return query(l,mid,rt<<1,L,R) + query(mid+1,r,rt<<1|1,L,R);
}
int findpos(int l,int r,int rt,int x){
	if(l==r) return l;
	int mid=(l+r)>>1;pushdown(rt,l,r);
	if(nod[rt<<1|1].mx >= x) return findpos(mid+1,r,rt<<1|1,x);
	return findpos(l,mid,rt<<1,x);
}
void build(int l,int r,int rt){
	if(l==r){
		nod[rt].lz=nod[rt].sum=nod[rt].mx=0; return;
	}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	nod[rt]=nod[rt<<1]+nod[rt<<1|1];
}
int main() {
	scanf("%d%s",&n,s+1);
	build(1,n,1);
	LL ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			if(s[i-1]!='1') pre[i]=1;
			else pre[i]=pre[i-1]+1;
			int lef;

			
			if(query(1,n,1,1,i).mx < pre[i]) lef = 1;
			else lef=findpos(1,n,1,pre[i])+1;
		
			//printf("upd [%d, %d]\n", lef,i);
			update(1,n,1,lef,i);
			
			//printf("i=%d,lef=%d\n", i,lef);
			//for(int j=1;j<=n;j++)
			//printf("%lld ", query(1,n,1,j,j).mx);
			
			//printf("\n");
			//return 0;
			
		}
		ans+=query(1,n,1,1,i).sum;
	}
	printf("%lld\n", ans);
}