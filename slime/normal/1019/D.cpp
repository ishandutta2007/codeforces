#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
#define maxn 2005
#define mod 97
using namespace std;
int x[maxn], y[maxn];
int nx[maxn], ny[maxn];
int ex[maxn], ey[maxn];
int num[mod][mod][maxn], cnt[mod][mod];	
struct edge
{
	int u, v;
	edge *next;
}p[8000000], *h[mod][mod];
int egcnt = 0;
void addedge(int u, int v, int x, int y)
{
	edge *n1 = &p[egcnt++];
	n1->u = u, n1->v = v, n1->next = h[x][y], h[x][y] = n1;
}
ll s;
bool check(int a, int b)
{
	if(1ll * nx[a] * ny[b] - 1ll* nx[b] * ny[a] == s) return 1;
	return 0;
}
void otp(int a)
{
	cout<<x[a]<<" "<<y[a]<<endl;
}
int main()
{
	int n;
	scanf("%d", &n);
	scanf("%lld", &s);
	s *= 2;
	for(int i = 0; i < mod; i++)
		for(int j = 0; j < mod; j++)
			for(int k = 0; k < mod; k++)
				for(int l = 0; l < mod; l++)
					if((i * l - j * k - s) % mod) continue;
					else 
						addedge(k, l, i, j);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for(int j = 1; j <= n; j++)
	{
		for(int k = j + 1; k <= n; k++)
		{
			nx[k] = x[k] - x[j], ny[k] = y[k] - y[j];
			ex[k] = nx[k] % mod, ey[k] = ny[k] % mod;
			if(ex[k] < 0) ex[k] += mod;
			if(ey[k] < 0) ey[k] += mod;
			num[ex[k]][ey[k]][cnt[ex[k]][ey[k]]++] = k;
		}
		for(int k = j + 1; k <= n; k++)
		{
			for(edge *p = h[ex[k]][ey[k]]; p; p = p->next)
			{
				for(int i = 0; i < cnt[p->u][p->v]; i++)
					if(check(k, num[p->u][p->v][i]))
					{
						printf("Yes\n");
						otp(j), 
						otp(k), 
						otp(num[p->u][p->v][i]);
						return 0;
					}
			}
		}
		for(int k = j + 1; k <= n; k++)
			cnt[ex[k]][ey[k]]--;
	}
	printf("No\n");
	return 0;
}