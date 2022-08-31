#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
#define MAXN 1005
#define jsb 1000000007
typedef long long LL;
typedef double db;
int n;int f[MAXN][MAXN][4];int fac[MAXN];int comb[MAXN][MAXN];
inline void A(int &x,int y){
	x+=y;if(x>=jsb)x-=jsb;
}
int F[MAXN];
int init(){
	fac[0]=1;rep(i,1,n)fac[i]=fac[i-1]*1ll*i%jsb;
	rep(i,0,n){
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i-1){
			comb[i][j]=comb[i-1][j];
			A(comb[i][j],comb[i-1][j-1]);
		}
	}
	f[1][0][0]=1;
	f[1][1][2]=1;
	rep(i,1,n)
	rep(j,0,n)
	rep(zt,0,3)
	if(f[i][j][zt]){
		//put i+1 to i
		if(!(zt&1))A(f[i+1][j+1][zt/2],f[i][j][zt]);
		//put i+1 to i+2
		if(i+2<=n)A(f[i+1][j+1][zt/2+2],f[i][j][zt]);
		//don't put
		A(f[i+1][j][zt/2],f[i][j][zt]);
		//printf("f[%d][%d][%d]=%d\n",i,j,zt,f[i][j][zt]);
	}
	per(i,n,0){
		F[i]=(f[n][i][0]+f[n][i][1])%jsb;
		F[i]=F[i]*1ll*fac[n-i]%jsb;
		//printf("_%d\n",F[i]);
		rep(j,i+1,n)F[i]=(F[i]-F[j]*1ll*comb[j][i]%jsb)%jsb;
		//printf("__%d\n",F[i]);
	}
}
int k;
int main(){
	scanf("%d%d",&n,&k);
	if(k==n){printf("%d\n",!(k&1));return 0;}
	init();
	printf("%d\n",(F[k]+jsb)%jsb);
	return 0;
}