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
#define lb lower_bound
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
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=100005,inf=1e9;
struct node{
	int to,next;
}p[N<<2],g[N<<2];
set<pii> e;
int ans,n,q,tot,head[N],h[N],dep[N],dp[N][20],num[N],s[N<<2],sta[N<<2],top,l[N],r[N];
bool vis[N],tag[N];
inline void add(int x,int y){
	p[++tot].to=y;p[tot].next=head[x];head[x]=tot;
	p[++tot].to=x;p[tot].next=head[y];head[y]=tot;
}
inline void rise(int &x,int y){
	if(!y) return;
	for(int i=0;i<19;i++) if(y&(1<<i)) x=dp[x][i];
}
inline int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	rise(x,dep[x]-dep[y]);
	if(x==y) return x;
	for(int i=18;~i;i--)
		if(dp[x][i]!=dp[y][i]) x=dp[x][i],y=dp[y][i];
	return dp[x][0];
}
inline void dfs(int x){
	vis[x]=1;l[x]=num[x]=++tot;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		dep[y]=dep[x]+1;dfs(y);
		dp[y][0]=x;
	}
	r[x]=tot;
}
inline bool cmp(int a,int b){
	return num[a]<num[b];
}
inline bool fa(int x,int y){
	return (num[y]>=l[x]&&num[y]<=r[x]);
}
inline void get(int &ans,int x,int y){
	if(tag[x]&&tag[y]&&e.count(mp(x,y))) ans=-inf;
//	printf("%d %d\n",x,y);
	g[++tot].to=y;g[tot].next=h[x];h[x]=tot;
}
inline int usb(int x){
	int si=0;
	for(int i=h[x];i;i=g[i].next){
		int y=g[i].to;
		si+=usb(y);
	}
	if(tag[x]) ans+=si,si=1;
	else if(si>1) ans++,si=0;
	return si;
}

int main(){
	read(n);
	for(int i=1;i<n;i++){
		int x,y;read(x,y);
		add(x,y);
		e.insert(mp(x,y));e.insert(mp(y,x));
	}
	tot=0;dfs(1);
	for(int i=1;i<19;i++)
		for(int j=1;j<=n;j++)
			dp[j][i]=dp[dp[j][i-1]][i-1];
	read(q);
	for(;q--;){
		int k,m,t;read(k);m=k;ans=0;
		for(int i=1;i<=k;i++) scanf("%d",&s[i]),tag[s[i]]=1;
		sort(s+1,s+k+1,cmp);
		for(int i=1;i<k;i++) s[++m]=lca(s[i],s[i+1]);
		sort(s+1,s+m+1,cmp);
		k=0;
		for(int i=1;i<=m;i++) if(i==1||s[i]!=s[i-1]) s[++k]=s[i];
		top=0;tot=0;
		for(int i=1;i<=k;i++){
			while(top&&!fa(sta[top],s[i])) top--;
			if(top) get(ans,sta[top],s[i]);
			sta[++top]=s[i];
		}
//		printf("%d\n",ans);
		usb(s[1]);
		printf("%d\n",ans>=0?ans:-1);
		for(int i=1;i<=k;i++) tag[s[i]]=0,h[s[i]]=0;
	}
	return 0; 
}