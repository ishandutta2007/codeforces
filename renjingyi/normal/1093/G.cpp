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
#define mp(a, b) make_pair(a, b)
using namespace std;
typedef pair<int, int> pp;
const int maxn = 2e5 + 5, maxk = 5;
const int oo = 1e9;
int h[maxn << 2][1 << maxk];
int sum, n, k;
void input(const int &p)
{
	for(int i = 0; i < (1 << k); i ++)
		h[sum + p][i] = 0;
	for(int i = 0; i < k; i ++)
	{
		int x;
		cin >> x;
		for(int j = 0; j < (1 << k); j ++)
			h[sum + p][j] += j >> i & 1 ? x : -x;
	}
}
int tmp[1 << maxk];
int query(const int &l, const int &r)
{
	for(int i = 0; i < (1 << k); i ++)
		tmp[i] = -oo;
	for(int s = l + sum - 1, t = r + sum + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
		for(int i = 0; i < (1 << k); i ++)
		{
			if(~s & 1)
				tmp[i] = max(tmp[i], h[s ^ 1][i]);
			if(t & 1)
				tmp[i] = max(tmp[i], h[t ^ 1][i]);
		}
	int tot = (1 << k) - 1;
	int mx = -oo;
	for(int i = 0; i < (1 << k); i ++)
		mx = max(mx, tmp[i] + tmp[tot ^ i]);
	return mx;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for(sum = 1; sum < n + 2; sum <<= 1);
	for(int i = 1; i <= n; i ++)
		input(i);
	for(int i = sum - 1; i; i --)
		for(int j = 0; j < (1 << k); j ++)
			h[i][j] = max(h[i << 1][j], h[i << 1 | 1][j]);
	int q;
	cin >> q;
	while(q --)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int x;
			cin >> x;
			input(x);
			for(int i = sum + x >> 1; i; i >>= 1)
				for(int j = 0; j < (1 << k); j ++)
					h[i][j] = max(h[i << 1][j], h[i << 1 | 1][j]);
		}
		else if(op == 2)
		{
			int l, r;
			cin >> l >> r;
			cout << query(l, r) << endl;
		}
	}
	
	return 0;
}