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
typedef long long LL;
typedef double db;
#define MAXN 8005
#define jsb 1000000009
int f[MAXN],g[MAXN];
int C(int n,int m){
	if(n>m)return 0;
	return (f[m]*1ll*g[n]%jsb)*g[m-n]%jsb;
}
int Pow(int a,int b){
	int c=1;
	for(;b;b>>=1,a=a*1ll*a%jsb)
	{
		if(b&1)c=c*1ll*a%jsb;
	}
	return c;
}
void init(){
	f[0]=1;g[0]=1;
	rep(i,1,8000){
		f[i]=f[i-1]*1ll*i%jsb;
		g[i]=Pow(f[i],jsb-2);
	}
}
inline void A(int &x,int y){x+=y;x%=jsb;}
inline int M(int x,int y){return x*1ll*y%jsb;}
int res=0;
int main(){
	int n,w,b;scanf("%d%d%d",&n,&w,&b);init();
	//printf("_%d\n",C(0,0));
	//printf("_%d\n",C(0,1));
	rep(i,2,n){
		int j=n-i;if(j<=0)continue;
		//if(i==2)printf("%d %d %d %d\n",i-2,w-2,j-1,b-1);
		A(res,M(M(C(i-1,w-1),(i-1)),C(j-1,b-1)));
	}
	res=M(res,f[w]);
	res=M(res,f[b]);
	printf("%d\n",res);
	return 0;
}