#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
typedef long long LL;
typedef double db;
int n,t;
int base=1000000;
const int MAXN=2100;
int ss[MAXN],sl[MAXN],ts[MAXN],tl[MAXN];db p[MAXN];
int order[MAXN];int pp[MAXN];
LL f[MAXN];db g[MAXN];
inline void relax(int x,LL a1,db a2){
	if(f[x]<a1||(f[x]==a1&&g[x]>a2)){
		f[x]=a1;g[x]=a2;
	}
}
bool cmp(const int i,const int j){
	return (tl[i]+tl[j])*1.*(base-pp[j])*1.*base+tl[i]*1.*pp[j]*1.*(base-pp[i]) < (tl[i]+tl[j])*1.*(base-pp[i])*1.*base+tl[j]*1.*pp[i]*1.*(base-pp[j]);
}
int main(){
	scanf("%d%d",&n,&t);
	rep(i,1,n){
		scanf("%d%d%d%d%lf",&ss[i],&sl[i],&ts[i],&tl[i],&p[i]);
		order[i]=i;
		pp[i]=(int)(p[i]*base+0.5);
	}
	sort(order+1,order+1+n,cmp);
	rep(i,1,n){
		int x=order[i];
		per(j,t,0){
			// only small
			if(j+ts[x]<=t)relax(j+ts[x],f[j]+ss[x]*1ll*base,g[j]+ts[x]);
			// small and big
			if(j+ts[x]+tl[x]<=t)relax(j+ts[x]+tl[x],f[j]+sl[x]*1ll*(base-pp[x])+ss[x]*1ll*base,ts[x]+g[j]*p[x]+(j+tl[x])*(1-p[x]));
		}
	}
	db ans=g[t];
	rep(i,0,t)if(f[i]==f[t]&&g[i]<ans)ans=g[i];
	printf("%.10lf %.10lf\n",f[t]*1./base,ans);
	return 0;
}