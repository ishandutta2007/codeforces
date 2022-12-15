#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;
const int inf = 1e9;

int a[N];
vector<int> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;

	cin >> n >> m;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a+n);

	for(int i = 0; i < m; i++)
	{
		int x1, x2, y;

		cin >> x1 >> x2 >> y;

		if(x1 != 1)
			continue;

		v.push_back(x2);
	}

	sort(v.begin(), v.end());

	a[n] = inf;
	n++;

	int i = 0, j = 0, res = n+m;

	for(; i < n; i++)
	{
		for(; j < v.size(); j++)
			if(v[j] >= a[i])
				break;

		res = min(res, (int)v.size()-j+i);
	}

	cout << res << "\n";

	return 0;
}