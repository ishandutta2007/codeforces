#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 2e5+10;

int n,k,head[N],d[N],sz[N],top,h[N];
struct qza{
	int to,next;
}a[N << 1];

inline void add(int f,int t){
	a[++top].to = t;
	a[top].next = head[f];
	head[f] = top;
	a[++top].to = f;
	a[top].next = head[t];
	head[t] = top;	
}

void dfs(int x,int f,int dp){
	d[x] = dp , sz[x] = 1;
	for(int i=head[x];i != -1;i = a[i].next)
		if(a[i].to != f)
			dfs(a[i].to,x,dp+1) , sz[x] += sz[a[i].to];
}

inline int cmp(int x,int y){
	return d[x]-sz[x] > d[y]-sz[y];
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&k);
	int f,t;
	for(int i=1;i < n;i++)
		scanf("%d%d",&f,&t) , add(f,t);
	dfs(1,0,1);
	for(int i=1;i <= n;i++) h[i] = i;
	sort(h+1,h+n+1,cmp);
	ll ans = 0;
	for(int i=1;i <= k;i++)
		ans += d[h[i]]-sz[h[i]];
	printf("%lld\n",ans);
}