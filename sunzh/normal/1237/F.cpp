#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
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
int n,m;
int k;
const int mod=998244353;
int f[4010][4010],g[4010][4010];
bool visx[4010],visy[4010];
int fac[4010],ifac[4010];
int ans;
inline int C(int x,int y){
//	printf("x:%d,y:%d\n",x,y);
	if(x-y<0) return 0;
	if(x==0&&y==0) return 1;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
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
int cx,cy;
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;++i){
		int r1=read(),c1=read(),r2=read(),c2=read();
		visx[r1]=visx[r2]=1;
		visy[c1]=visy[c2]=1;
	}
	for(int i=1;i<=n;++i) if(visx[i]) ++cx;
	for(int i=1;i<=m;++i) if(visy[i]) ++cy;
	fac[1]=fac[0]=1;
	for(int i=2;i<=4000;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[4000]=qpow(fac[4000],mod-2);
	for(int i=3999;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	f[0][0]=f[1][0]=1;
	for(int i=2;i<=n;++i){
		for(int j=0;j*2+cx<=n;++j){
			f[i][j]=f[i-1][j];
			if(j&&visx[i-1]+visx[i]==0) (f[i][j]+=f[i-2][j-1])%=mod;
//			printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
	}
	g[0][0]=g[1][0]=1;
	for(int i=2;i<=m;++i){
		for(int j=0;j*2+cy<=m;++j){
			g[i][j]=g[i-1][j];
			if(j&&visy[i-1]+visy[i]==0) (g[i][j]+=g[i-2][j-1])%=mod; 
		}
	}
	for(int i=0;i<=(n-cx)/2;++i){
		for(int j=0;j<=(m-cy)/2;++j){
			(ans+=1ll*f[n][i]*C(n-cx-2*i,j)%mod*g[m][j]%mod*C(m-cy-2*j,i)%mod*fac[i]%mod*fac[j]%mod)%=mod;
		}
	}
	print(ans);
}