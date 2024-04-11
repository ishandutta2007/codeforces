#include <bits/stdc++.h>
using namespace std;
namespace Input
{
	const int BUF = 1 << 20;
	char buf[BUF + 1];
	char *head = buf, *tail = buf;
	char inputchar()
	{
		if(head == tail)
			*(tail = (head = buf) + fread(buf, 1, BUF, stdin)) = 0;
		return *head ++;
	}
	void inputnum(int &ret)
	{
		char ch = inputchar();
		while(ch < '0' || ch > '9')
			ch = inputchar();
		ret = ch - '0';
		ch = inputchar();
		while(ch >= '0' && ch <= '9')
		{
			ret = ret * 10 + ch - '0';
			ch = inputchar();
		}
	}
}
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
int fa[maxn], t[maxn];
long long dp1[maxn], dp2[maxn];
int n;
void work1(const int &p)
{
	t[p] = 1;
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa[p])
		{
			fa[edges[e].to] = p;
			work1(edges[e].to);
			t[p] += t[edges[e].to];
			dp1[p] += dp1[edges[e].to];
		}
	dp1[p] += t[p];
}
void work2(const int &p)
{
	if(p != 1)
		dp2[p] = dp2[fa[p]] + dp1[fa[p]] - t[fa[p]] - dp1[p] + n - t[p];
	for(int e = points[p]; e; e = edges[e].next)
		if(edges[e].to != fa[p])
			work2(edges[e].to);
}
int main()
{
	std::ios::sync_with_stdio(false);
	using namespace Input;
	inputnum(n);
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		inputnum(a);
		inputnum(b);
		adde(a, b);
		adde(b, a);
	}
	work1(1);
	work2(1);
	long long ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = max(ans, dp1[i] - t[i] + dp2[i] + n);
	cout << ans << endl;
	
	return 0;
}