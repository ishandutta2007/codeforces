#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
using namespace std;

#define N 2*1007

int n, a, b;

string s1[N], s2[N];

vector<int> G[N];
vector<int> T[N];

bitset<N> vis;

int val[N];

vector<int> post;

void dfs_rev(int v)
{
	vis[v] = 1;

	for(int i = 0; i < T[v].size(); ++i)
	{
		if(!vis[T[v][i]])
		{
			dfs_rev(T[v][i]);
		}
	}

	post.pb(v);
}

void dfs_mark(int v)
{
	vis[v] = 1;
	val[v] = (!vis[v^1]);

	for(int i = 0; i < G[v].size(); ++i)
	{
		if(!vis[G[v][i]])
		{
			dfs_mark(G[v][i]);
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; ++i)
    {
    	cin >> s1[i] >> s2[i];
    }

    for(int i = 1; i <= n; ++i)
    {
    	for(int j = 1; j <= n; ++j)
    	{
    		if(i==j)
    			continue;

    		a = 2*i;
    		b = 2*j;

    		if(s1[i].substr(0, 2)+s2[i].substr(0, 1)==s1[j].substr(0, 2)+s2[j].substr(0, 1))
    		{
    			G[a^1].pb(b);
    			T[b].pb(a^1);
    		}

    		if(s1[i].substr(0, 2)+s2[i].substr(0, 1)==s1[j].substr(0, 3))
    		{
    			G[a^1].pb(b^1);
    			T[b^1].pb(a^1);
    		}

    		if(s1[i].substr(0, 3)==s1[j].substr(0, 2)+s2[j].substr(0, 1))
    		{
    			G[a].pb(b);
    			T[b].pb(a);
    		}

    		if(s1[i].substr(0, 3)==s1[j].substr(0, 3))
    		{
    			G[a].pb(a^1);
    			T[a^1].pb(a);
    		}
    	}
    }

    for(int i = 2; i <= 2*n+1; ++i)
    {
    	if(!vis[i])
    		dfs_rev(i);
    }

    for(int i = 2; i <= 2*n+1; ++i)
    {
    	vis[i] = 0;
    }

    for(int i = 2*n-1; i >= 0; --i)
    {
    	if(!vis[post[i]])
    	{
    		dfs_mark(post[i]);
    	}
    }

    for(int i = 2; i <= 2*n+1; ++i)
    {
    	for(int j = 0; j < G[i].size(); ++j)
    	{
    		if(val[i] && !val[G[i][j]])
    		{
    			cout << "NO";
    			return 0;
    		}
    	}
    }

    cout << "YES\n";

    for(int i = 1; i <= n; ++i)
    {
    	if(val[2*i])
            cout << s1[i].substr(0, 3) << endl;
		else
        	cout << s1[i].substr(0, 2)+s2[i].substr(0, 1) << endl;
    }
}