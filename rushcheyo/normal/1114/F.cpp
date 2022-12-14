#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//  or or

const int N=400005,P=1000000007;
int n,q,a[N],pro[N<<2],mul[N<<2],p[305],inv[305];
bool np[305];
ll mask[305],orsum[N<<2],ortag[N<<2];

int power(int a,int x){
	int ans=1;
	for(;x;x>>=1,a=1ll*a*a%P)
		if(x&1)ans=1ll*ans*a%P;
	return ans;
}

void pushup(int u){
	pro[u]=1ll*pro[u<<1]*pro[u<<1|1]%P;
	orsum[u]=orsum[u<<1]|orsum[u<<1|1];
}
void upd(int x,int l,int r,int y,ll z){
	pro[x]=1ll*pro[x]*power(y,r-l+1)%P;
	mul[x]=1ll*mul[x]*y%P;
	orsum[x]|=z;
	ortag[x]|=z;
}
void pushdown(int u,int l,int r,int mid){
	if(mul[u]!=1||ortag[u]){
		upd(u<<1,l,mid,mul[u],ortag[u]);upd(u<<1|1,mid+1,r,mul[u],ortag[u]);mul[u]=1;ortag[u]=0;
	}
}
void build(int u,int l,int r){
	mul[u]=1;ortag[u]=0;
	if(l==r){pro[u]=a[l];orsum[u]=mask[a[l]];return;}
	int m=l+r>>1;build(u<<1,l,m);build(u<<1|1,m+1,r);
	pushup(u);
}
void update(int u,int l,int r,int ql,int qr,int x,ll y){
	if(l>=ql&&r<=qr){upd(u,l,r,x,y);return;}
	int mid=l+r>>1;
	pushdown(u,l,r,mid);
	if(ql<=mid)update(u<<1,l,mid,ql,qr,x,y);
	if(qr>mid)update(u<<1|1,mid+1,r,ql,qr,x,y);
	pushup(u);
}
pair<int,ll> gao(const pair<int,ll> &a,const pair<int,ll> &b){
	return make_pair(1ll*a.first*b.first%P,a.second|b.second);
}
pair<int,ll> query(int u,int l,int r,int ql,int qr){
	if(l>=ql&&r<=qr)return make_pair(pro[u],orsum[u]);
	int mid=l+r>>1;
	pushdown(u,l,r,mid);
	if(qr<=mid)return query(u<<1,l,mid,ql,qr);
	if(ql>mid)return query(u<<1|1,mid+1,r,ql,qr);
	return gao(query(u<<1,l,mid,ql,qr),query(u<<1|1,mid+1,r,ql,qr));
}

int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=2;i<=300;i++){
		if(!np[i])p[++p[0]]=i;
		for(int j=1;j<=p[0]&&p[j]*i<=300;j++){
			np[p[j]*i]=true;
			if(i%p[j]==0)break;
		}
	}
	for(int i=2;i<=300;i++)
		for(int j=1;j<=p[0];j++)
			if(i%p[j]==0)mask[i]|=1ll<<j-1;
	inv[1]=1;
	for(int i=2;i<=300;i++)inv[i]=1ll*(P-P/i)*inv[P%i]%P;
	build(1,1,n);
	while(q--){
		char op[15];
		scanf("%s",op);
		if(op[0]=='M'){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			update(1,1,n,l,r,x,mask[x]);
		}else{
			int l,r;
			scanf("%d%d",&l,&r);
			pair<int,ll> ret=query(1,1,n,l,r);
			int ans=ret.first;
			for(int j=0;j<p[0];j++)if(ret.second>>j&1)ans=ans*(p[j+1]-1ll)%P*inv[p[j+1]]%P;
			printf("%d\n",ans);
		}
	}
	return 0;
}