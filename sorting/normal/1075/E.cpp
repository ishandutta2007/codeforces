#include<bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;

pair<long long, long long> p[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> p[i].first >> p[i].second;

	pair<long long, long long> mini, maxi;

	mini = p[0];
	maxi = p[0];

	for(int i = 1; i < n; i++)
	{
		mini.first = min(mini.first, p[i].first);
		mini.second = min(mini.second, p[i].second);

		maxi.first = max(maxi.first, p[i].first);
		maxi.second = max(maxi.second, p[i].second);
	}

	long long res = (maxi.first-mini.first+maxi.second-mini.second)*2;
	long long res2 = 0;

	for(int i = 0; i < n; i++)
		res2 = max(res2, max(abs(maxi.first-p[i].first), abs(p[i].first-mini.first)) + max(abs(maxi.second-p[i].second), abs(p[i].second-mini.second)));

	res2 *= 2;

	cout << res2;

	for(int i = 4; i <= n; i++)
		cout << " " << res;

	cout << "\n";

	return 0;
}