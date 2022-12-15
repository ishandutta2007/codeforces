#include<bits/stdc++.h>

using namespace std;

const long long N = 1e6 + 7;

pair<long long, long long> a[N];
long long dp[N][3];
long long pr[N];

long long n;

vector<long long> v;

long long fenwick[N];

void update(long long ind, long long val)
{
	for(ind; ind <= n; ind += ind&(-ind))
		fenwick[ind] += val;
}

long long query(long long ind)
{
	long long res = 0;

	for(ind; ind >= 1; ind -= ind&(-ind))
		res += fenwick[ind];

	return res;
}

int main ()
{
	cin >> n;

	for(long long i = 1; i <= n; i++)
	{
		cin >> a[i].first;

		a[i].second = i;
	}

	sort(a+1, a+n+1);

	for(long long i = 1; i <= n; i++)
		dp[i][0] = 1;

	for(long long i = n; i >= 1; i--)
	{
		dp[a[i].second][1] = query(a[i].second);

		update(a[i].second, dp[a[i].second][0]);
	}

	for(long long i = n; i >= 1; i--)
		update(i,-dp[i][0]);

	long long res = 0;

	for(long long i = n; i >= 1; i--)
	{
		res += query(a[i].second);

		update(a[i].second, dp[a[i].second][1]);
	}

	cout << res << "\n";

	return 0;
}