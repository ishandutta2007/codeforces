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

#define N 100007
#define typ pair<pair<ull, ull>, ull>

int n, c, curr, best, ans = -1;

int a[N];
int b[N];

VI G[N];

int out[N];

queue<int> Q;

ull hab[N];
ull hba[N];

map<typ, ull> M;
map<int, int> sub;

bitset<N> vis;

void dfs1(int v)
{
	vis[v] = 1;

	for(auto it:G[v])
	{
		if(it>0)
		{
			if(!vis[b[it]])
			{
				dfs1(b[it]);

				if(++sub[hab[it]]==1)
					++curr;
			}
		}
		else
		{
			if(!vis[a[-it]])
			{
				dfs1(a[-it]);

				if(++sub[hba[-it]]==1)
					++curr;
			}
		}
	}
}

void dfs2(int v)
{
	vis[v] = 1;

	if(curr>ans)
	{
		ans = curr;
		best = v;
	}

	for(auto it:G[v])
	{
		if(it>0)
		{
			if(!vis[b[it]])
			{
				if(--sub[hab[it]]==0)
					--curr;

				if(++sub[hba[it]]==1)
					++curr;

				dfs2(b[it]);

				if(++sub[hab[it]]==1)
					++curr;

				if(--sub[hba[it]]==0)
					--curr;
			}
		}
		else
		{
			if(!vis[a[-it]])
			{
				if(--sub[hba[-it]]==0)
					--curr;

				if(++sub[hab[-it]]==1)
					++curr;

				dfs2(a[-it]);

				if(++sub[hba[-it]]==1)
					++curr;

				if(--sub[hab[-it]]==0)
					--curr;
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i < n; ++i)
	{
		cin >> a[i] >> b[i];
		G[a[i]].pb(i);
		G[b[i]].pb(-i);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(G[i].size()==1)
		{
			Q.push(i);
			vis[i] = 1;
		}
	}

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();
		vis[v] = 0;

		typ h;
		h.st.st = h.st.nd = h.nd = 0;

		if(out[v]+1==G[v].size())
		{	
			int e;

			for(auto i:G[v])
			{
				if(i>0)
				{
					if(hab[i]==0)
						e = i;
					else
					{
						h.st.st ^= hab[i];
						h.st.nd += hab[i]*hab[i];
						h.nd += hab[i]*hab[i]*hab[i];
					}
				}
				else
				{
					if(hba[-i]==0)
						e = i;
					else
					{
						h.st.st ^= hba[-i];
						h.st.nd += hba[-i]*hba[-i];
						h.nd += hba[-i]*hba[-i]*hba[-i];
					}
				}
			}

			if(M.find(h)==M.end())
				M[h] = ++c;

			if(e>0)
			{
				hba[e] = M[h];

				if(++out[b[e]]+1>=G[b[e]].size() && !vis[b[e]])
				{
					Q.push(b[e]);
					vis[b[e]] = 1;
				}
			}
			else
			{
				hab[-e] = M[h];

				if(++out[a[-e]]+1>=G[a[-e]].size() && !vis[a[-e]])
				{
					Q.push(a[-e]);
					vis[a[-e]] = 1;
				}
			}
		}
		else
		{
			for(auto i:G[v])
			{
				if(i>0)
				{
					h.st.st ^= hab[i];
					h.st.nd += hab[i]*hab[i];
					h.nd += hab[i]*hab[i]*hab[i];
				}
				else
				{
					h.st.st ^= hba[-i];
					h.st.nd += hba[-i]*hba[-i];
					h.nd += hba[-i]*hba[-i]*hba[-i];
				}
			}

			for(auto i:G[v])
			{
				if(i>0)
				{
					h.st.st ^= hab[i];
					h.st.nd -= hab[i]*hab[i];
					h.nd -= hab[i]*hab[i]*hab[i];

					if(M.find(h)==M.end())
						M[h] = ++c;

					if(!hba[i])
					{
						hba[i] = M[h];

						if(++out[b[i]]+1>=G[b[i]].size() && !vis[b[i]])
						{
							Q.push(b[i]);
							vis[b[i]] = 1;
						}
					}
						
					h.st.st ^= hab[i];
					h.st.nd += hab[i]*hab[i];
					h.nd += hab[i]*hab[i]*hab[i];
				}
				else
				{
					h.st.st ^= hba[-i];
					h.st.nd -= hba[-i]*hba[-i];
					h.nd -= hba[-i]*hba[-i]*hba[-i];

					if(M.find(h)==M.end())
						M[h] = ++c;

					if(!hab[-i])
					{
						hab[-i] = M[h];

						if(++out[a[-i]]+1>=G[a[-i]].size() && !vis[a[-i]])
						{
							Q.push(a[-i]);
							vis[a[-i]] = 1;
						}
					}

					h.st.st ^= hba[-i];
					h.st.nd += hba[-i]*hba[-i];
					h.nd += hba[-i]*hba[-i]*hba[-i];
				}
			}
		}
	}

	dfs1(1);
	vis.reset();
	dfs2(1);

	cout << best;
}