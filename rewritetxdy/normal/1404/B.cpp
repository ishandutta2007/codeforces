#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5+20;

int t,n,x,y,dx,dy,head[N],top;
struct osc{
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

int dis = 0,xx;
inline void dfs(int x,int f,int dp){
	if(x == y){
		dis = dp;
		return;
	}
	for(int i=head[x];~i;i = a[i].next)
		if(a[i].to != f)
			dfs(a[i].to,x,dp+1);
}


inline void dfss(int x,int f,int dp){
	if(dp > dis){
		dis = dp;
		xx = x;
	}
	for(int i=head[x];~i;i = a[i].next)
		if(a[i].to != f)
			dfss(a[i].to,x,dp+1);
}

int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d%d",&n,&x,&y,&dx,&dy);
		for(int i=1;i <= n;i++) head[i] = -1; top = 0;
		int f,to;
		for(int i=1;i < n;i++)
			scanf("%d%d",&f,&to) , add(f,to);
		dis = 0;
		dfs(x,0,0);
		if(dis <= dx){
			puts("Alice");
			continue;
		}
		dis = 0;
		dfss(x,0,0);
		dfss(xx,0,0);
		min(dy,dis) > 2*dx ? puts("Bob") : puts("Alice");
	}
	return 0;
}