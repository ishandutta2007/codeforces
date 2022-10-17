#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
void read(int& a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int min(int a,int b){
	return a<b?a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=500000;
const int Inf=0x3f3f3f3f;
int head[Maxn+5],arrive[Maxn<<1|5],nxt[Maxn<<1|5],val[Maxn<<1|5],tot;
void add_edge(int from,int to,int col){
	arrive[++tot]=to;
	nxt[tot]=head[from];
	val[tot]=col;
	head[from]=tot;
}
bool vis[Maxn+5];
int f[Maxn+5][2];
int dis[Maxn+5];
int n,m;
queue<int> q;
int main(){
	read(n),read(m);
	if(n==1){
		puts("0");
		puts("0");
		return 0;
	}
	for(int i=1;i<=m;i++){
		int u,v,c;
		read(u),read(v),read(c);
		add_edge(v,u,c);
	}
	memset(f,0x3f,sizeof f);
	memset(dis,0x3f,sizeof dis);
	vis[n]=1;
	dis[n]=0;
	q.push(n);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=head[u];i;i=nxt[i]){
			int v=arrive[i];
			if(vis[v]){
				continue;
			}
			f[v][val[i]]=min(f[v][val[i]],dis[u]+1);
			if(f[v][0]<Inf&&f[v][1]<Inf){
				vis[v]=1;
				if(f[v][0]<f[v][1]){
					dis[v]=f[v][1];
				}
				else{
					dis[v]=f[v][0];
				}
				q.push(v);
			}
		}
	}
	if(dis[1]>=Inf){
		puts("-1");
	}
	else{
		printf("%d\n",dis[1]);
	}
	for(int i=1;i<=n;i++){
		if(f[i][0]>f[i][1]){
			putchar('0');
		}
		else{
			putchar('1');
		}
	}
	puts("");
	return 0;
}