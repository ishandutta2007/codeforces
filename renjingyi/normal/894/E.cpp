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
const int maxn = 1e6 + 5;
struct Edge
{
	int to, next;
	long long c;
}edges[maxn << 1];
int te = 1;
int points[maxn];
void adde(const int &a, const int &b, const long long &c)
{
	te ++;
	edges[te].to = b;
	edges[te].c = c;
	edges[te].next = points[a];
	points[a] = te;
}
long long s[maxn], q[maxn];
int dfn[maxn], low[maxn];
int dfscnt = 0;
bool inst[maxn];
stack<int> st;
int belong[maxn];
long long tot[maxn];
void tarjan(const int &p)
{
	dfn[p] = low[p] = ++ dfscnt;
	inst[p] = 1;
	st.push(p);
	for(int e = points[p]; e; e = edges[e].next)
	{
		if(!dfn[edges[e].to])
		{
			tarjan(edges[e].to);
			low[p] = min(low[p], low[edges[e].to]);
		}
		else if(inst[edges[e].to])
			low[p] = min(low[p], dfn[edges[e].to]);
	}
	if(dfn[p] == low[p])
	{
		int x;
		do
		{
			x = st.top();
			st.pop();
			inst[x] = 0;
			belong[x] = p;
		}while(x != p);
	}
}
int a[maxn], b[maxn], c[maxn];
long long w[maxn];
bool mark[maxn];
long long dp[maxn];
void work(const int &p)
{
	if(mark[p])
		return;
	mark[p] = 1;
	for(int e = points[p]; e; e = edges[e].next)
	{
		work(edges[e].to);
		dp[p] = max(dp[p], dp[edges[e].to] + edges[e].c);
	}
	dp[p] += tot[p];
}
int main()
{
	std::ios::sync_with_stdio(false);
	using namespace Input;
	int n, m;
	inputnum(n);
	inputnum(m);
	int cnt = 0;
	while(s[cnt] <= 1e9)
	{
		cnt ++;
		s[cnt] = s[cnt - 1] + cnt;
		q[cnt] = q[cnt - 1] + s[cnt];
	}
	for(int i = 1; i <= m; i ++)
	{
		inputnum(a[i]);
		inputnum(b[i]);
		inputnum(c[i]);
		int pos = upper_bound(s, s + cnt + 1, c[i]) - s - 1;
		w[i] = (long long)c[i] * (pos + 1) - q[pos];
		adde(a[i], b[i], c[i]);
	}
	for(int i = 1; i <= n; i ++)
		if(!dfn[i])
			tarjan(i);
	te = 1;
	for(int i = 1; i <= n; i ++)
		points[i] = 0;
	for(int i = 1; i <= m; i ++)
	{
		if(belong[a[i]] == belong[b[i]])
			tot[belong[a[i]]] += w[i];
		else
			adde(belong[a[i]], belong[b[i]], c[i]);
	}
	int ss;
	inputnum(ss);
	ss = belong[ss];
	work(ss);
	cout << dp[ss] << endl;
	
	return 0;
}