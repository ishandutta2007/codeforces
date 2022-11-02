#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int gint(){
	char c; int f=1;
	while(c=getchar(),c<48||c>57)
		if(c=='-')f=-1;
	int x=0;
	for(;c>47&&c<58;c=getchar()){
		x=x*10+c-48;
	}
	return x*f;
}

#define max_N 100005
typedef long long ll;

struct edge{
	int v,n;
	edge(int v=0,int n=0):v(v),n(n){}
}e[max_N<<1];

int head[max_N],tot;

inline void add_edge(int u,int v){
	e[++tot]=edge(v,head[u]),head[u]=tot;
}

int n,a[max_N];

ll f[max_N][2];

void dfs(int x,int p=0){
	for(int i=head[x],y;i;i=e[i].n)
		if((y=e[i].v)!=p){
			dfs(y,x);
			f[x][0]=max(f[x][0],f[y][0]);
			f[x][1]=max(f[x][1],f[y][1]);
		}
	ll b=a[x]-f[x][0]+f[x][1];
	if(b>0)f[x][0]+=b;
	else f[x][1]-=b;
}

int main(){
	n=gint();
	for(int i=1,u,v;i<n;++i){
		u=gint(),v=gint();
		add_edge(u,v),add_edge(v,u);
	}
	for(int i=1;i<=n;++i)a[i]=gint();
	dfs(1);
	printf("%I64d\n",f[1][0]+f[1][1]);
	return 0;
}