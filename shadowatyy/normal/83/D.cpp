#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

const int X = 2e7+7;

int a, b, k, cnt;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int sito[X];

int bez_k[24];

ll ilo[1<<24];

int f(int n, int k)
{
	if(k>100)
	{
		for(int i = 2; i <= n/k; ++i)
		{
			if(i<k && !sito[i])
			{
				for(int j = i; j <= n/k; j += i)
				{
					sito[j] = i;
				} 
			}
		}

		int res = 0;

		for(int i = 1; i <= n/k; ++i)
		{
			if(!sito[i])
				++res;
		}

		return res;
	}
	else
	{
		ilo[0] = 1;

		for(int i = 1; i < 1<<cnt; ++i)
		{
			ilo[i] = bez_k[31-__builtin_clz(i&-i)]*ilo[i^(i&-i)];
			ilo[i] = min(ilo[i], (ll)n+1);
		}

		int res = n/k;

		for(int i = 1; i < 1<<cnt; ++i)
		{
			if(__builtin_popcount(i)%2)
				res -= n/k/ilo[i];
			else
				res += n/k/ilo[i];
		}

		return res;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> a >> b >> k;

	for(int i = 2; i*i <= k; ++i)
	{
		if(k%i==0)
		{
			cout << 0;
			return 0;
		}
	}

	for(int i = 0; i < 25; ++i)
	{
		if(primes[i]<k)
			bez_k[cnt++] = primes[i];
	}

	cout << f(b, k)-f(a-1, k);
}