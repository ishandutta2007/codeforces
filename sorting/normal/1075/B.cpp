#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 7;

pair<long long, bool> p[N];
vector<long long> not_taxi, res, taxi;

long long n, m;

long long count_before(long long x)
{
	long long l = 0, r = n-1, mid;

	if(not_taxi[0] > x)
		return 0;

	while(l != r)
	{
		mid = (l+r+1)/2;

		if(not_taxi[mid] <= x)
			l = mid;
		else
			r = mid - 1;
	}

	return l+1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(long long i = 0; i < n+m; i++)
		cin >> p[i].first;

	for(long long i = 0; i < n+m; i++)
		cin >> p[i].second;

	sort(p, p+n+m);

	for(long long i = 0; i < n+m; i++)
	{
		if(!p[i].second)
		{
			not_taxi.push_back(p[i].first);
		}
		else
			taxi.push_back(p[i].first);
	}

	long long pr = -1, cnt = 0;

	for(long long i = 0; i < m; i++)
	{
		if(i == 0)
		{
			if(i == m-1)
				res.push_back(n);
			else
				res.push_back(count_before( (taxi[i]+taxi[i+1])/2 ) );
		}
		else
		{
			if(i != m-1)
				res.push_back(count_before( (taxi[i]+taxi[i+1])/2 ) - count_before( (taxi[i-1]+taxi[i])/2 ));
			else
				res.push_back(n- count_before( (taxi[i-1]+taxi[i])/2 ));
		}
	}

	for(long long i = 0; i < m; i++)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}