#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 1505
#define maxm 255010
#define inf 2000000005
using namespace std;
struct edge
{
	int u, v, c;
	edge *rev;
	edge *next;
}pool[maxm * 2], *h[maxn];
int egcnt = 0;
void addedge(int u, int v, int c)
{
	//cout<<"ADE"<<u<<" "<<v<<" "<<c<<endl;
	edge *new1 = &pool[egcnt++];
	new1->u = u, new1->v = v, new1->c = c;
	
	edge *new2 = &pool[egcnt++];
	new2->u = v, new2->v = u, new2->c = 0;
	
	new1->rev = new2, new2->rev = new1;
	new1->next = h[u], h[u] = new1;
	new2->next = h[v], h[v] = new2;
}
int level[maxn], q[maxn], fr, ed;
int s, t;
void bfs()
{
	fr = ed = 0;
	memset(level, -1, sizeof(level));
	level[s] = 1, q[ed++] = s;

	while(fr < ed)
	{
		for(edge *p = h[q[fr]]; p; p = p->next)
		{
			if(!p->c || level[p->v] != -1) continue;
			level[p->v] = level[q[fr]] + 1, q[ed++] = p->v;
		}
		fr++;
	}
}
int dfs(int a, int flow)
{
	if(!flow) return 0;
	if(a == t) return flow;
	int nf = 0;
	for(edge *p = h[a]; p; p = p->next)
	{
		if((level[p->v] != level[a] + 1) || (p->c <= 0)) continue;
		int nflow = dfs(p->v, min(flow - nf, p->c));
		nf += nflow, p->c -= nflow, p->rev->c += nflow;
	}
	if(!nf) level[a] = -1;
	return nf;
}
int dinic()
{
	int ans = 0;
	while(1)
	{
		bfs();
		int nans = dfs(s, inf);
		if(!nans) break;
		ans += nans;
	}
	return ans;
}
int pl[2][205];
int x[55][2][2];
int cnt[2];
int id[2][205];
void push(int x, int y) {
	pl[x][cnt[x]++] = y;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 1; j <= m; j++) {
		cin >> x[j][0][0] >> x[j][1][0] >> x[j][0][1] >> x[j][1][1];
		x[j][0][1]++, x[j][1][1]++;
		for (int k = 0; k < 2; k++)
			for (int l = 0; l < 2; l++)
				push(k, x[j][k][l]);
	}
	for (int i = 0; i < 2; i++)
		if (cnt[i])
			sort(pl[i], pl[i] + cnt[i]);
	s = 1, t = 2;
	int nid = 3;
	for (int j = 0; j < cnt[0] - 1; j++)
		id[0][j] = (nid++), 
		addedge(id[0][j], t, pl[0][j + 1] - pl[0][j]);
	for (int j = 0; j < cnt[1] - 1; j++)
		id[1][j] = (nid++), 
		addedge(s, id[1][j], pl[1][j + 1] - pl[1][j]);
	for (int j = 1; j <= m; j++) {
		int nr = (nid++);
		for (int k = 0; k < cnt[0] - 1; k++)
			if (pl[0][k] >= x[j][0][0] && pl[0][k] < x[j][0][1])
				addedge(nr, id[0][k], inf);
		for (int k = 0; k < cnt[1] - 1; k++)
			if (pl[1][k] >= x[j][1][0] && pl[1][k] < x[j][1][1])
				addedge(id[1][k], nr, inf);
	}
	int fn = dinic();
	cout << fn << endl;
	return 0;
}