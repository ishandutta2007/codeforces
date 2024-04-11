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
const int maxn = 1005;
struct rec
{
	int a, b, c, d;
	friend istream &operator>>(istream &in, rec &c)
	{
		in >> c.a >> c.b >> c.c >> c.d;
		return in;
	}
}c[maxn];
bool cmp1(const rec &a, const rec &b)
{
	return a.a < b.a;
}
bool cmp2(const rec &a, const rec &b)
{
	return a.b < b.b;
}
bool work(const int &l, const int &r)
{
	if(l == r)
		return 1;
	sort(c + l, c + r + 1, cmp1);
	int mx = 0;
	for(int i = l; i < r; i ++)
	{
		mx = max(mx, c[i].c);
		if(mx <= c[i + 1].a)
			return work(l, i) & work(i + 1, r);
	}
	sort(c + l, c + r + 1, cmp2);
	mx = 0;
	for(int i = l; i < r; i ++)
	{
		mx = max(mx, c[i].d);
		if(mx <= c[i + 1].b)
			return work(l, i) & work(i + 1, r);
	}
	return 0;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> c[i];
	cout << (work(1, n) ? "YES" : "NO") << endl;
	
	return 0;
}