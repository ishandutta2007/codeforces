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
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

struct node{
	int to,next;
}p[2000005];
int n,m,u[1000005],v[1000005],tot,head[1000005],up[1000005],dep[1000005],wa[1000005],si,res[1000005];
int ans[1000005];
bool go[1000005],vis[1000005];
inline void add(int x,int y){
	p[++tot].to=y;p[tot].next=head[x];head[x]=tot;
	p[++tot].to=x;p[tot].next=head[y];head[y]=tot;
}
inline void dfs(int x){
	vis[x]=1;
	for(int i=head[x];i;i=p[i].next){
		int y=p[i].to;
		if(vis[y]) continue;
		go[(i+1)/2]=1;dep[y]=dep[x]+1;
		up[y]=(i+1)/2;dfs(y);
		res[x]+=res[y];
	}
}

int main(){
	read(n,m);
	for(int i=1;i<=m;i++){
		read(u[i],v[i]);
		add(u[i],v[i]);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs(i);
	tot=0;
	for(int i=1;i<=m;i++){
		if(go[i]) continue;
		if(dep[u[i]]>dep[v[i]]) swap(u[i],v[i]);
		if((dep[v[i]]-dep[u[i]]&1)) {res[v[i]]--;res[u[i]]++;continue;}
		tot++;wa[tot]=i;res[u[i]]--;res[v[i]]++;
	}
	if(!tot){
		printf("%d\n",m); 
		for(int i=1;i<=m;i++) printf("%d%c",i,i==m?'\n':' ');
		return 0;
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i]) dfs(i);
	for(int i=1;i<=n;i++)
		if(res[i]==tot) ans[++si]=up[i];
	if(tot==1) ans[++si]=wa[1];
	printf("%d\n",si);
	sort(ans+1,ans+si+1);
	for(int i=1;i<=si;i++)
		printf("%d%c",ans[i],i==si?'\n':' ');
	return 0;
}