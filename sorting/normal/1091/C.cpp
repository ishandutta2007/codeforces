#include <bits/stdc++.h>

using namespace std;

map<long long, bool> mp;
long long n;

void add_mp(long long k)
{
	long long res = n*(k-1)/2 + k;

	mp[res] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(long long i = 1; i*i <= n; i++)
		if(n % i == 0)
		{
			add_mp(i);
			add_mp(n/i);
		}

	for(pair<long long, long long> p: mp)
		cout << p.first << " ";
	cout << "\n";

	return 0;
}