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
const int jsb=1000000007;
inline void A(int &x,int y){x+=y;if(x>=jsb)x-=jsb;}
int f[35][35],g[35][35];
int main(){
	int k;scanf("%d",&k);int a[35];int w=0;
	while(k){
		a[++w]=k&1;
		k/=2;
	}
	g[w][0]=1;
	per(i,w-1,0)rep(j,0,w){
		A(f[i][j+1],f[i+1][j]);
		//1
		A(f[i][j],f[i+1][j]*1ll*(1<<j)%jsb);
		//0
		if(a[i+1]){
			A(g[i][j+1],g[i+1][j]);
			//1 
			A(g[i][j],g[i+1][j]*1ll*((!j)?0:(1<<(j-1)))%jsb);
			// 
			A(f[i][j],g[i+1][j]*1ll*((!j)?1:(1<<(j-1)))%jsb);
			//
		}
		else A(g[i][j],g[i+1][j]*1ll*((!j)?1:(1<<(j-1)))%jsb);
	}
	int res=0;
	rep(j,0,30)A(res,f[0][j]),A(res,g[0][j]);
	printf("%d\n",res);
	return 0;
}