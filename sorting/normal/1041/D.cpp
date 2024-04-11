#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const int N = 2e5 + 7;

pair<long long,long long> p[N];
long long skip[N];

int main ()
{
	long long n, h;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> h;

	cin >> p[0].first >> p[0].second;

	skip[1] += p[0].second - p[0].first;

	long long j = 0, res = 0;

	for(long long i = 1; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;

		while(p[i].first - p[j].first - skip[i] + skip[j] >= h)
		{
			//cout << j << endl;
			//cout << skip[i] - skip[j] + h << " - " << j << endl;
			res = max(res, skip[i] - skip[j] + h);
			j++;
		}
		skip[i+1] = skip[i] + p[i].second - p[i].first;
	}

	if(j != n)
		res = max(res, skip[n] - skip[j] + h);

	cout << res << "\n";

	return 0;
}