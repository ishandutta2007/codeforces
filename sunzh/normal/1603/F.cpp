#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int T;
int n,k,x;
const int mod=998244353;
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int qdw[10000010],qif[10000010];
int pw[10000010];
int main(){
	pw[0]=1;
	for(int i=1;i<=10000000;++i) pw[i]=(pw[i-1]<<1)%mod;
	T=read();
	while(T--){
		n=read(),k=read(),x=read();
		if(x==0){
			if(n>k){
				printf("0\n");continue ;
			}
			int ans=1;
			for(int i=0;i<n;++i) ans=1ll*ans*(pw[k]-pw[i])%mod;
			printf("%d\n",(ans+mod)%mod);
		}
		else{
			int inv2=(mod+1>>1);
			{
				int cur=qpow(2,n);qdw[0]=1;
				for(int i=1;i<=k;++i){
					qdw[i]=1ll*qdw[i-1]*(1-cur)%mod;
					cur=1ll*cur*inv2%mod;
				}
			}
			{
				qif[0]=1;
				for(int i=1;i<=k;++i) qif[i]=1ll*qif[i-1]*(1-pw[i])%mod;
				qif[k]=qpow(qif[k]);
				for(int i=k-1;i>=0;--i) qif[i]=1ll*qif[i+1]*(1-pw[i+1])%mod;
			}
			auto qbi=[&](int x,int y){
				if(x!=n){
					printf("FUCKyou\n");return 0ll;
				}
				return 1ll*qdw[y]*qif[y]%mod;
			};
			// for(int i=1;i<=k;++i) pr[i]=1ll*pr[i-1]*qpow(1-pw[i])%mod*(1-qpow(2,n-i+1))%mod;
			int rs1=1;
			int ans=0;
			for(int i=1;i<=k&&i<=n;++i){
				rs1=1ll*rs1*(pw[k]-pw[i-1])%mod;
				// rs2=1ll*rs2*(1-pw[n-i+1])%mod;
				int res=1ll*rs1*qbi(n,i)%mod;
				(ans+=1ll*res*(pw[i]-1)%mod)%=mod;
			}
			printf("%d\n",(qpow(pw[k],n)-1ll*ans*qpow(pw[k]-1)%mod+mod)%mod);
		}
	}
}