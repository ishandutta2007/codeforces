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
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

int k, r;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> k >> r;

	for(int i = 1; i <= 9; ++i)
	{
		if((i*k)%10==r || (i*k)%10==0)
		{
			cout << i;
			return 0;
		}
	}

	cout << 10;

}