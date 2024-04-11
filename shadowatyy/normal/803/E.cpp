#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 1007

int n, k;

string s;

bitset<2*N> vis[N];

PII par[N][2*N];

vector<char> res;

void read(int p, int v)
{
	if(p || v)
	{
		if(par[p][v+N].nd>v)
			res.pb('L');
		else if(par[p][v+N].nd<v)
			res.pb('W');
		else
			res.pb('D');

		read(par[p][v+N].st, par[p][v+N].nd);
	}
}

void dfs(int p, int v)
{
	if(p==n)
	{
		if((v==k || v==-k) && res.empty())
			read(p, v);

		return;
	}

	vis[p][v+N] = 1;

	if(s[p+1]=='W' || s[p+1]=='?')
	{
		if(((v+1!=k && v+1!=-k) || p+1==n) && !vis[p+1][v+1+N])
		{
			par[p+1][v+1+N] = mp(p, v);
			dfs(p+1, v+1);
		}
	}

	if(s[p+1]=='L' || s[p+1]=='?')
	{
		if(((v-1!=k && v-1!=-k) || p+1==n) && !vis[p+1][v-1+N])
		{
			par[p+1][v-1+N] = mp(p, v);
			dfs(p+1, v-1);
		}
	}

	if(s[p+1]=='D' || s[p+1]=='?')
	{
		if(((v!=k && v!=-k) || p+1==n) && !vis[p+1][v+N])
		{
			par[p+1][v+N] = mp(p, v);
			dfs(p+1, v);
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> s;

	s = '#'+s;

	dfs(0, 0);

	reverse(ALL(res));

	if(res.empty())
	{
		cout << "NO";
		return 0;
	}

	for(auto it:res)
	{
		cout << it;
	}
}