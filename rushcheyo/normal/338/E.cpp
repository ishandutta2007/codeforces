#include<cstdio>
const int N=300005,M=15000000,v=1000000000,lim=2000000000;
int n,m,h,tot,rt,a[N],b[N],ls[M],rs[M],mi[M],tag[M];
void add(int u,int x){mi[u]+=x;tag[u]+=x;}
void update(int &u,int l,int r,int ql,int qr,int x){
	if(!u)u=++tot;
	if(l>=ql&&r<=qr){add(u,x);return;}
	if(tag[u]){if(!ls[u])ls[u]=++tot;add(ls[u],tag[u]);if(!rs[u])rs[u]=++tot;add(rs[u],tag[u]);tag[u]=0;}
	int mid=l+(r-l)/2;
	if(ql<=mid)update(ls[u],l,mid,ql,qr,x);
	if(qr>mid)update(rs[u],mid+1,r,ql,qr,x);
	mi[u]=mi[ls[u]];
	if(mi[rs[u]]<mi[u])mi[u]=mi[rs[u]];
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=m;i++)scanf("%d",b+i),update(rt,0,lim,b[i]+v,lim,-1);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		update(rt,0,lim,h-a[i]+v,lim,1);
		if(i<m)continue;
		if(mi[rt]>=0)ans++;
		update(rt,0,lim,h-a[i-m+1]+v,lim,-1);
	}
	printf("%d\n",ans);
}