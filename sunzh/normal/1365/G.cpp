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
int n;
int st[10010];
int cnt;
void dfs(int x,int s,int ns){
	if(x==14&&s==6){
		st[++cnt]=ns;return ;
	}
	if(s>6||s+14-x<6) return ;
	dfs(x+1,s,ns);
	dfs(x+1,s+1,ns|(1<<x-1));
}
long long w[13];
int main(){
	n=read();dfs(1,0,0);
	for(int i=0;i<13;++i){
		vector<int>ve;
		for(int j=1;j<=n;++j) if(st[j]>>i&1) ve.pb(j);
		if(!ve.size()) continue ;
		printf("? %d ",ve.size());
		for(int j:ve) printf("%d ",j);printf("\n");
		fflush(stdout);scanf("%lld",&w[i]);
	}
	printf("! ");
	for(int i=1;i<=n;++i){
		long long ans=0;
		for(int j=0;j<13;++j) if(!(st[i]>>j&1)) ans|=w[j];
		printf("%lld ",ans);
	}
}