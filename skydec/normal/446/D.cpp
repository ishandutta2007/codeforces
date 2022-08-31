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
db a[650][650];int n,tot,m,k;int wei[505];int be[505],du[505];
db val[150][150];db c[150][150];db e[150][150];
inline void mulval(){
	memset(e,0,sizeof e);
	rep(i,1,tot)rep(j,1,tot)rep(k,1,tot)e[i][j]+=val[i][k]*val[k][j];
	rep(i,1,tot)rep(j,1,tot)val[i][j]=e[i][j];
}
inline void mulc(){
	memset(e,0,sizeof e);
	rep(i,1,tot)rep(j,1,tot)rep(k,1,tot)e[i][j]+=c[i][k]*val[k][j];
	rep(i,1,tot)rep(j,1,tot)c[i][j]=e[i][j];
}
void solve(){
	rep(i,1,n)if(wei[i])rep(j,n+1,tot)val[be[i]-n][j-n]=-a[i][j];
	tot-=n;
	rep(i,1,tot)c[i][i]=1;
	k-=2;
	for(;k;k>>=1,mulval())if(k&1)mulc();
	db res=0;
	rep(i,n+1,n+tot)res+=c[i-n][tot]*(-a[1][i]);
	printf("%.10lf\n",res);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);tot=n;
	rep(i,1,n){
		scanf("%d",&wei[i]);
		if(wei[i])be[i]=++tot;
	}
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);du[x]++;du[y]++;
		if(wei[y])a[x][be[y]]++;
		else a[x][y]++;
		
		if(wei[x])a[y][be[x]]++;
		else a[y][x]++;
	}
	rep(i,1,n)rep(j,1,tot)a[i][j]/=du[i];
	rep(i,1,n)a[i][i]=-1;
	
	rep(i,1,n){
		rep(j,i,n)if(a[j][i]!=0){
			rep(k,1,tot)swap(a[j][k],a[i][k]);
			break;
		}
		db haha=a[i][i];
		rep(j,1,tot)a[i][j]/=haha;
		rep(j,1,n)if(i^j&&a[j][i]!=0){
			per(k,tot,i)a[j][k]-=a[j][i]*a[i][k];
		}
	}
	solve();
	return 0;
}