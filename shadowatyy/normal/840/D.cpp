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
#define SIZE(x) (int)(x).size()
using namespace std;

const int N = 3e5+7;

int n, q;

int a[N];

int l[N];
int r[N];
int k[N];

int ile[N];

VI kand[N];

VI freq[N];

VI wyst[N];

void go(VI que, int L, int R)
{
	int mid = (L+R)/2;

	for(int i = mid; i <= R; ++i)
	{
		freq[i] = freq[i-1];
		++ile[a[i]];	

		if(find(ALL(freq[i]), a[i])==freq[i].end())
		{
			if(freq[i].size()<5)
				freq[i].pb(a[i]);
			else
			{
				for(auto &it:freq[i])
				{
					if(ile[it]<ile[a[i]])
					{
						it = a[i];
						break;
					}
				}
			}	
		}
	}

	for(auto it:que)
	{
		if(l[it]<=mid && mid<=r[it])
		{
			kand[it].insert(kand[it].end(), ALL(freq[r[it]]));
		}
	}

	for(int i = mid; i <= R; ++i)
	{
		freq[i].clear();
		--ile[a[i]];
	}

	for(int i = mid; i >= L; --i)
	{
		freq[i] = freq[i+1];
		++ile[a[i]];

		if(find(ALL(freq[i]), a[i])==freq[i].end())
		{
			if(freq[i].size()<5)
				freq[i].pb(a[i]);
			else
			{
				for(auto &it:freq[i])
				{
					if(ile[it]<ile[a[i]])
					{
						it = a[i];
						break;
					}
				}
			}	
		}
	}

	for(auto it:que)
	{
		if(l[it]<=mid && mid<=r[it])
		{
			kand[it].insert(kand[it].end(), ALL(freq[l[it]]));
		}
	}

	for(int i = mid; i >= L; --i)
	{
		freq[i].clear();
		--ile[a[i]];
	}

	VI queL, queR;

	for(auto it:que)
	{
		if(r[it]<mid)
			queL.pb(it);
		else if(l[it]>mid)
			queR.pb(it);
	}

	if(!queL.empty())
		go(queL, L, mid-1);

	if(!queR.empty())
		go(queR, mid+1, R);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		wyst[a[i]].pb(i);
	}

	VI s;

	for(int i = 1; i <= q; ++i)
	{
		cin >> l[i] >> r[i] >> k[i];
		s.pb(i);
	}

	go(s, 1, n);
	//go(s, 15, 18);

	for(int i = 1; i <= q; ++i)
	{
		int res = inf;

		for(auto it:kand[i])
		{
			int cnt = upper_bound(ALL(wyst[it]), r[i])-lower_bound(ALL(wyst[it]), l[i]);

			if(k[i]*cnt>r[i]-l[i]+1)
				res = min(res, it);
		}

		if(res==inf)
			cout << -1 << endl;
		else
			cout << res << endl;
	}
}