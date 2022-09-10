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

int R, C, res;

char t[107][107];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> R >> C;

	for(int i = 1; i <= R; ++i)
	{
		for(int j = 1; j <= C; ++j)
		{
			cin >> t[i][j];
		}
	}

	for(int i = 1; i <= C; ++i)
	{
		if(t[R][i]=='B' && (t[R][i-1]=='.' || t[R][i-1]==0))
			++res;
	}

	cout << res;
}