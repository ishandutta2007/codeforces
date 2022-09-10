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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 57

int n, k, c;

string s;

int t[N];

VI G[N];

vector<string> nms;

int comp[N];

void dfs(int v)
{
	comp[v] = c;

	for(auto it:G[v])
	{
		if(!comp[it])
			dfs(it);
	}
}

void add(int b, int a)
{
	if(a>b)
	{
		swap(a, b);
		--a;
		++b;

		for(int i = a; i < b; ++i)
		{
			G[i].pb(i+1);
			G[i+1].pb(i);
		}
	}
	else
	{
		G[a].pb(b);
		G[b].pb(a);
	}	
	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 0; i < 26; ++i)
	{
		for(int j = 0; j < 26; ++j)
		{
			string q = "";

			q += char('A'+i);
			q += char('a'+j);

			nms.pb(q);
		}
	}

	cin >> n >> k;

	for(int i = 1; i <= n-k+1; ++i)
	{
		cin >> s;

		if(s=="NO")
			t[i] = 1;
	}

	for(int i = 1; i <= n-k+1; ++i)
	{
		if(!t[i])
			continue;

		int j = i;

		while(j<n-k+1 && t[j+1])
			++j;

		if(i+k-1!=j)
		{
			add(i+k-1, j);
		}
		else
		{
			if(i==1)
			{
				add(i+k-2, j);
			}
			
			if(j==n-k+1)
			{
				add(i+k-1, j+1);
			}
		}

		i = j;
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!comp[i])
		{
			++c;
			dfs(i);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << nms[comp[i]] << " ";
	}

}