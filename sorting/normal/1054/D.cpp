#include<bits/stdc++.h>

using namespace std;

map<long long, long long> Map;

const long long N = 2e5 + 7;

long long a[N];

int main()
{
	long long n, k;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for(long long i = 0; i < n; i++)
		cin >> a[i];

	for(long long i = 1; i < n; i++)
		a[i] ^= a[i-1];

	long long pow_of_two = (1ll<<k)-1ll;

	for(long long i = 0; i < n; i++)
		Map[a[i]]++;

	Map[0]++;

	for(auto it = Map.begin(); it != Map.end(); it++)
	{
		Map[((it->first)^pow_of_two)] += it->second;
		it->second = 0;
	}

	long long res = 0;

	for(auto it = Map.begin(); it != Map.end(); it++)
	{
		long long curr = it->second;
		long long f = curr/2, s = (curr/2) + curr%2;

		//cout << curr << endl;

		res += (f*(f-1)/2) + (s*(s-1)/2);

		//cout << res << " res" << endl;
	}

	cout << (n*(n+1)/2) - res << "\n";

	return 0;
}