#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;

inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}

struct node{
	int to,next;
}p[100005];
int n,m,u[100005],dp[100005],v[100005],head[100005],tot;
bool vis[100005];

inline void add(int x,int y){
	p[++tot].to=y;p[tot].next=head[x];head[x]=tot;
}
inline int dfs(int x){
	if(vis[x]) return dp[x];
	vis[x]=1;dp[x]=0;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		dp[x]=max(dfs(y),dp[x]);
	}
	return ++dp[x];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	int l=1,r=m+1;
	for(;l<r;){
		int mid=l+r>>1,ans=0;
		tot=0;memset(head,0,sizeof(head));
		for(int i=1;i<=mid;i++)
			add(u[i],v[i]);
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			ans=max(ans,dfs(i));
		if(ans==n) r=mid; else l=mid+1;
	}
	if(r==m+1) puts("-1");
	else printf("%d\n",r);
	return 0;
}