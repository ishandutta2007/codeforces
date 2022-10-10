#include<bits/stdc++.h>
using namespace std;

long long sums[200005];
vector<pair<int, int>> segments;
int n, h;

long long good(int start, int end)
{
	long long len = segments[end].second - segments[start].first;
	long long free;
	if(start == 0) free = sums[end];
	else free = sums[end] - sums[start - 1];
	return h - len + free;
}

long long bs(int start)
{
	int low = start, high = n - 1;
	while(low < high)
	{
		int mid = (low + high + 1)/2;
		if(good(start, mid) > 0) low = mid;
		else high = mid - 1;
	}
	return segments[low].second + good(start, low) - segments[start].first;
}

int main()
{
	cin >> n >> h;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		segments.push_back({x, y});
		if(i == 0) sums[i] = y - x;
		else sums[i] = sums[i - 1] + y - x;
	}
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans, bs(i));
		//cout << bs(i) << endl;
	}
	cout << ans << endl;
}