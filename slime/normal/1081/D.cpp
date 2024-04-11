#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
using namespace std;
int n, m, k;
struct eg
{
	int u, v, w;
	bool operator < (const eg &x)const
	{
		return w < x.w; 
	}
}p[maxn];
int fl[maxn], fa[maxn], w[maxn];
int gfa(int a)
{
	if(fa[a] == a) return a;
	int nf = gfa(fa[a]);
	w[a] = max(w[a], w[fa[a]]);
	fa[a] = nf;
	return nf;
}
int x[maxn];
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++)
		scanf("%d", &x[i]), 
		fl[x[i]] = 1;
	for(int i = 1; i <= n; i++)
		fa[i] = i, w[i] = 0;
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &p[i].u, &p[i].v, &p[i].w);
	sort(p + 1, p + m + 1);
	for(int i = 1; i <= m; i++)
	{
		int ufa = gfa(p[i].u), vfa = gfa(p[i].v);
		if(ufa == vfa) continue;
		fa[ufa] = vfa;	
		int fls = 1;	
		if(!fl[ufa] || !fl[vfa]) fls = 0;
		fl[vfa] |= fl[ufa];
		if(fls)
			w[vfa] = p[i].w;	
	} 
	for(int i = 0; i < k; i++)
	{
		gfa(x[i]);
		int ns = max(w[x[i]], w[fa[x[i]]]);
		printf("%d ", ns);
	}
	return 0;
}