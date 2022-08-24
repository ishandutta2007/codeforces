#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 100100;
const ll MOD = 1e9 + 7;

int N;
int arr[MAXN];

pair <int, int> seat[MAXN]; // location, index
int nseat;
int mseat, mloc;

ll cpow (ll base, ll exp) // base ^ exp % MOD
{
	ll res = 1, p = base;
	for (ll i = 0; (1LL << i) <= exp; i++)
	{
		if (exp & (1 << i))
			res = (res * p) % MOD;
		p = (p * p) % MOD;
	}
	return res;
}

ll choose (int n, int k)
{
	ll res = 1;
	for (int i = n; i > n - k; i--)
		res = (res * i) % MOD;
	for (int i = 1; i <= k; i++)
		res = (res * cpow (i, MOD - 2)) % MOD;
	return res;
}

ll solve (int start)
{
	if (mseat == 1 && start == mloc - 1)
		return 0;
	
	int lo = mloc - 1, hi = mloc + 1;
	int clo = seat[mloc].first, chi = seat[mloc].first;
	ll ans = 1;
	
	if (mseat > 1)
	{
		if (start == mloc - 1)
		{
			clo = seat[mloc].first - mseat + 1;
			chi = seat[mloc].first;
			
			if (clo <= seat[lo].first) return 0;
			ans = cpow (2, mseat - 2);
		}
		else
		{
			clo = seat[mloc].first;
			chi = seat[mloc].first + mseat - 1;
			
			if (chi >= seat[hi].first) return 0;
			ans = cpow (2, mseat - 2);
		}
	}
	
	while (lo > 0 || hi < nseat)
	{
		//cout << lo << " " << hi << " " << seat[lo].second << " " << seat[hi].second << "\n";
		if (seat[lo].second > seat[hi].second)
		{
			if (chi >= seat[hi].first || seat[hi].first - clo + 1 > seat[hi].second)
				return 0;
			
			int nhi = seat[hi].first;
			int nlo = seat[hi].first - seat[hi].second + 1;
			if (nlo < 1 || nlo > clo) return 0;
			if (nlo <= seat[lo].first) return 0;
			
			//cout << nlo << " " << nhi << " " << clo << " " << chi << "\n";
			
			ans = (ans * (choose (nhi - nlo - (chi - clo + 1), clo - nlo))) % MOD;
			clo = nlo, chi = nhi;
			hi++;
		}
		else
		{
			if (clo <= seat[lo].first || chi - seat[lo].first + 1 > seat[lo].second)
				return 0;
			
			int nlo = seat[lo].first;
			int nhi = seat[lo].first + seat[lo].second - 1;
			if (nhi > N || nhi < chi) return 0;
			if (nhi >= seat[hi].first) return 0;
			
			//cout << nlo << " " << nhi << " " << clo << " " << chi << "\n";
			
			ans = (ans * (choose (nhi - nlo - (chi - clo + 1), nhi - chi))) % MOD;
			clo = nlo, chi = nhi;
			
			lo--;
		}
	}
	
	//cout << ans << " " << clo << " " << chi << "\n";
	ans = (ans * (choose (N - (chi - clo + 1), clo - 1))) % MOD;
	
	//cout << ans << "\n";
	return ans;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	
	seat[0] = make_pair (0, N + 1);
	nseat = 1;
	
	mseat = 1e9, mloc = -1;
	for (int i = 1; i <= N; i++)
	{
		if (arr[i])
		{
			seat[nseat] = make_pair (i, arr[i]);
			
			if (arr[i] < mseat)
			{
				mseat = arr[i];
				mloc = nseat;
			}
			nseat++;
		}
	}
	
	if (nseat == 1)
	{
		cout << cpow (2, N - 1) << "\n";
		return 0;
	}
	
	seat[nseat] = make_pair (N + 1, N + 2);
	
	cout << (solve (mloc - 1) + solve (mloc)) % MOD << "\n";
	return 0;
}