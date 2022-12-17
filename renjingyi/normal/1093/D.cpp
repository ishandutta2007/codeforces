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
const int maxn = 3e5 + 5;
const long long mod = 998244353;
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
int mark[maxn];
int cnt1 = 0, cnt2 = 0;
bool ok = 1;
void work(const int &p, const int &x)
{
	mark[p] = x;
	if(x == 2)
		cnt1 ++;
	else
		cnt2 ++;
	for(int e = points[p]; e; e = edges[e].next)
	{
		if(!mark[edges[e].to])
			work(edges[e].to, x ^ 1);
		else if(mark[edges[e].to] == mark[p])
		{
			ok = 0;
			return;
		}
	}
}
long long ksm(const long long &a, const long long &k)
{
	long long ans = 1;
	for(long long x = a % mod, asd = k; asd; asd >>= 1, (x *= x) %= mod)
		if(asd & 1)
			(ans *= x) %= mod;
	return ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n, m;
		cin >> n >> m;
		for(int i = 1; i <= n; i ++)
			points[i] = mark[i] = 0;
		te = 1;
		cnt1 = cnt2 = 0;
		ok = 1;
		for(int i = 1; i <= m; i ++)
		{
			int a, b;
			cin >> a >> b;
			adde(a, b);
			adde(b, a);
		}
		long long ans = 1;
		for(int i = 1; i <= n; i ++)
			if(!mark[i])
			{
				cnt1 = cnt2 = 0;
				work(i, 2);
				(ans *= ksm(2, cnt1) + ksm(2, cnt2)) %= mod;
			}
		cout << (ok ? ans : 0) << endl;
	}
	
	return 0;
}