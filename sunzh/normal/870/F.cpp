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
int phi[10000010];
int f[10000010];
int cnt[10000010];
int g[10000010];
int n;
bool vis[10000010];
int prime[10000010];
long long ans;
int tot;
int main(){
	n=read();
	phi[1]=1;
	for(int i=2;i<=n;++i){
		if(!vis[i]) prime[++tot]=i,phi[i]=i-1,f[i]=i;
		for(int j=1;j<=tot&&1ll*prime[j]*i<=n;++j){
			f[i*prime[j]]=prime[j];
			vis[i*prime[j]]++;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break ;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
		ans-=phi[i];
//		printf("phi[%d]=%d\n",i,phi[i]);
	}
//	printf("%lld\n",ans);
	ans+=(1ll*n*(n-1)>>1);
	long long tmp=0;
	for(int i=2;i<=n;++i) ++cnt[f[i]];
	for(int i=2;i<=n;++i) g[i]=g[i-1]+cnt[i];
	for(int i=1;i<=tot;++i){
		tmp+=1ll*cnt[prime[i]]*(g[n/prime[i]]);
	}
//	printf("%lld\n",tmp);
	for(int i=1;i<=n;++i){
		if(i*i<=n){
			tmp-=cnt[i];
		}
		else break ;
	}
	tmp>>=1;tmp-=ans;
	long long all=1ll*n*(n-1)>>1;all-=n-1;
	int k=n-1;
	for(int i=1;i<=tot;++i){
		if(prime[i]>(n>>1)){
			all-=k-1;--k;
		}
	}
//	printf("%lld %lld %lld\n",ans,tmp,all);
	printf("%lld\n",ans+2ll*tmp+3ll*(all-tmp-ans));
}