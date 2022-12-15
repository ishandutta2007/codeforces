#include <bits/stdc++.h>

using namespace std;

const int N = 1007;

pair<int, int> p[N], b[N];
map<pair<int, int>, int> mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	for(int i = 0; i < n; i++)
		cin >> b[i].first >> b[i].second;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			pair<int, int> t;

			t.first = p[i].first + b[j].first;
			t.second = p[i].second + b[j].second;

			mp[t]++;
		}

	for(pair< pair<int, int>, int> t: mp)
	{
		if(t.second == n)
		{
			cout << t.first.first << " " << t.first.second << "\n";

			return 0;
		}
	}

	return 0;
}