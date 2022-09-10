#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

int n;

bool prime(int q)
{
	for(int i = 2; i*i <= q; ++i)
	{
		if(q%i==0)
			return 0;
	}

	return 1;
}

int solve(int q)
{
	if(prime(q))
		return 1;
	
	if(q%2==0)
		return 2;
	else
	{
		if(q>3 && prime(q-2))
			return 2;
		else
			return 3;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	cout << solve(n);
}