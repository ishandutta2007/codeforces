#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define pb push_back
#define rep(i,j,k) for(register int i=(j);i<=(k);i++)
#define per(i,j,k) for(int i=(j);i>=(k);i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
#define jsb 1000000007
typedef long long LL;
typedef double db;
int f[15][15],g[15][15];
int m;int is[15];
int Pow(int a,int b){int c=1;for(;b;b>>=1,a=a*1ll*a%jsb)if(b&1)c=c*1ll*a%jsb;return c;}
int res[15];
inline void A(int &x,int y){
	x+=y;if(x>=jsb)x-=jsb;
}
void dp(){
	int x[11];int u=m;per(i,10,1)x[i]=u%10,u/=10;
	g[0][0]=1;
	rep(i,0,9)rep(j,0,10){
		rep(k,0,x[i+1]-1){
			A(f[i+1][j+is[k]],f[i][j]);
			A(f[i+1][j+is[k]],g[i][j]);
		}
		A(f[i+1][j+is[x[i+1]]],f[i][j]);
		A(g[i+1][j+is[x[i+1]]],g[i][j]);
		rep(k,x[i+1]+1,9){
			A(f[i+1][j+is[k]],f[i][j]);
		}
	}
	rep(i,0,10){A(res[i],f[10][i]);A(res[i],g[10][i]);}
}
int nw[10];
int C(int y,int x){
	if(x==0)return 1;
	if(y<x)return 0;
	int ress=1;
	rep(i,y-x+1,y)ress=ress*1ll*i%jsb;
	return ress;
}
void Work(){
	int ress=0;
	rep(x1,0,9)rep(x2,0,9)rep(x3,0,9)rep(x4,0,9)rep(x5,0,9)rep(x6,0,9)
	rep(x7,1,9)if(x7>x1+x2+x3+x4+x5+x6){
		int bi[11];memset(bi,0,sizeof bi);
		bi[x1]++;bi[x2]++;bi[x3]++;bi[x4]++;bi[x5]++;bi[x6]++;bi[x7]++;
		int top=1;
		rep(i,0,10)top=top*1ll*C(res[i],bi[i])%jsb;
		//if(top)printf("%d\n",top);
		A(ress,top);
	}
	printf("%d\n",ress);
}
int main(){
	nw[0]=1;rep(i,1,7)nw[i]=Pow(i,jsb-2);
	scanf("%d",&m);is[4]=is[7]=1;dp();is[4]=is[7]=1;
	res[0]--;
	//rep(i,0,3)printf("%d\n",res[i]);
	Work();
	return 0;
}