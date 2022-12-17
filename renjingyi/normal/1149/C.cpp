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
inline int max(int a, int b)
{
	return a > b ? a : b;
}
inline int max(int a, int b, int c)
{
	return a > b && a > c ? a : (b > c ? b : c);
}
inline int max(int a, int b, int c, int d)
{
	return a > b && a > c && a > d ? a : (b > c && b > d ? b : (c > d ? c : d));
}
struct Node
{
	int s, a, b, c, d, e;
	Node(const int &v = 0) : s(v), a(v), b(-v - v), c(-v), d(-v), e(0) {}
}h[maxn << 2];
int sum;
Node merge(const Node &l, const Node &r)
{
	Node ret;
	ret.s = l.s + r.s;
	ret.a = max(l.a, r.a + l.s);
	ret.b = max(l.b, r.b - 2 * l.s);
	ret.c = max(l.c, r.c - l.s, l.a + r.b - 2 * l.s);
	ret.d = max(l.d, r.d - l.s, l.b + r.a + l.s);
	ret.e = max(l.e, r.e, l.c + r.a + l.s, l.a + r.d - l.s);
	return ret;
}
int query(const int &l, const int &r)
{
	Node ansl, ansr;
	bool getl = 0, getr = 0;
	for(int s = l + sum - 1, t = r + sum + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
	{
		if(~s & 1)
		{
			if(!getl)
			{
				ansl = h[s ^ 1];
				getl = 1;
			}
			else
				ansl = merge(ansl, h[s ^ 1]);
		}
		if(t & 1)
		{
			if(!getr)
			{
				ansr = h[t ^ 1];
				getr = 1;
			}
			else
				ansr = merge(h[t ^ 1], ansr);
		}
	}
	if(!getl)
		return ansr.e;
	if(!getr)
		return ansl.e;
	return merge(ansl, ansr).e;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(sum = 1; sum < n + n; sum <<= 1);
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i ++)
		h[sum + i + 1] = Node(s[i] == '(' ? 1 : -1);
	for(int i = sum - 1; i; i --)
		h[i] = merge(h[i << 1], h[i << 1 | 1]);
	cout << query(1, n + n - 2) << endl;
	while(q --)
	{
		int a, b;
		cin >> a >> b;
		swap(h[sum + a], h[sum + b]);
		for(int i = sum + a >> 1; i; i >>= 1)
			h[i] = merge(h[i << 1], h[i << 1 | 1]);
		for(int i = sum + b >> 1; i; i >>= 1)
			h[i] = merge(h[i << 1], h[i << 1 | 1]);
		cout << query(1, n + n - 2) << '\n';
	}
	
	return 0;
}