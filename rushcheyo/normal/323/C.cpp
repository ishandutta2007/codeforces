#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,m,tot,x,a[N],b[N],pos[N],rt[N],ls[N*21],rs[N*21],sz[N*21];
int f(int z){return (z-1+x)%n+1;}
void upd(int &x,int y,int l,int r,int p){
	x=++tot,ls[x]=ls[y],rs[x]=rs[y],sz[x]=sz[y]+1;
	if(l<r){
		int mid=l+r>>1;
		if(p<=mid)upd(ls[x],ls[y],l,mid,p);
		else upd(rs[x],rs[y],mid+1,r,p);
	}
}
int qry(int x,int l,int r,int ql,int qr){
	if(!x)return 0;
	if(l>=ql&&r<=qr)return sz[x];
	int mid=l+r>>1,ans=0;
	if(ql<=mid)ans+=qry(ls[x],l,mid,ql,qr);
	if(qr>mid)ans+=qry(rs[x],mid+1,r,ql,qr);
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)scanf("%d",b+i),pos[b[i]]=i;
	for(int i=1;i<=n;i++)upd(rt[i],rt[i-1],1,n,pos[a[i]]);
	scanf("%d",&m);
	for(int a,b,c,d;m--;){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a=f(a),b=f(b),c=f(c),d=f(d);
		if(a>b)swap(a,b);
		if(c>d)swap(c,d);
		printf("%d\n",x=qry(rt[b],1,n,c,d)-qry(rt[a-1],1,n,c,d));x++;
	}
}