#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 7;

long long a[N], a2[N];
map<long long, long long> mp;
long long res = 0;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long k, b, n;
	long long zero = 0;

	cin >> k >> b >> n;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	mp[0] = 1;

	for(int i = 1; i <= n; i++)
		if(a[i] == 0)
			a2[i] = a2[i-1] + 1;
		else
			a2[i] = 0;

	for(int i = 1; i <= n; i++)
		zero += a2[i];

	//cout << zero << "\n";

	if(b == 0)
	{
		cout << zero << "\n";

		return 0;
	}

	long long curr = 0;

	for(int i = 1; i <= n; i++)
	{
		curr += a[i];
		curr %= (k-1);

		long long exp = curr + (k-1) - b;
		exp %= (k-1);

		res += mp[exp];

		mp[curr]++;
	}

	if(b == k-1)
		res -= zero;

	cout << res << "\n";

	return 0;
}