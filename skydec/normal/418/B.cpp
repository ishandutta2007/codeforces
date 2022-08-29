#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
LL f[1<<20];
struct cat{
	int k,use,x;
}a[105];int n,m,b;
inline bool cmp(const cat &a,const cat &b){return a.k>b.k;}
int main(){
	scanf("%d%d%d",&n,&m,&b);int biu=0;
	for(int i=1;i<=n;i++){
		int x,k,p;scanf("%d%d%d",&x,&k,&p);
		a[i].x=x;a[i].k=k;
		for(int j=1;j<=p;j++){
			int u;scanf("%d",&u);a[i].use|=(1<<(u-1));
		}
		biu|=a[i].use;
	}
	if(biu!=((1<<m)-1)){
		printf("-1");
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<(1<<m);i++)f[i]=(LL)(1e18)+1e16;
	for(int i=1;i<=n;i++)for(int j=0;j<(1<<m);j++){
		LL cost=a[i].x;if(j==0)cost+=a[i].k*1ll*b;
		f[j|a[i].use]=min(f[j|a[i].use],f[j]+cost);
	}
	printf("%I64d\n",f[(1<<m)-1]);
	return 0;
}