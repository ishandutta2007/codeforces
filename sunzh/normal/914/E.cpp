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
int n;
vector<int>vec[200010];
bool vis[200010];
int siz[200010];
int maxs[200010];
long long cnt[1<<20|1];
int sum,rt;
int col[200010];
char str[200010];
long long ans[200010];
inline long long max(long long x,long long y){
	return x>y?x:y;
}
inline int max(int x,int y){
	return x>y?x:y;
}
void getsize(int x,int f){
	siz[x]=1;++sum;
	for(int v:vec[x]){
		if(vis[v]||v==f) continue ;
		getsize(v,x);
		siz[x]+=siz[v];
	}
}
void getrt(int x,int f){
	maxs[x]=0;
	for(int v:vec[x]){
		if(vis[v]||v==f) continue ;
		getrt(v,x);
		maxs[x]=max(maxs[x],siz[v]);
	}
	maxs[x]=max(maxs[x],sum-siz[x]);
	if(maxs[x]<maxs[rt]) rt=x;
}

void dfs(int x,int f,int k,int S){
	S^=(1<<col[x]);cnt[S]+=k;
	for(int v:vec[x]){
		if(v==f||vis[v]) continue ;
		dfs(v,x,k,S);
	}
}

long long get_cnt(int x,int f,int S){
	long long res=0;
	S^=(1<<col[x]);
	res=cnt[S];
	for(int i=0;i<='t'-'a';++i) res+=cnt[S^(1<<i)];
	for(int v:vec[x]){
		if(vis[v]||v==f) continue ;
		res+=get_cnt(v,x,S);
	}
	ans[x]+=res;
	return res;
}

void calc(int x){//xx 
	dfs(x,x,1,0);
	long long res=cnt[0];
	for(int i=0;i<='t'-'a';++i) res+=cnt[1<<i];
	for(int v:vec[x]){
		if(vis[v]) continue ;
		dfs(v,x,-1,1<<col[x]);
		res+=get_cnt(v,x,0);
		dfs(v,x,1,1<<col[x]);
	}
	ans[x]+=(res+1)/2;
	dfs(x,x,-1,0);
	return ;
}
void solve(int x){
	vis[x]=1;
	calc(x);
	for(int v:vec[x]){
		if(vis[v]) continue ;
		sum=rt=0;
		getsize(v,x);getrt(v,x);solve(rt);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();vec[u].pb(v),vec[v].pb(u);
	}
	scanf("%s",str+1);
	for(int i=1;i<=n;++i) col[i]=str[i]-'a';
	sum=rt=0;maxs[0]=1e9;
	getsize(1,1);
	getrt(1,1);
	solve(rt);
	for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
}