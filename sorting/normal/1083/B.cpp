#include<bits/stdc++.h>

using namespace std;

const long long N = 5e5 + 5;

//long long arr[N];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, k;

	cin >> n >> k;

	string s, t;

	cin >> s >> t;

	long long possible = 0, res = 0, first = 0, second = 0;
	long long i = 0;

	for(i = 0; i < n && possible < k; i++)
	{
		first *= 2ll;
		second *= 2ll;

		first += s[i] - 'a';
		second += t[i] - 'a';

		possible = second - first + 1;

		res += min(possible, k);
	}

	i = n - i;

	res += k * i;

	cout << res << "\n";

	return 0;
}