#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
int T,na,nb,nc,a[MN],b[MN],c[MN];
LL sqr(LL a){return a*a;}
LL calc(int *a,int *b,int *c,int x,int y,int z){
	return sqr(a[x]-b[y])+sqr(a[x]-c[z])+sqr(b[y]-c[z]);
}
LL work(int *a,int *b,int *c,int na,int nb,int nc){
	LL res=4e18;
	int p1=1,p2=1;
	for(int i=1;i<=na;++i){
		while(b[p1]<a[i]&&p1<=nb)p1++;
		if(p1>nb)break;
		while(c[p2]<b[p1]&&p2<=nc)p2++;
		if(p2>nc)break;
		while(p1<=nb&&b[p1+1]<=c[p2]&&calc(a,b,c,i,p1,p2)>=calc(a,b,c,i,p1+1,p2))
			p1++;
	//	cerr<<"? "<<i<<" "<<p1<<" "<<p2<<" "<<a[i]<<" "<<b[p1]<<" "<<c[p2]<<endl;
		res=min(res,calc(a,b,c,i,p1,p2));
	}
	return res;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&na,&nb,&nc);
		for(int i=1;i<=na;++i)scanf("%d",&a[i]);
		for(int i=1;i<=nb;++i)scanf("%d",&b[i]);
		for(int i=1;i<=nc;++i)scanf("%d",&c[i]);
		sort(a+1,a+1+na);
		sort(b+1,b+1+nb);
		sort(c+1,c+1+nc);
		LL ans=4e18;
		ans=min(ans,work(a,b,c,na,nb,nc));
		ans=min(ans,work(a,c,b,na,nc,nb));
		ans=min(ans,work(b,a,c,nb,na,nc));
		ans=min(ans,work(b,c,a,nb,nc,na));
		ans=min(ans,work(c,a,b,nc,na,nb));
		ans=min(ans,work(c,b,a,nc,nb,na));
		for(int i=1;i<=na;++i)a[i]=0;
		for(int i=1;i<=nb;++i)b[i]=0;
		for(int i=1;i<=nc;++i)c[i]=0;
		printf("%lld\n",ans);
	}
}