#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const long long N = 1e5 + 7;
const long long K = 1e3 + 7;

int grundy[N];
vector<pair<int, int> > v[N];
int xorPrefix[N];

int xorRange(int l, int r)
{
	if(l == 0)
		return xorPrefix[r];

	return xorPrefix[r] ^ xorPrefix[l-1];
}

void updateXorPrefix(int pos)
{
	xorPrefix[pos] = xorPrefix[pos-1] ^ grundy[pos];
}

int main ()
{
	int n;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; i++)
	{
		int sum = i + i+1;

		for(int j = i+1; sum <= n; j++)
		{
			v[sum].push_back({i, j});
			sum += j+1;
		}
	}

	int res;

	for(int i = 3; i <= n; i++)
	{
		unordered_set<int> nim;

		for(int j = 0; j < v[i].size(); j++)
		{
			int x = xorRange(v[i][j].first, v[i][j].second);
			nim.insert(x);

			if(x == 0)
				res = v[i][j].second - v[i][j].first + 1;
		}

		grundy[i] = 0;

		while(nim.find(grundy[i]) != nim.end())
			grundy[i]++;

		updateXorPrefix(i);
	}

	if(grundy[n])
		cout << res << "\n";
	else
		cout << "-1\n";

	return 0;
}