#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 606;

int n,m,head[N],top,d[N],vis[N],ans[N][N],tmp[N];
struct qwq{
	int to,next,v;
}a[N*N];

inline void add(int f,int t,int v){
	a[++top].to = t;
	a[top].v = v;
	a[top].next = head[f];
	head[f] = top;
}

inline void dij(int s){
	for(int i=0;i < n;i++) d[i] = 1e9+1000 , vis[i] = 0;
	d[s] = 0;
	for(int t=1;t <= n;t++){
		int minn = 1e9+1000,x;
		for(int i=0;i < n;i++) if(!vis[i] && d[i] < minn) minn = d[i] , x = i;
		vis[x] = 1;
		for(int i=0;i < n;i++) tmp[i] = 1e9+1000;
		for(int i=head[x];~i;i = a[i].next){
			int cur = (d[x]+a[i].to)%n;
			tmp[cur] = min(tmp[cur],d[x]+a[i].v);
		}
		for(int i=0;i < n*2;i++) tmp[(i+1)%n] = min(tmp[(i+1)%n],tmp[i%n]+1);
		for(int i=0;i < n;i++) d[i] = min(d[i],tmp[i]);
	}
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	for(int i=1;i <= m;i++){
		int fr,to,v;
		scanf("%d%d%d",&fr,&to,&v);
		add(fr,to,v);
	}
	for(int i=0;i < n;i++) dij(i) , memcpy(ans[i],d,sizeof(d));
	
	for(int i=0;i < n;i++) for(int j=0;j < n;j++) 
		printf("%d%c",ans[i][j],j+1 == n ? '\n' : ' ');
	
}