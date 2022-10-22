#include<cstdio>
#include<algorithm>
using namespace std;
const int o=22,inf=1e9+10;
struct country{int l,r,t,id;}c[o];
inline bool cmp(country A,country B){return A.l<B.l;}
int n,p,f[1<<o],lst[1<<o],id[o],t[o];
inline void slv(int id_,int S){for(;S;S^=(1<<lst[S])) id[c[lst[S]].id]=id_,t[c[lst[S]].id]=f[S]-c[lst[S]].t;}
inline void prt(){printf("YES\n");for(int i=0;i<n;++i) printf("%d %d\n",id[i],t[i]);}
int main(){
	scanf("%d%d",&n,&p);
	for(int i=0;i<n;++i) scanf("%d%d%d",&c[i].l,&c[i].r,&c[i].t),c[i].r+=c[i].l-1,c[i].id=i;
	sort(c,c+n,cmp);
	for(int i=f[0]=1,j,v;i<(1<<n);++i) for(f[i]=inf,j=0;j<n;++j) if((i>>j)&1){
		v=f[i^(1<<j)];
		for(int k=0;k<n;++k){
			if(v>=c[k].l) v=max(v,c[k].r+1);
			else if(v+c[j].t>=c[k].l&&((i>>k)&1)) v=c[k].r+1;
		}
		if(v+c[j].t<c[j].l&&v+c[j].t<f[i]) f[i]=v+c[lst[i]=j].t;
	}
	if(p<2) if(f[(1<<n)-1]<inf) slv(1,(1<<n)-1),prt();else printf("NO");
	else{
		for(int i=0;i<(1<<n);++i)
			if(f[i]<inf&&f[((1<<n)-1)^i]<inf){slv(1,i);slv(2,((1<<n)-1)^i);prt();return 0;}
		printf("NO");
	}
	return 0;
}