#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define max(a,b) ((a)>(b)?(a):(b))
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=5100;
int l[N],r[N];
int sta;
int n;
int node[N*2];int M=0;
LL f[N*2],g[N*2];
LL inf=(LL)1e16;
int main(){
	scanf("%d%d",&n,&sta);node[++M]=sta;
	rep(i,1,n){
		scanf("%d%d",&l[i],&r[i]);
		node[++M]=l[i];
		node[++M]=r[i];
	}
	sort(node+1,node+1+M);
	M=unique(node+1,node+1+M)-node-1;
	rep(i,1,n){
		l[i]=lower_bound(node+1,node+1+M,l[i])-node;
		r[i]=lower_bound(node+1,node+1+M,r[i])-node;
	}
	sta=lower_bound(node+1,node+1+M,sta)-node;
	rep(i,1,M)f[i]=inf;
	f[sta]=0;
	rep(i,1,n){
		LL bef=(LL)1e16;
		rep(j,1,M){
			if(f[j]-node[j]<bef)bef=f[j]-node[j];
			g[j]=bef+node[j];
		}
		bef=inf;
		per(j,M,1){
			if(f[j]+node[j]<bef)bef=f[j]+node[j];
			if(bef-node[j]<g[j])g[j]=bef-node[j];
		}
		LL R1=node[r[i]];
		LL L1=node[l[i]];
		rep(j,1,M){
			f[j]=g[j];
			if(node[j]>=R1)f[j]+=node[j]-R1;
			else if(node[j]<=L1)f[j]+=L1-node[j];
		}
	}
	LL ans=inf;
	rep(j,1,M)ans=min(ans,f[j]);
	printf("%I64d\n",ans);
	return 0;
}