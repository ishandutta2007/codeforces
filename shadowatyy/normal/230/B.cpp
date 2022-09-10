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
#define mt make_tuple
#define eb emplace_back
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 1000000

int n;

ll l;

set<ll> S;

bitset<N+7> sito;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	sito[1] = 1;

	for(ll i = 2; i <= N; ++i)
	{
		if(!sito[i])
		{
			S.insert(i*i);

			for(ll j = i*i; j <= N; j += i)
			{
				sito[j] = 1;
			}
		}
	}

	cin >> n;

	while(n--)
	{
		cin >> l;

		if(S.find(l)!=S.end())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
		
}