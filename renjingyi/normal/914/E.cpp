#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <complex>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int maxn = 2e5 + 5;
struct Edge
{
	int to, next;
}edges[maxn << 1];
int te = 1;
int points[maxn];
void adde(const int &a, const int &b)
{
	te ++;
	edges[te].to = b;
	edges[te].next = points[a];
	points[a] = te;
}
int c[maxn];
bool mark[maxn];
int t[maxn], mx[maxn];
void getr(const int &p, const int &fa, const int &s, int &root)
{
	t[p] = 1;
	mx[p] = 0;
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to] && edges[e].to != fa)
		{
			getr(edges[e].to, p, s, root);
			t[p] += t[edges[e].to];
			mx[p] = max(mx[p], t[edges[e].to]);
		}
	mx[p] = max(mx[p], s - t[p]);
	//cout << "getr : " << p << " " << fa << " " << s << " " << t[p] << " " << mx[p] << " " << root << endl;
	if(mx[p] < mx[root])
		root = p;
}
int cnt[1 << 20];
void add(const int &p, const int &fa, const int &now, const int &v)
{
	//cout << "add : " << p << " " << fa << " " << now << " " << v << endl;
	int next = now ^ c[p];
	cnt[next] += v;
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to] && edges[e].to != fa)
			add(edges[e].to, p, next, v);
}
long long ans[maxn];
long long calc(const int &p, const int &fa, const int &now)
{
	int next = now ^ c[p];
	long long tmp = cnt[next];
	for(int i = 0; i < 20; i ++)
		tmp += cnt[next ^ (1 << i)];
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to] && edges[e].to != fa)
			tmp += calc(edges[e].to, p, next);
	ans[p] += tmp;
	return tmp;
}
void solve(const int &p, const int &s)
{
	mark[p] = 1;
	add(p, 0, 0, 1);
	long long tmp = cnt[0] + 1;
	for(int i = 0; i < 20; i ++)
		tmp += cnt[1 << i];
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to])
		{
			if(t[edges[e].to] > t[p])
				t[edges[e].to] = s - t[p];
			add(edges[e].to, p, c[p], -1);
			tmp += calc(edges[e].to, p, 0);
			add(edges[e].to, p, c[p], 1);
		}
	add(p, 0, 0, -1);
	ans[p] += tmp / 2;
	for(int e = points[p]; e; e = edges[e].next)
		if(!mark[edges[e].to])
		{
			int sum = t[edges[e].to], root = 0;
			getr(edges[e].to, p, sum, root);
			solve(root, sum);
		}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		cin >> a >> b;
		adde(a, b);
		adde(b, a);
	}
	for(int i = 1; i <= n; i ++)
	{
		char x;
		cin >> x;
		c[i] = (1 << x - 'a');
	}
	mx[0] = n;
	int root = 0;
	getr(1, 0, n, root);
	solve(root, n);
	for(int i = 1; i <= n; i ++)
		cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}