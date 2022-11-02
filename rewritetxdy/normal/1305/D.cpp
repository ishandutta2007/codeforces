#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;
const int N = 1100;

int head[N],top,n,vis[N],viss[N],ans;
struct zs{
	int to,next;
}a[N<<1];
queue<int>q;

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
	a[++top].to = f;
	a[top].next = head[t];
	head[t] = top;
}

inline int bfs(int xx){
	memset(viss,0,sizeof(viss));
	q.push(xx);
	viss[xx] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		ans = x;
		for(int i=head[x];i != -1;i = a[i].next)
			if(!vis[a[i].to] && !viss[a[i].to])
				viss[a[i].to] = 1 , q.push(a[i].to);
	}
	return ans;
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d",&n);
	int f,t,m = n >> 1;
	for(int i=1;i < n;i++)	
		scanf("%d%d",&f,&t) , add(f,t);
	for(int k=1;k <= m;k++){
		for(int i=1;i <= n;i++)
			if(!vis[i]){
				int x = bfs(i),y = bfs(x);
				printf("? %d %d\n",x,y);
				fflush(stdout); 
				int r;
				scanf("%d",&r);
				if(r == x){
					printf("! %d\n",x);
					return 0;
				}
				if(r == y){
					printf("! %d\n",y);
					return 0;
				}
				vis[x] = vis[y] = 1;
				break;
			}
	}
	for(int i=1;i <= n;i++)
		if(!vis[i]){
			printf("! %d\n",i);
			return 0;
		}
}