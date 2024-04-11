#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define maxn 200005
#define ll long long
using namespace std;
int ds[maxn];
int ans[maxn];
bool fl[maxn];
struct edge
{
	int u, v, t;
	edge *next;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v, int t)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->t = t, n1->next = h[u], h[u] = n1;
}
int x[maxn], y[maxn];
int as;	
int n, m, k;
void del(int a, int b)
{
	if(fl[a]) return;
	if(ds[a] >= k) return ;
//	cout<<"DEL"<<a<<" "<<b<<endl;
	as--;
	fl[a] = 1;
	for(edge *p = h[a]; p; p = p->next)
	{
		if(p->t >= b) continue;
		ds[p->v]--;
		del(p->v, b);
	}
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		ds[x[i]]++, ds[y[i]]++;
		addedge(x[i], y[i], i), 
		addedge(y[i], x[i], i);
	}
	as = n;
	for(int i = 1; i <= n; i++)
		if(ds[i] < k)
			del(i, m + 1);
	for(int i = m; i >= 1; i--)
	{
	//	cout<<"!!!"<<i<<" "<<x[i]<<" "<<y[i]<<endl;
		ans[i] = as;
		if(fl[x[i]] || fl[y[i]])
			continue;
		ds[x[i]]--, ds[y[i]]--;
		del(x[i], i), del(y[i], i);
	}
	for(int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	return 0;
}