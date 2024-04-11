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
int T;
int n;
int dp[1<<21];
char A[100010];
char B[100010];
vector<int>vec[22];
int mask[22];
bool vis[22];
void dfs(int x){
	vis[x]=1;
	for(int v:vec[x]){
		if(!vis[v]) dfs(v);
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",A+1);
		scanf("%s",B+1);
		for(int i=0;i<=20;++i) vec[i].clear(),mask[i]=vis[i]=0;
		for(int i=1;i<=n;++i){
			if(!(mask[A[i]-'a']&(1<<(B[i]-'a')))){
				mask[A[i]-'a']|=1<<B[i]-'a';
				vec[A[i]-'a'].pb(B[i]-'a');
				vec[B[i]-'a'].pb(A[i]-'a');
			}
		}
		int cnt=0,alp=0;
		for(int i=0;i<=20;++i){
			if(mask[i]){
				if(!vis[i]) dfs(i),++cnt;
			}
		}
		for(int i=0;i<=20;++i) alp+=vis[i];
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int ans=0;
		auto getbit=[&](int x){
//			printf("x:%d\n",x);
			int c=0;
			for(int i=21;i>=0;--i){
				c+=(x&(1<<i))>>i;
			}
			return c;
		};
		for(int i=0;i<(1<<20);++i){
			if(dp[i]){
				ans=max(ans,getbit(i));
				for(int k=0;k<=20;++k){
					if(vis[k]==0) continue ;
					if((mask[k]&i)==0&&(i&(1<<k))==0){
//						printf("k:%d\n",k);
						dp[i|(1<<k)]=1;
					}	
				}
			}
		}
//		printf("%d %d %d\n",alp,cnt,ans);
		printf("%d\n",2*alp-cnt-ans);
	}
	return 0;
}