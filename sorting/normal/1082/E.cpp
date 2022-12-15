#include<bits/stdc++.h>

using namespace std;

const int N = 5e5 + 7;

int a[N];
int prefix[N], suffix[N];
vector<int> v[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, c;

	cin >> n >> c;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v[a[i]].push_back(i);
	}

	for(int i = 1; i <= n; i++)
	{
		prefix[i] = prefix[i-1];
		if(a[i] == c)
			prefix[i]++;
	}

	for(int i = n; i >= 1; i--)
	{
		suffix[i] = suffix[i+1];
		if(a[i] == c)
			suffix[i]++;
	}

	int res = -N;

	for(int i = 1; i <= N-7; i++)
	{
		if(v[i].empty() || c == i)
			continue;

		int mn = -prefix[v[i][0]-1];

		for(int j = 0; j < v[i].size(); j++)
		{
			int x = v[i][j];

			mn = min(mn, -prefix[x-1]+j);

			int curr = prefix[n] + j+1 - mn - prefix[x];

			//cout << mn << " " << curr << endl;

			res = max(res, curr);
		}
	}

	res = max(res, prefix[n]);

	cout << res << "\n";

	return 0;
}