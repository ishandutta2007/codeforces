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
const int maxn = 1e5 + 5;
int h[maxn << 2];
int sum;
int a[maxn];
int merge(const int &x, const int &y)
{
	return a[x] > a[y] ? x : y;
}
int query(const int &l, const int &r)
{
	int ans = 0;
	for(int s = l + sum - 1, t = r + sum + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
	{
		if(~s & 1)
			ans = merge(ans, h[s ^ 1]);
		if(t & 1)
			ans = merge(ans, h[t ^ 1]);
	}
	return ans;
}
int du[maxn], to[maxn];
long long t[maxn], s[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(sum = 1; sum < n + 2; sum <<= 1);
	for(int i = 1; i < n; i ++)
	{
		cin >> a[i];
		h[sum + i] = i;
	}
	a[n] = n + 1;
	h[sum + n] = n;
	for(int i = sum - 1; i; i --)
		h[i] = merge(h[i << 1], h[i << 1 | 1]);
	for(int i = 1; i < n; i ++)
	{
		to[i] = query(i + 1, a[i]);
		du[to[i]] ++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i ++)
		if(du[i] == 0)
			q.push(i);
	long long ans = 0;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		if(p == n)
			break;
		t[p] ++;
		s[p] += t[p];
		ans += (to[p] - p) * s[p];
		ans -= (a[p] - to[p]) * t[p];
		t[to[p]] += t[p];
		s[to[p]] += s[p];
		if(!-- du[to[p]])
			q.push(to[p]);
	}
	cout << ans << endl;
	
	return 0;
}