#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;
const int N = 2e5+10;

int n,m,k,c[N],head[N],top,d[N],vis[N],cnt[N],ss,tt;
struct zs{
	int to,next;
}a[N];
queue<int>q;

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
}

inline void spfa(){
	memset(d,0x7f,sizeof(d));
	d[tt] = 0;
	vis[tt] = 1;
	q.push(tt);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		vis[x] = 0;
		for(int i=head[x];i != -1;i = a[i].next)
			if(d[x]+1 < d[a[i].to]){
				d[a[i].to] = d[x]+1;
				if(!vis[a[i].to])
					vis[a[i].to] = 1 , q.push(a[i].to);
			}
	}
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	int f,t;
	for(int i=1;i <= m;i++)
		scanf("%d%d",&f,&t) , add(t,f);
	scanf("%d",&k);
	for(int i=1;i <= k;i++)
		scanf("%d",&c[i]);
	ss = c[1] , tt = c[k];
	spfa();
	for(int x=1;x <= n;x++)
		for(int i=head[x];i != -1;i = a[i].next)
			if(d[a[i].to] == d[x]+1)
				cnt[a[i].to]++;
	int maxn = 0,minn = 0;
	for(int i=2;i <= k;i++){
		if(d[c[i]]-d[c[i-1]] != -1)
			minn++ , maxn++;
		else if(cnt[c[i-1]] > 1)
			maxn++;
	}
	printf("%d %d\n",minn,maxn);
	return 0;
}