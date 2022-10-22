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
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
const int mod=998244353;
int n;
vector<PII>vec[200010];
int dp[200010][4];// 0 no 1 fa 2 beforefa 3 afterfa
void dfs(int x,int fa,int num){
	bool f=0;
	vector<PII>son;
	for(auto i:vec[x]){
		int v=i.fi;if(v==fa) continue ;
		f=1;dfs(v,x,i.se);son.ep(i.se,v);
	}
	if(!f){
		dp[x][0]=1,dp[x][1]=1;return ;
	}
	sort(son.begin(),son.end());
	dp[x][0]=dp[x][1]=1;
	for(int i=0;i<son.size();++i){
		dp[x][0]=1ll*dp[x][0]*(dp[son[i].se][1]+dp[son[i].se][2])%mod;
		if(son[i].fi>num) dp[x][1]=1ll*dp[x][1]*((dp[son[i].se][0]+dp[son[i].se][2])%mod+dp[son[i].se][3])%mod;
		else dp[x][1]=1ll*dp[x][1]*(dp[son[i].se][1]+dp[son[i].se][2])%mod;
	}
	vector<int>pre(son.size()+2),suf(son.size()+2);
	//dp[x][2]
	suf[son.size()]=1;
	for(int i=son.size()-1;i>=0;--i){
		suf[i]=1ll*suf[i+1]*((dp[son[i].se][0]+dp[son[i].se][2])%mod+dp[son[i].se][3])%mod;
	}
	int sum=1;
	for(int i=0;i<son.size()&&son[i].fi<num;++i){
		(dp[x][2]+=1ll*sum*suf[i+1]%mod*(dp[son[i].se][0]+dp[son[i].se][3])%mod)%=mod;
		sum=1ll*sum*(dp[son[i].se][1]+dp[son[i].se][2])%mod;
	}
	//dp[x][3]
	sum=1;
	pre[0]=(dp[son[0].se][1]+dp[son[0].se][2])%mod;
	for(int i=1;i<son.size();++i) pre[i]=1ll*pre[i-1]*(dp[son[i].se][1]+dp[son[i].se][2])%mod;
	for(int i=0;i<son.size();++i){
		if(son[i].fi>num){
			(dp[x][3]+=1ll*(i==0?1:pre[i-1])*(dp[son[i].se][0]+dp[son[i].se][3])%mod*suf[i+1]%mod)%=mod;
		}
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].ep(v,i);
		vec[v].ep(u,i);
	}
	dfs(1,0,0);
	printf("%d\n",(dp[1][0]+dp[1][3])%mod);
	
}