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

ll n;

ll t[207];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	t[1] = 2;
	t[2] = 3;

	for(int i = 3; i <= 200; ++i)
	{
		if(t[i-1]<INF)
			t[i] = t[i-1]+t[i-2];
		else
			t[i] = INF+1;
	}

	cin >> n;

	cout << (upper_bound(t+1, t+200, n)-t-1);

}