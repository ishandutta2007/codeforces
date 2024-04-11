#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
using namespace std;
struct edge
{
	int u, v;
	edge *next;
}p[maxn << 1], *h[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[u], h[u] = n1;
}
int d[maxn], fl = 1;
int q[maxn], fr = 0, ed = 0;
int dep[maxn], cnt[maxn];
bool inq[maxn];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		d[u]++, d[v]++;
		addedge(u, v), addedge(v, u);
	}
	memset(dep, 0, sizeof(dep));
	for(int i = 1; i <= n; i++)
		if(d[i] == 1)
			q[ed++] = i;
	while(fr < ed)
	{
		inq[q[fr]] = 1;
	//	cout<<"Q"<<q[fr]<<endl;
		for(edge *p = h[q[fr]]; p; p = p->next)
			if(inq[p->v]) continue;
			else
			{
				if(cnt[p->v] && dep[p->v] != dep[q[fr]] + 1)
					fl = 0;
				dep[p->v] = dep[q[fr]] + 1;
				cnt[p->v]++;
				d[p->v]--;
				if(d[p->v] == 1)
					q[ed++] = p->v;
			}
		fr++;
	}
	if(ed != n) fl = 0;
	for(int i = 1; i <= n; i++)
		if(dep[i] && cnt[i] < 3) fl = 0;//, cout<<"WA"<<" "<<i<<endl;
		
	int mxs = 0;
	for(int i = 1; i <= n; i++)
		mxs = max(mxs, dep[i]);
	if(mxs != k) fl = 0;
	if(fl)
		printf("YES\n");
	else printf("NO\n");
	return 0;
}