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

int n, res;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	res = n;

	if(res>0)
	{
		cout << res;
		return 0;
	}

	res = max(res, n/10);
	res = max(res, (n-(n%100)+10*(n%10))/10);

	cout << res;
		
}