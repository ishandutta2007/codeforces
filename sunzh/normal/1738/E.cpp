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
#include<random>
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
const int mod=998244353;
int T;
int n;
int a[100010];
inline int qpow(int x,int k=mod-2){
	int res=1;
	while(k){ if(k&1) res=1ll*res*x%mod; x=1ll*x*x%mod; k>>=1;}
	return res;
}
int fac[100010],ifac[100010];
int C(int x,int y){
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
int main(){
	fac[0]=1;
	for(int i=1;i<=100000;++i) fac[i]=1ll*fac[i-1]*i%mod;
	ifac[100000]=qpow(fac[100000]);
	for(int i=99999;i>=0;--i) ifac[i]=1ll*ifac[i+1]*(i+1)%mod;
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		map<long long ,int>s1,s2;
		long long nws=0;
		int ans=1;
		for(int i=1;i<=n;++i){
			nws+=a[i];
			s1[nws]++;
		}
		nws=0;
		for(int i=n;i>=1;--i){
			nws+=a[i];
			s2[nws]++;
		}
		for(auto i:s1){
			if(i.fi*2>nws) break ;
			if(i.fi*2==nws){
				ans=1ll*ans*qpow(2,i.se-(i.se==n))%mod;
			}
			else{
				int t=s2[i.fi];
				int su=0;
				for(int j=0;j<=t&&j<=i.se;++j) (su+=1ll*C(i.se,j)*C(t,j)%mod)%=mod;
				ans=1ll*ans*su%mod;
			}
		}
		printf("%d\n",ans);
	}
}