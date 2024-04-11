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
int n;
const int mod=998244353;
int l[110],r[110];
int pos[110];
int cnt;
int sum[110];
int dp[60][110];
int inv[110];
inline int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int tot=1;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read();
		pos[++cnt]=l[i],pos[++cnt]=r[i]+1;
		tot=1ll*tot*(r[i]-l[i]+1)%mod;
	}
	for(int i=1;i<=n;++i) inv[i]=qpow(i,mod-2);
	sort(pos+1,pos+cnt+1);
	int m=unique(pos+1,pos+cnt+1)-pos-1; 
	dp[0][m]=1;
	for(int i=0;i<n;++i){
		for(int j=m;j>=1;--j) sum[j]=(sum[j+1]+dp[i][j])%mod;
		for(int j=m-1;j>=1;--j){
			int Comb=pos[j+1]-pos[j];
			for(int k=i+1;k<=n;++k){
				if(r[k]<pos[j]||l[k]>=pos[j+1]) break ;
				(dp[k][j]+=1ll*Comb*sum[j+1]%mod)%=mod;
				Comb=1ll*Comb*(pos[j+1]-pos[j]+k-i)%mod*inv[k-i+1]%mod;
//				(S+=1ll*Comb*(k-i-1)%mod)%=mod;
//				(S+=tmp+Comb)%=mod;
//				(tmp+=Comb)%=mod;
//				printf("k-i+1:%d\n",k-i+1);printf("S:%d\n",S);
			}
		}
//		for(int j=1;j<=m;++j) printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	}
	for(int i=m;i>=1;--i) sum[i]=(sum[i+1]+dp[n][i])%mod;
//	for(int i=m;i>=1;--i) printf("%d ",sum[i]);
//	printf("%d\n",sum[1]);
	printf("%d\n",1ll*sum[1]*qpow(tot,mod-2)%mod);
	return 0;
}