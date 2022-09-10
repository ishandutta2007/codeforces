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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define N 500007

int n;

string s;

ordered_set<int> S[2*N];

VI sa;

PII cmp[N];
int pos[N];
int lcp[N];
int pref[N];
int prawo[N];

ll res;

bool comp(int a, int b)
{
	return cmp[a]<cmp[b];
}

int query(int a, int b, int k)
{
	if(a>b)
		return 0;

	k += N;

	auto l = S[k].lower_bound(a);
	auto r = S[k].upper_bound(b);

	return (r==S[k].end()?S[k].size():S[k].order_of_key(*r))-(l==S[k].end()?S[k].size():S[k].order_of_key(*l));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		sa.pb(i);
		cmp[i] = mp(s[i], -1);
	}

	for(int l = 1; l <= 2*n; l <<= 1)
	{
		sort(ALL(sa), comp);

		for(int i = 0; i < n; ++i)
		{
			if(i>0 && cmp[sa[i]]==cmp[sa[i-1]])
				pos[sa[i]] = pos[sa[i-1]];
			else
				pos[sa[i]] = i;
		}

		for(int i = 1; i <= n; ++i)
		{
			if(i+l<=n)
				cmp[i] = mp(pos[i], pos[i+l]);
			else
				cmp[i] = mp(pos[i], -1);
		}	
	}

	for(int i = 0; i < sa.size(); ++i)
	{
		pos[sa[i]] = i;
	}

	int curr = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(pos[i]==n-1)
		{
			curr = max(curr-1, 0);
			continue;
		}

		while(i+curr<=n && sa[pos[i]+1]+curr<=n && s[i+curr]==s[sa[pos[i]+1]+curr])
			++curr;

		lcp[i] = curr;
		curr = max(curr-1, 0);
	}

	for(int i = 1; i <= n; ++i)
	{
		pref[i] = pref[i-1];

		if(s[i]=='(')
			++pref[i];
		else
			--pref[i];

		S[pref[i]+N].insert(i);
	}

	pref[n+1] = -inf;
	prawo[n] = n+1;

	for(int i = n-1; i >= 0; --i)
	{
		int j = i+1;

		while(pref[j]>=pref[i])
			j = prawo[j];

		prawo[i] = j;
	}

	for(int i = 1; i <= n; ++i)
	{
		res += query(i, prawo[i-1]-1, pref[i-1]);

		if(pos[i]!=n-1)
			res -= query(i, min(prawo[i-1]-1, i+lcp[i]-1), pref[i-1]);
	}

	cout << res;
}