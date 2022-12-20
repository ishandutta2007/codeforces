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
const int maxn = 5e5 + 5;
bool cmp(const int &a, const int &b)
{
	return a > b;
}
int a[maxn];
int pos[maxn];
long long q1[maxn], q2[maxn];
long long mx[maxn], mn[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	for(int i = 1; i <= n; i ++)
		pos[a[i]] = max(pos[a[i]], i);
	for(int i = n; i >= 0; i --)
		pos[i] = max(pos[i], pos[i + 1]);
	for(int i = 1; i <= n; i ++)
		q1[i] = q1[i - 1] + a[i];
	for(int i = n; i >= 1; i --)
		q2[i] = q2[i + 1] + a[i];
	for(int i = 1; i <= n; i ++)
		mn[i] = 1e9;
	long long tot = q1[n];
	for(int i = 1; i <= n; i ++)
	{
		long long now1 = q1[i], now2 = (long long)i * (i - 1) + (pos[i + 1] > i ? (long long)i * (pos[i + 1] - i) + q2[pos[i + 1] + 1] : q2[i + 1]);
		if(now1 - i <= now2)
			mx[i] = pos[i + 1] > i ? pos[i + 1] + now2 + i - now1 : i + now2 + i - now1;
		if(now1 - now2 <= i)
			mn[i] = now1 - now2;
	}
	q1[0] = 1e9;
	for(int i = 1; i <= n; i ++)
		q1[i] = min(q1[i - 1], mx[i]);
	for(int i = n; i >= 0; i --)
		q2[i] = max(q2[i + 1], mn[i]);
	bool get = 0;
	for(int i = 0; i <= n; i ++)
	{
		if((i + tot) % 2 == 0 && q1[i] >= i && q2[i] <= i)
		{
			get = 1;
			cout << i << " ";
		}
	}
	if(!get)
		cout << -1;
	cout << endl;
	
	return 0;
}