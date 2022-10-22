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
int T;
int n;
int a[500010];
int tre[500010];
int que[500010];
int head,tail;
int pre[500010];
int ans;
int dp[500010];
vector<int>bck[500010];
int lowbit(int x){
	return x&-x;
}
void update(int x,int k){
	while(x<=n){
		tre[x]=max(tre[x],k);
		x+=lowbit(x);
	}
}
int query(int x){
	int res=0;
	while(x){
		res=max(res,tre[x]);x-=lowbit(x);
	}
	return res;
}
int main(){
	T=read();
	while(T--){
		ans=0;
		n=read();
		for(int i=1;i<=n;++i) a[i]=read();
		for(int i=1;i<=n;++i) tre[i]=que[i]=dp[i]=0,bck[i].clear(),pre[i]=-1;
		head=1,tail=0;
		que[++tail]=n;
		for(int i=n-1;i>=1;--i){
			while(head<=tail&&a[i]>=a[que[tail]]){
				pre[que[tail]]=i;bck[i].pb(que[tail]);--tail;
			}
			que[++tail]=i;
		}
		for(int i=1;i<=n;++i){
			dp[i]=max(dp[i],query(a[i])+1);
			ans=max(ans,dp[i]);
			for(int v:bck[i]){
				dp[v]=max(dp[v],query(a[v])+2);
			}
			update(a[i],dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}