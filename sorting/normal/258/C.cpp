#include<bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

using namespace std;

const int N = 1e5 + 7;
const long long mod = 1e9 + 7;

long long a[N];
long long res[N];
vector<long long> p, q;

long long fastPow(long long base, long long exp)
{
	//cout << base << " " << exp << " mimi \n";

	if(base == 0)
		return 0;

	if(exp == 0)
		return 1;

	long long res = 1;

	if(exp % 2 == 1)
		res = base;

	long long tmp = fastPow(base, exp/2);

	res *= tmp;
	res %= mod;

	res *= tmp;
	res %= mod;

	return res;
}

int main ()
{
	long long n, maxi;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(long long i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a+n);

	maxi = a[0];

	for(long long i = 1; i < n; i++)
		maxi = max(maxi, a[i]);

	long long res = 0, currRes;

	for(long long i = 1; i <= maxi; i++)
	{
		currRes = 1;

		p.clear();

		for(long long j = 1; j*j <= i; j++)
			if(i % j == 0)
			{
				//cout << tmp << endl;
				p.push_back(j);
				if(j*j != i)
					p.push_back(i / j);

				if(j == 1)
					continue;
			}

		

		p.push_back(maxi + 1);

		sort(p.begin(), p.end());

		q.clear();

		for(long long j2 = 0; j2 < p.size()-1; j2++)
		{
			auto it1 = lower_bound(a, a+n, p[j2]);
			auto it2 = lower_bound(a, a+n, p[j2+1]);

			q.push_back(it2 - it1);
		}

		for(long long j2 = 0; j2 < q.size()-1; j2++)
		{
			//cout << j2+1 << " " << q[j2] << " hello\n";
			currRes *= fastPow(j2+1, q[j2]);
			currRes %= mod;
		}

		//cout << q.back() << " back \n";

		//cout << q.size() << " " << fastPow(q.size(), q.back()) << " hello\n";
		//cout << q.size() << " " << fastPow(q.size() - 1, q.back()) << " hello\n";

		currRes *= (fastPow(q.size(), q.back()) - fastPow(q.size() - 1, q.back())) % mod;
		currRes %= mod;

		res += currRes;
		res %= mod;

		//cout << res << endl;
	}

	while(res < 0)
		res += mod;

	cout << res << "\n";

	return 0;
}