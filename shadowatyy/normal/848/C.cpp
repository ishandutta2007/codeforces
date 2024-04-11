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

const int N = 1e5+7;
#define S 1400

int n, m;

int a[N];

struct tree
{
	int load[N];

	void insert(int p, int val)
	{
		++p;

		while(p<=n+2)
		{
			load[p] += val;
			p += p&-p;
		}
	}

	ll query(int a, int b)
	{
		++b;
		ll res = 0;

		while(a)
		{
			res -= load[a];
			a -= a&-a;
		}

		while(b)
		{
			res += load[b];
			b -= b&-b;
		}

		return res;
	}
};

tree fen[2][107];

set<int> wyst[N];

int poprz[N];
int nast[N];

void dodaj(int i)
{
	auto it = wyst[a[i]].upper_bound(i);

	if(it==wyst[a[i]].end())
		nast[i] = n+1;
	else
		nast[i] = *it;

	it = wyst[a[i]].lower_bound(i);

	if(it==wyst[a[i]].begin())
		poprz[i] = 0;
	else
		poprz[i] = *prev(it);

	fen[0][i/S].insert(nast[i], i);
	fen[1][i/S].insert(poprz[i], i);
}

void usun(int i)
{
	auto it = wyst[a[i]].upper_bound(i);

	if(it==wyst[a[i]].end())
		nast[i] = n+1;
	else
		nast[i] = *it;

	it = wyst[a[i]].lower_bound(i);

	if(it==wyst[a[i]].begin())
		poprz[i] = 0;
	else
		poprz[i] = *prev(it);

	fen[0][i/S].insert(nast[i], -i);
	fen[1][i/S].insert(poprz[i], -i);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		wyst[a[i]].insert(i);
	}

	for(int i = 1; i <= n; ++i)
	{
		dodaj(i);
	}

	while(m--)
	{
		int t;
		cin >> t;

		if(t==1)
		{		
			int p, x;
			cin >> p >> x;

			if(a[p]==x)
				continue;

			VI akt;

			if(nast[p]!=n+1)
				akt.pb(nast[p]);

			if(poprz[p]!=0)
				akt.pb(poprz[p]);

			auto it = wyst[x].upper_bound(p);

			if(it!=wyst[x].end())
				akt.pb(*it);

			if(it!=wyst[x].begin())
				akt.pb(*prev(it));

			sort(ALL(akt));
			akt.erase(unique(ALL(akt)), akt.end());

			akt.pb(p);

			for(auto it:akt)
				usun(it);

			wyst[a[p]].erase(p);
			a[p] = x;
			wyst[a[p]].insert(p);

			for(auto it:akt)
				dodaj(it);
		}
		else
		{
			int a, b;
			cin >> a >> b;

			ll res = 0;

			for(int i = a; i <= b; ++i)
			{
				if(i%S==0 && i+S-1<=b)
				{		
					res += fen[0][i/S].query(b+1, n+1);
					res -= fen[1][i/S].query(0, a-1);
					i += S-1;
				}
				else
				{
					if(nast[i]>b)
						res += i;

					if(poprz[i]<a)
						res -= i;
				}
			}

			cout << res << endl;
		}
	}
}