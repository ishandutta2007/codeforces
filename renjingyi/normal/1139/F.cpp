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
#define get1(x) (x <= n ? b[x] : f[x - n])
#define get2(x) (x <= n ? b[x] + p[x] : f[x - n] + c[x - n])
#define get3(x) (x <= n ? p[x] - b[x] : c[x - n] - f[x - n])
using namespace std;
const int maxn = 1e5 + 5;
namespace BIT
{
	#define lowbit(x) (x & -x)
	int c[maxn << 1];
	void add(const int &p, const int &n, const int &v)
	{
		for(int i = p; i <= n; i += lowbit(i))
			c[i] += v;
	}
	int query(const int &p)
	{
		int ans = 0;
		for(int i = p; i; i -= lowbit(i))
			ans += c[i];
		return ans;
	}
}
int p[maxn], s[maxn], b[maxn], c[maxn], f[maxn];
map<int, int> id;
int trans[maxn << 1];
int x[maxn << 1], y[maxn << 1];
int n, m, cnt = 0;
int ans[maxn];
bool cmp(const int &aa, const int &bb)
{
	return get1(aa) == get1(bb) ? aa < bb : get1(aa) < get1(bb);
}
void work1(const int &l, const int &r)
{
	if(l == r)
		return;
	int mid = l + r >> 1;
	work1(l, mid);
	work1(mid + 1, r);
	int pos = mid + 1;
	for(int i = l; i <= mid; i ++)
		if(x[i] > n)
		{
			for(; pos <= r && get2(x[pos]) <= get2(x[i]); pos ++)
				if(x[pos] <= n)
					BIT::add(trans[x[pos]], cnt, 1);
			ans[x[i] - n] += BIT::query(trans[x[i]]);
		}
	for(int i = mid + 1; i < pos; i ++)
		if(x[i] <= n)
			BIT::add(trans[x[i]], cnt, -1);
	int pos1 = pos = l, pos2 = mid + 1;
	while(pos1 <= mid && pos2 <= r)
	{
		if(get2(x[pos1]) <= get2(x[pos2]))
			y[pos ++] = x[pos1 ++];
		else
			y[pos ++] = x[pos2 ++];
	}
	while(pos1 <= mid)
		y[pos ++] = x[pos1 ++];
	while(pos2 <= r)
		y[pos ++] = x[pos2 ++];
	for(int i = l; i <= r; i ++)
		x[i] = y[i];
}
void work2(const int &l, const int &r)
{
	if(l == r)
		return;
	int mid = l + r >> 1;
	work2(l, mid);
	work2(mid + 1, r);
	int pos = l;
	for(int i = mid + 1; i <= r; i ++)
		if(x[i] > n)
		{
			for(; pos <= mid && get3(x[pos]) <= get3(x[i]); pos ++)
				if(x[pos] <= n)
					BIT::add(trans[x[pos]], cnt, 1);
			ans[x[i] - n] += BIT::query(trans[x[i]]);
		}
	for(int i = l; i < pos; i ++)
		if(x[i] <= n)
			BIT::add(trans[x[i]], cnt, -1);
	int pos1 = pos = l, pos2 = mid + 1;
	while(pos1 <= mid && pos2 <= r)
	{
		if(get3(x[pos1]) <= get3(x[pos2]))
			y[pos ++] = x[pos1 ++];
		else
			y[pos ++] = x[pos2 ++];
	}
	while(pos1 <= mid)
		y[pos ++] = x[pos1 ++];
	while(pos2 <= r)
		y[pos ++] = x[pos2 ++];
	for(int i = l; i <= r; i ++)
		x[i] = y[i];
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> p[i];
	for(int i = 1; i <= n; i ++)
	{
		cin >> s[i];
		id[s[i]] = 0;
	}
	for(int i = 1; i <= n; i ++)
		cin >> b[i];
	for(int i = 1; i <= m; i ++)
	{
		cin >> c[i];
		id[c[i]] = 0;
	}
	for(int i = 1; i <= m; i ++)
		cin >> f[i];
	for(map<int, int>::reverse_iterator it = id.rbegin(); it != id.rend(); it ++)
		it->second = ++ cnt;
	for(int i = 1; i <= n; i ++)
		trans[i] = id[s[i]];
	for(int i = 1; i <= m; i ++)
		trans[n + i] = id[c[i]];
	for(int i = 1; i <= n + m; i ++)
		x[i] = i;
	sort(x + 1, x + n + m + 1, cmp);
	work1(1, n + m);
	sort(x + 1, x + n + m + 1, cmp);
	work2(1, n + m);
	for(int i = 1; i <= m; i ++)
		cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}