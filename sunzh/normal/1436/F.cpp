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
int m;
int a[100010],freq[100010];
int mu[100010];
int pr[100010];
bool vis[100010];
int cnt;
int ans;
const int N=100000;
const int mod=998244353;
void getmu(){
	mu[1]=1;
	for(int i=2;i<=N;++i){
		if(!vis[i]) pr[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt&&1ll*pr[j]*i<=N;++j){
			vis[pr[j]*i]=1;
			if(i%pr[j]==0){
				mu[i*pr[j]]=0;break ;
			}
			else mu[i*pr[j]]=-mu[i];
		}
	}
}
inline int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
int main(){
	m=read();
	for(int i=1;i<=m;++i) a[i]=read(),freq[a[i]]=read();
	getmu();
	for(int i=1;i<=N;++i){
		if(mu[i]){
			long long c=0;
			int sum=0,squ=0;
			for(int j=i;j<=N;j+=i) (sum+=1ll*freq[j]%mod*j%mod)%=mod,(squ+=1ll*freq[j]%mod*j%mod*j%mod)%=mod,c+=freq[j];
			if(c<=1) continue ;
			sum=1ll*sum*sum%mod;sum=(sum-squ+mod)%mod;//sum=1ll*sum*qpow(2,mod-2)%mod;
			int S=0;
			if(c>=3) S=1ll*sum*(1ll*c%mod*qpow(2,(c-3)%(mod-1))%mod)%mod;
			else S=sum;
			(S+=1ll*(c-1)%mod*squ%mod*qpow(2,(c-2)%(mod-1))%mod)%=mod;
			(ans+=1ll*mu[i]*S%mod)%=mod;
		}
	}
	print((ans+mod)%mod);
}