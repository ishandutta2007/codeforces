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

ll n, a;

char s;

ll res;

ll t[307];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	t['f'] = 1;
	t['e'] = 2;
	t['d'] = 3;
	t['a'] = 4;
	t['b'] = 5;
	t['c'] = 6;	

	cin >> n >> s;

	a = (n-1)/4;

	n -= 4*a;

	res = 16*a;

	if(n==1 || n==3)
		res += t[s];
	else
		res += t[s]+7;

	cout << res;
}