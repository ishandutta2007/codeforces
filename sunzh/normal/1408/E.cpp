#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
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
int m,n;
int a[100010];
int b[100010];
int cnt;
struct node{
	int u,v,w;
	bool operator <(const node &x)const{
		return w>x.w;
	}
}e[400010];
int fa[200010];
long long ans;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void kruskal(){
	int c=0;
	for(int i=1;i<=n+m;++i) fa[i]=i;
	for(int i=1;i<=cnt;++i){
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy){
			++c;ans-=e[i].w;
			fa[fx]=fy;if(c==n+m-1) break ;
		}
	}
}
int main(){
	m=read(),n=read();
	for(int i=1;i<=m;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	for(int i=1;i<=m;++i){
		int s=read();
		for(int j=1;j<=s;++j){
			int x=read();
			e[++cnt].u=i,e[cnt].v=x+m,e[cnt].w=a[i]+b[x];
			ans+=e[cnt].w;
		}
	}
	sort(e+1,e+cnt+1);
	kruskal();
	printf("%lld\n",ans);
	return 0;
}