#include<cstdio>
#include<iostream>
#include<utility>
using namespace std;
const int o=4e5+10;
pair<int,int> merge(pair<int,int> A,pair<int,int> B){return make_pair(min(A.first,B.first),max(A.second,B.second));}
int n,q,a[o],nxt[o/4][33];long long ans;pair<int,int> t[33][o/4],v[33][o];
pair<int,int> query(int k,int id,int ql,int qr,int l=1,int r=n-1){
	if(ql<=l&&r<=qr) return v[k][id];
	int md=l+r>>1;
	if(qr<=md) return query(k,id<<1,ql,qr,l,md);
	if(md<ql) return query(k,(id<<1)|1,ql,qr,md+1,r);
	return merge(query(k,id<<1,ql,qr,l,md),query(k,(id<<1)|1,ql,qr,md+1,r));
}
pair<int,int> jmp(int l,int r,int k){if(l==r) return make_pair(nxt[l][k],nxt[r][k]);return query(k,1,l,r-1);}
void build(int id,int l,int r,int k){
	if(l==r){
		if(!k) v[k][id]=t[k][l]=make_pair(min(a[l],a[l+1]),max(a[l],a[l+1]));
		else v[k][id]=t[k][l]=jmp(t[k-1][l].first,t[k-1][l].second,k-1);
		return;
	}
	int md=l+r>>1;
	build(id<<1,l,md,k);build((id<<1)|1,md+1,r,k);
	v[k][id]=merge(v[k][id<<1],v[k][(id<<1)|1]);
}
int main(){
	scanf("%d%d",&n,&q);
	if(n==1){for(;q--;printf("0\n"));return 0;}
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),nxt[i][0]=a[i];
	for(int i=1;i<33;++i) for(int j=1;j<=n;++j) nxt[j][i]=nxt[nxt[j][i-1]][i-1];
	for(int i=0;i<33;++i) build(1,1,n-1,i);
	for(pair<int,int> pr,z;q--;printf("%lld\n",ans),ans=0){
		scanf("%d%d",&pr.first,&pr.second);
		if(pr==make_pair(1,n)) continue;
		for(int i=32;i+1;--i) if((z=jmp(pr.first,pr.second,i))!=make_pair(1,n)) pr=z,ans+=(1ll<<i);
		if(ans>n*(n+1ll)/2) ans=-1;
		else ++ans;
	}
	return 0;
}