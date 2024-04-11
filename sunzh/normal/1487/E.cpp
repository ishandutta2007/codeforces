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
#define int long long
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
int n[5];
int a[5][150010];
long long dp[5][150010];
long long ans=1e18;
set<int>st[5][150010];
signed main(){
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=4;++i) n[i]=read();
	for(int i=1;i<=4;++i){
		for(int j=1;j<=n[i];++j) a[i][j]=read();
	}
	for(int i=2;i<=4;++i){
		int t=read();
		while(t--){
			int u=read(),v=read();
			st[i][v].insert(u);
		}
	}
	for(int i=1;i<=n[1];++i) dp[1][i]=a[1][i];
	for(int i=2;i<=4;++i){
		set<pair<long long,int> >Q;
		for(int j=1;j<=n[i-1];++j) Q.insert(mp(dp[i-1][j],j));
		for(int j=1;j<=n[i];++j){
			auto it=Q.begin();
			while(st[i][j].count(it->se)){
				++it;
			}
			if(it==Q.end()) continue ;
			else dp[i][j]=it->fi+a[i][j];
		}
	}
	for(int i=1;i<=n[4];++i) ans=min(ans,dp[4][i]);
	if(ans>=5e10) printf("-1\n");
	else printf("%lld\n",ans);
}