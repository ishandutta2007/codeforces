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
#define ALL(c) (c).begin(), (c).end()
using namespace std;

int n, s, res;

int t[37];

bitset<8> vis[307][307][157];

int vx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int vy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bitset<307> w[307];

void solve(int x, int y, int l, int d, int k)
{
	for(int i = 1; i <= t[l]; ++i)
	{
		x += vx[k];
		y += vy[k];

		if(vis[x][y][d][k])
			return;

		vis[x][y][d][k] = 1;

		--d;

		w[x][y] = 1;
	}

	if(l<n)
	{
		solve(x, y, l+1, d, (k-1+8)%8);
		solve(x, y, l+1, d, (k+1)%8);
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];

		s += t[i];
	}

	solve(150, 150, 1, s, 0);

	for(int i = 1; i <= 300; ++i)
	{
		for(int j = 1; j <= 300; ++j)
		{
			if(w[i][j])
				++res;
		}
	}

	cout << res;
}