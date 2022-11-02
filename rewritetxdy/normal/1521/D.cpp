#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

int t,n,f[N][2],ans[N][2],d[N],head[N],top,fa[N],pre[N];
struct osc{
	int to,next;
}a[N<<1];
queue<int>q,qq;

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
	a[++top].to = f;
	a[top].next = head[t];
	head[t] = top;
}

inline int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dfs(int x,int faaa){
	pre[x] = faaa;
	if(x != 1 && a[head[x]].next == -1){
		f[x][0] = f[x][1] = 0; return;
	}
//	f[x][0] = f[x][1] = 1e9;
	int w1 = 0,w2 = 0,v1 = 0,v2 = 0,sum = 0;
	for(int i=head[x];~i;i = a[i].next)
		if(a[i].to != faaa){
			dfs(a[i].to,x);
			sum += f[a[i].to][0]+1;
			if(f[a[i].to][0]+1-f[a[i].to][1] > w1)
				w2 = w1 , v2 = v1 , w1 = f[a[i].to][0]+1-f[a[i].to][1] , v1 = a[i].to;
			else if(f[a[i].to][0]+1-f[a[i].to][1] > w2)
				w2 = f[a[i].to][0]+1-f[a[i].to][1] , v2 = a[i].to;
		}
	f[x][0] = sum-w1-w2 , f[x][1] = sum-w1 , ans[x][0] = v1 , ans[x][1] = v2;
}

void dfss(int x,int w){
	for(int i=head[x];~i;i = a[i].next){
		if(a[i].to == pre[x]) continue;
		if((w == 0 && (a[i].to == ans[x][0] || a[i].to == ans[x][1])) || (w == 1 && a[i].to == ans[x][0]))
			fa[find(x)] = find(a[i].to) , d[x]++ , d[a[i].to]++ , dfss(a[i].to,1);
		else q.push(a[i].to) , dfss(a[i].to,0);
	}
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n); for(int i=1;i <= n;i++) head[i] = -1 , fa[i] = i , d[i] = 0; top = 0;
		int fr,to;
		for(int i=1;i < n;i++) scanf("%d%d",&fr,&to) , add(fr,to);
		dfs(1,0); dfss(1,0);
		printf("%d\n",f[1][0]);
		for(int i=1;i <= n;i++) for(int j=d[i];j < 2;j++) qq.push(i);
		int tmp = qq.front(); qq.pop(); qq.push(tmp);
//		assert(0);
		while(!q.empty()){
			int xx = q.front(); q.pop();
			int x = qq.front(); qq.pop();
			int y = qq.front(); qq.pop();
			while(find(x) == find(y)){
				int z = qq.front(); qq.pop();
				qq.push(y); y = z;
			}
			printf("%d %d %d %d\n",xx,pre[xx],x,y);
			fa[find(x)] = find(y);
		}
		while(!qq.empty()) qq.pop();
	}
	return 0;
}