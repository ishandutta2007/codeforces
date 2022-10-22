#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
#define pow powl
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n,d,mod;
int f[1010][15][1010];
int ifac[10010];
int C(int x,int y){
//	printf("x:%d,y:%d\n",x,y);
	if(x<y)return 0;
	int res=1;
	for(int i=1;i<=y;++i) res=1ll*res*(x-i+1)%mod;
	res=1ll*res*ifac[y]%mod;
//	printf("x:%d,y:%d,res:%d\n",x,y,res);
	return res;
}
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	n=read(),d=read(),mod=read();
	int s=1;
	for(int i=1;i<=n;++i){
		s=1ll*s*i%mod;ifac[i]=qpow(s,mod-2);
	}
	for(int i=0;i<=n;++i) f[1][0][i]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=min(d,i-1);++j){
			for(int k=1;k<=n;++k){
				f[i][j][k]=f[i][j][k-1];
				for(int t=1;t<=j;++t){
					if(t*k>i) break ;
					if(k>1) (f[i][j][k]+=1ll*f[i-t*k][j-t][k-1]*C(f[k][d-1][k-1]+t-1,t)%mod)%=mod;
					else (f[i][j][k]+=1ll*f[i-t*k][j-t][k-1]*C(f[k][0][k-1]+t-1,t)%mod)%=mod;
				}
//				printf("f[%d][%d][%d]=%d\n",i,j,k,f[i][j][k]);
			}
		}
	}
	if(n<=2){
		printf("1\n");return 0;
	}
	if(n&1){
		printf("%d\n",f[n][d][n/2]);
	}
	else{
		printf("%d\n",(f[n][d][n/2]-1ll*C(f[n/2][d-1][n/2-1],2)+mod)%mod);
	}
}