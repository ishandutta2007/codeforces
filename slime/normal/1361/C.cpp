#include <bits/stdc++.h>
using namespace std;
#define maxn 1150010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int st[maxn];
struct edge
{
	int u, v, id;
	edge *nx;
	edge *rev;
	int tp;
}p[maxn * 2], *h[maxn];
int cnt = 0;
void addedge(int u, int v, int id)
{
	edge *new1 = &p[cnt++];
	new1->u = u, new1->v = v, new1->nx = h[u], new1->id = id, h[u] = new1, new1->tp = 0;
	edge *new2 = &p[cnt++];
	new2->u = v, new2->v = u, new2->nx = h[v], new2->id = -id, h[v] = new2, new2->tp = 0;
	new1->rev = new2, new2->rev = new1;
}
int top = 0;
void dfs(int a)
{
	for(; h[a];)
	{
		if(h[a]->tp) 
		{
			h[a] = h[a]->nx;
			continue;
		}
		h[a]->rev->tp = 1;
		int lid = h[a]->id, lv = h[a]->v;
		h[a] = h[a]->nx;
		dfs(lv);
		st[top++] = lid;
	}
}
int n;
int a[maxn], b[maxn];
int d[maxn];
void work(int c) {
	top = 0;
	cnt = 0;
	for (int i = 0; i < maxn; i++) h[i] = NULL;
	int tr = (1 << c) - 1;
	for (int i = 0; i <= tr; i++) d[i] = 0;
	for (int i = 1; i <= n; i++) {
		addedge(a[i] & tr, b[i] & tr, i);
		d[a[i] & tr] ^= 1, 
		d[b[i] & tr] ^= 1;
	}
	for (int i = 0; i <= tr; i++)
		if (d[i]) return ;
	dfs(a[1] & tr);
	if (top != n) return ;
	else {
		cout << c << endl;
		for (int i = top - 1; i >= 0; i--) {
			int q = st[i];
			int id = abs(q);
			if (q >= 0) printf("%d %d ", 2 * id - 1, 2 * id);
			else printf("%d %d ", 2 * id, 2 * id - 1);
		}
		exit(0);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	for (int j = 20; j >= 0; j--)
		work(j);
	return 0;
}