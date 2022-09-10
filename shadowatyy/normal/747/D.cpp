#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
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

#define N 200007

int n, k, c, res;

int a[N];

int z[N];

multiset<int> S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i]<0)
			a[i] = 1;
		else
			a[i] = 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==1)
			++c;
	}

	if(k<c)
	{
		cout << -1;
		return 0;
	}

	k -= c;

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==0)
			z[i] = z[i-1]+1;
		else
		{
			if(z[i-1] && i-1-z[i-1]!=0)
			{
				S.insert(z[i-1]);
			}
				
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]!=a[i-1])
			++res;
	}

	while(!S.empty() && *S.begin()<=k)
	{
		res -= 2;
		k -= *S.begin();
		S.erase(S.begin());
	}

	if(z[n] && k>=z[n] && z[n]!=n)
		--res;

	cout << res;
}