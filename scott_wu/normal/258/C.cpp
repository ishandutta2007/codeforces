#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const ll MOD = 1000000007;

int N;
int arr[MAXN];
ll ans;
ll pnum[MAXN];

ll npow (int base, int exp)
{
	ll res = 1, pnum = base;
	if (exp & 1)
		res *= pnum;
	for (int i = 1; (1 << i) <= exp; i++)
	{
		pnum = (pnum * pnum) % MOD;
		if (exp & (1 << i))
			res = (res * pnum) % MOD;
	}
	return res;
}	

void solve (int val)
{
	vector <int> nfac;
	for (int i = 1; i * i <= val; i++)
	{
		if (val % i == 0)
		{
			nfac.push_back (i);
			if (i * i != val)
			{
				nfac.push_back (val / i);
			}
		}
	}
	
	sort (nfac.begin(), nfac.end());
	
	ll res = 1;
	int last = 0;
	for (int i = 1; i < nfac.size(); i++)
	{
		int lo = 0, hi = N - 1;
		while (lo < hi)
		{
			int mid = (lo + hi) / 2;
			if (arr[mid] < nfac[i])
				lo = mid + 1;
			else
				hi = mid;
		}
		
		res = (res * npow (i, lo - last)) % MOD;
		last = lo;
	}
	
	res = (res * ((npow (nfac.size(), N - last) - npow (nfac.size()-1, N - last) + MOD) % MOD)) % MOD;
	ans = (ans + res) % MOD;
}

int main()
{
	ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sort (arr, arr + N);
	
	for (int i = arr[N-1]; i >= 1; i--)
		solve (i);
	
	cout << ans << "\n";
}