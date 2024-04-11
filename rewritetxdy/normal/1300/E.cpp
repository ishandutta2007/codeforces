#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1e6+10;
const double eps = 1e-9;

int n,vis[N];

struct zs{
	int l,r,w;
	double v; 
}c[N];

inline void dfs(int i){
	if((c[i].v*c[i].w+c[c[i].r].v*c[c[i].r].w)/(c[i].w+c[c[i].r].w) < c[i].v){
		c[i].v = (c[i].v*c[i].w+c[c[i].r].v*c[c[i].r].w)/(c[i].w+c[c[i].r].w);
		c[i].w = c[i].w+c[c[i].r].w;
		vis[c[i].r] = 1;
		c[i].r = c[c[i].r].r;
		c[c[i].r].l = i;
		if(c[i].r <= n)
			dfs(i);
		if(c[i].l)
			dfs(c[i].l);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i <= n;i++)
		scanf("%lf",&c[i].v),c[i].w = 1,c[i].l = i-1,c[i].r = i+1;
	for(int i=1;i < n;i++)
		if(!vis[i] && c[i].r <= n)
			dfs(i);
	for(int i=1;i <= n;i=c[i].r)
		for(int j=1;j <= c[i].w;j++)
			printf("%.12f\n",c[i].v);
	return 0;
}