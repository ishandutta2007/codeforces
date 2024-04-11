#include <bits/stdc++.h>
using namespace std;

map<int, int> countPrimes;
int factor[20000000];
int primes[20000000];

void sieve()
{
	for(int i = 2; i < 8000; i+=2)
	{
		if(!primes[i])
		{
			//if(i < 1000)cout << i << endl;
			for(int j = 2*i; j < 16000001; j += i)
			{
				if(!primes[j])
				{
					//if(j == 999999) cout << i << endl;
					primes[j] = 1;
					factor[j] = i;
				}
			}
		}
		if(i == 2) i--;
	}
}

void factorize(int x)
{
	while(x > 1)
	{
		if(factor[x] == 0) factor[x] = x;
		int p = factor[x];
		//cout << p << endl;
		if(!countPrimes.count(p)) countPrimes[p] = 1;
		else countPrimes[p]++;
		while(x % p == 0)
		{
			x /= p;
		}
	}
	//cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<long long> A;
	sieve();
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}
	sort(A.begin(), A.end());
	if(A[0] == A[n - 1])
	{
		cout << -1 << endl;
		return 0;
	}
	long long g = A[0];
	for(int i = 1; i < n; i++)
		g = __gcd(g, A[i]);
	for(int i = 0; i < n; i++)
	{
		A[i] /= g;
		//cout << A[i] << endl;
		factorize(A[i]);
	}
	//cout << "good\n";
	int ans = 0;
	for(auto x : countPrimes)
	{
		//cout << x.first <<  " " << x.second << endl;
		ans = max(ans, x.second);
	}
	cout << n - ans << endl;
	/*for(int i = 0; i < 1002; i++)
	{
		cout << i << " ";
		factorize(i);
	}*/
}