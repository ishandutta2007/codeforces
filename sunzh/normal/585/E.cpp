#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<random>
#include<ctime>
#include<cstring>
#include<map>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
const int mod=1e9+7;
int n;
const int N=1e7;
int c[10000010];
int t[10000010],s[10000010];
int tot;
int mu[10000010];
bool vis[10000010];int p[2000010];
int pow2[500010];
void getp(int lim){
	mu[1]=1;
	for(int i=2;i<=lim;++i){
		if(!vis[i]) p[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&1ll*p[j]*i<=lim;++j){
			vis[p[j]*i]=1;
			if(i%p[j]==0){
				mu[p[j]*i]=0;
				break ;
			}
			else mu[p[j]*i]=-mu[i];
		}
	}
}
int add(int x,int y){
	return x+y>=mod?x+y-mod:x+y; 
}
void Add(int &x,int y){
	x=add(x,y);
}
int main(){
	n=read();
	getp(N);
	for(int i=1;i<=n;++i){
		int x=read();
		c[x]++; 
	}pow2[0]=1;
	for(int i=1;i<=n;++i) pow2[i]=(pow2[i-1]+pow2[i-1])%mod;
	for(int j=1;j<=tot;++j){
		for(int k=N/p[j];k;--k){
			(c[k]+=c[k*p[j]])%=mod;
		}
	}
	for(int i=1;i<=N;++i){
		s[i]=pow2[c[i]]-1;
	}
	for(int i=1;i<=N;++i) t[i]=(mu[i]*c[i]+mod)%mod;
	for(int i=1;i<=tot;++i){
		for(int j=1;1ll*j*p[i]<=N;++j){
			Add(t[j*p[i]],t[j]);
		}
	}
	for(int i=1;i<=tot;++i){
		for(int j=1;1ll*j*p[i]<=N;++j){
			s[j]=add(mod,s[j]-s[j*p[i]]);
		}
	}
	int ans=0;
	for(int i=2;i<=N;++i){
		Add(ans,1ll*s[i]*t[i]%mod);
	}
	printf("%d\n",ans);
}