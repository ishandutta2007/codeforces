#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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
#define flush fflush(stdout)
using namespace std;

#define N 600007

int n, d;

ll ans;

string t[N];
int s[N];
int c[N];
int pos[N];
int lcp[N];
ll pref_cost[N];
int cost[N];
int lewo[N];
int prawo[N];
int dlugosc[N];
PII cmp[N];

VI sa;

inline bool comp(int a, int b)
{
	return cmp[a]<cmp[b];
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		s[++d] = 256+d;

		for(int j = 0; j < t[i].size(); ++j)
		{
			s[++d] = t[i][j];
			dlugosc[d] = t[i].size()-j;
			cost[d] = c[i];
		}
	}

	for(int i = 1; i <= d; ++i)
	{
		sa.pb(i);
		cmp[i] = mp(s[i], -1);
	}

	for(int l = 1; l <= 2*d; l *= 2)
	{
		sort(ALL(sa), comp);

		for(int i = 0; i < d; ++i)
		{
			if(i>0 && cmp[sa[i-1]]==cmp[sa[i]])
				pos[sa[i]] = pos[sa[i-1]];
			else
				pos[sa[i]] = i;
		}

		for(int i = 1; i <= d; ++i)
		{
			if(i+l<=d)
				cmp[i] = mp(pos[i], pos[i+l]);
			else
				cmp[i] = mp(pos[i], -1);
		}
	}

	int curr = 0;

	for(int i = 1; i <= d; ++i)
	{
		if(pos[i]==d-1)
		{
			curr = max(--curr, 0);
			continue;
		}

		while(i+curr<=d && sa[pos[i]+1]+curr<=d && s[i+curr]==s[sa[pos[i]+1]+curr])
			++curr;

		lcp[pos[i]] = curr;
		curr = max(--curr, 0);
	}

	for(int i = 0; i < d; ++i)
	{
		pref_cost[i] += cost[sa[i]];
		pref_cost[i+1] += pref_cost[i];
	}

	lewo[0] = -1;

	for(int i = 1; i < d; ++i)
	{
		int j = i-1;

		while(j!=-1 && lcp[j]>=lcp[i])
			j = lewo[j];

		lewo[i] = j;
	}

	prawo[d-1] = d;

	for(int i = d-2; i >= 0; --i)
	{
		int j = i+1;

		while(j!=d && lcp[j]>=lcp[i])
			j = prawo[j];

		prawo[i] = j;
	}

	for(int i = 0; i < d-1; ++i)
	{
		int l = lewo[i]+1;
		int r = prawo[i];

		if(r<d)
			ans = max(ans, (ll)lcp[i]*(pref_cost[r]-(l==0?0:pref_cost[l-1])));

		if(lcp[i]<dlugosc[sa[i]] && (i==0 || lcp[i-1]<dlugosc[sa[i]]))
			ans = max(ans, (ll)dlugosc[sa[i]]*cost[sa[i]]);
	}

	cout << ans;
}