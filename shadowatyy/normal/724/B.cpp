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

int n, m, l;

vector<int> row[27];

map<vector<int>, bool> M[27];

vector<int> perm;

bool sprawdz()
{
	for(int i = 1; i <= n; ++i)
	{
		if(M[i].find(perm)==M[i].end())
			return 0;
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			cin >> l;

			row[i].pb(l);
		}

		M[i][row[i]] = 1;
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			for(int k = j+1; k < m; ++k)
			{
				swap(row[i][j], row[i][k]);

				M[i][row[i]] = 1;

				swap(row[i][j], row[i][k]);
			}
		}
	}

	for(int i = 1; i <= m; ++i)
	{
		perm.pb(i);
	}

	if(sprawdz())
	{
		cout << "YES";
		return 0;
	}

	for(int j = 0; j < m; ++j)
	{
		for(int k = j+1; k < m; ++k)
		{
			swap(perm[j], perm[k]);

			if(sprawdz())
			{
				cout << "YES";
				return 0;
			}

			swap(perm[j], perm[k]);
		}
	}

	cout << "NO";
}