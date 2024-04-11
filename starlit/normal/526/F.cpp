#include<bits/stdc++.h>
const int N=300005;
using namespace std;
int n,x,y,a[N],i,cnt;
long long ans;
struct T{
	int l,r,ad,mn,ti;
	T*ls,*rs;
	void build(int,int);
	inline void pls(int v){
		ad+=v,mn+=v;
	}
	void deb(){
		cerr<<'['<<l<<','<<r<<']'<<mn<<'/'<<ti<<'('<<ad<<endl;
		if(l<r)ls->deb(),rs->deb();
	}
	void mdf(int v){
		//if(l==1&&r==n)cerr<<"Mdf "<<x<<'~'<<y<<' '<<v<<endl;
		if(l>y||r<x)return;
		if(l>=x&&r<=y)pls(v);
		else{
			if(ad)ls->pls(ad),rs->pls(ad),ad=0;
			ls->mdf(v),rs->mdf(v);
			mn=min(ls->mn,rs->mn),ti=0;
			if(mn==ls->mn)ti+=ls->ti;
			if(mn==rs->mn)ti+=rs->ti;
		}
	}
}b[N*2],*rt;
void T::build(int L,int R){
	l=mn=L,r=R,ti=1;
	if(l<r){
		int mi=l+r>>1;
		(ls=&b[cnt++])->build(l,mi);
		(rs=&b[cnt++])->build(mi+1,r);
	}
}
struct sta{
	int sx[N],sy[N],t;
	inline void ins(int v){
		int ls=x=y=i;
		rt->mdf(v);
		for(;t&&sy[t]<v;t--)
		x=sx[t],y=ls-1,rt->mdf(v-sy[t]),ls=x;
		sx[++t]=ls,sy[t]=v;
	}
}Mx,Mn;
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d%d",&x,&y),a[x]=y;
	(rt=&b[cnt++])->build(1,n);
	for(i=1;i<=n;i++)
	//cerr<<"ins "<<a[i]<<endl,
	Mx.ins(a[i]),Mn.ins(-a[i]),
	ans+=rt->ti/*,rt->deb()*/;
	printf("%lld",ans);
}