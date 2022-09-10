#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define boost ios_base::sync_with_stdio(false);
#define _boost cin.tie(0);
#define inf 1000000000
#define INF 1000000000000000000LL
#define mod 1000000007
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
#define FORR(x, y, z) for(int x = y; x >= (z); --x)
using namespace std;
#define int long long
VI g[100007];



#undef int
int main()
{
	#define int long long
	boost;
	_boost;

	int n;
	cin >> n;
	FOR(i,1,n-1)
	{
		int var,var1;
		cin >> var >> var1;
		g[var].pb(var1);
		g[var1].pb(var);
	}

	int wyn=0;

	FOR(i,1,n)
	{
		wyn+=g[i].size()*(g[i].size()-1)/2;
	}

	cout << wyn << endl;


    return 0;
}