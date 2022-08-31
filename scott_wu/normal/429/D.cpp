#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;

int N;
ll yval[MAXN];
vector <pair <ll, ll> > pt;

ll srt (ll cval)
{
	ll lo = 0, hi = 15e8;
	while (lo < hi)
	{
		ll mid = (lo + hi) / 2;
		if (mid * mid >= cval)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

ll solve (int start, int end)
{
	if (start == end)
		return 2e18;
	int mid = (start + end) / 2;
	
	ll val = min (solve (start, mid), solve (mid + 1, end));
	ll csum = srt (val);
	
	pt.clear();
	for (int i = max ((ll) start, mid - csum); i <= min ((ll) end, mid + csum); i++)
		pt.push_back (make_pair (yval[i], i));
	
	sort (pt.begin(), pt.end());
	for (int i = 0; i < pt.size(); i++)
	{
		for (int j = i - 1; j >= 0 && i - j < 10; j--)
		{
			val = min (val, (pt[j].first - pt[i].first) * (pt[j].first - pt[i].first) + (pt[j].second - pt[i].second) * (pt[j].second - pt[i].second));
		}
		for (int j = i + 1; j < pt.size() && j - i < 10; j++)
		{
			val = min (val, (pt[j].first - pt[i].first) * (pt[j].first - pt[i].first) + (pt[j].second - pt[i].second) * (pt[j].second - pt[i].second));
		}
	}
	return val;
}

int main()
{
	ios_base::sync_with_stdio(0);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> yval[i];
		if (i > 0)
			yval[i] += yval[i-1];
	}
	
	cout << solve (0, N - 1) << "\n";
	return 0;
}