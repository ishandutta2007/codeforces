#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
const int oo = 1e9;
int h[maxn << 2];
int sum;
int query(const int &l, const int &r)
{
	int ans = oo;
	for(int s = l + sum - 1, t = r + sum + 1; s ^ t ^ 1; s >>= 1, t >>= 1)
	{
		if(~s & 1)
			ans = min(ans, h[s ^ 1]);
		if(t & 1)
			ans = min(ans, h[t ^ 1]);
	}
	return ans;
}
int a[maxn], b[maxn];
vector<int> pos[maxn];
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t --)
	{
		int n;
		cin >> n;
		for(sum = 1; sum < n + 2; sum <<= 1);
		for(int i = 1; i <= n; i ++)
			cin >> a[i];
		for(int i = 1; i <= n; i ++)
			cin >> b[i];
		for(int i = n; i >= 1; i --)
			pos[a[i]].push_back(i);
		for(int i = 1; i <= n; i ++)
			h[sum + i] = a[i];
		for(int i = sum - 1; i; i --)
			h[i] = min(h[i << 1], h[i << 1 | 1]);
		bool boom = 0;
		for(int i = 1; i <= n; i ++)
		{
			int ttt = pos[b[i]].size();
			if(ttt == 0)
			{
				boom = 1;
				break;
			}
			int p = pos[b[i]][ttt - 1];
			pos[b[i]].pop_back();
			if(query(1, p) < b[i])
			{
				boom = 1;
				break;
			}
			h[sum + p] = oo;
			for(int j = sum + p >> 1; j; j >>= 1)
				h[j] = min(h[j << 1], h[j << 1 | 1]);
		}
		for(int i = 1; i <= n; i ++)
			pos[i].clear();
		cout << (boom ? "NO" : "YES") << '\n';
	}
	
	return 0;
}