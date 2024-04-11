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

#define N 1000007

int n, c, a, b;

VI L[N];
VI R[N];
VI TL[N];
VI TR[N];
int Lans[N];
int Rans[N];

int max_l[N];
int min_r[N];
int max_v[N];
int min_v[N];

string s;

void dfs(int v)
{
	max_l[v] = -inf;
	min_r[v] = inf;
	max_v[v] = min_v[v] = v;

	for(auto it:L[v])
	{
		dfs(it);
		max_l[v] = max(max_l[v], max_v[it]);
		min_v[v] = min(min_v[v], min_v[it]);
	}

	for(auto it:R[v])
	{
		dfs(it);
		min_r[v] = min(min_r[v], min_v[it]);
		min_v[v] = min(min_v[v], min_v[it]);
	}
}


int znajdz(int a, int b, int l, int r)
{	
	int Max = -1, Min = inf;

	for(int i = min(a, l), j = max(b, r+1); i <= r && j >= l+1; ++i, --j)
	{
		if(i>=a)
		{
			for(auto it:R[i])
			{
				Max = max(Max, it);
			}

			for(auto it:L[i])
			{
				Max = max(Max, it);
			}
		}

		if(j<=b)
		{
			for(auto it:TR[j])
			{
				if(it>=a)
					Min = min(Min, it);
			}

			for(auto it:TL[j])
			{
				if(it>=a)
					Min = min(Min, it);
			}
		}

		if(i>=l && Max<=i)
			return i;

		if(j<=r+1 && Min>=j)
			return j-1;
	}   

	cerr << a << " " << b << " " << l << " " << r << endl;

	return -1;
}


bool build(int v, int a, int b)
{
	max_l[v] = max(max_l[v], a);
	min_r[v] = min(min_r[v], b+1);

	if(a==b)
		return 1;

	if(max_l[v]>min_r[v])
		return 0;

	int k = znajdz(a+1, b, max_l[v], min_r[v]-1);

	if(k==-1)
		return 0;
	else
	{
		if(a+1<=k)
		{
			Lans[v] = a+1;

			if(!build(a+1, a+1, k))
				return 0;
		}

		if(k+1<=b)
		{
			Rans[v] = k+1;

			if(!build(k+1, k+1, b))
				return 0;
		}

		return 1;
	}
}

void read(int v)
{
	if(Lans[v])
		read(Lans[v]);

	cout << v << " ";

	if(Rans[v])
		read(Rans[v]);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> c;

	while(c--)
	{
		cin >> a >> b >> s;

		if(a>=b)
		{
			cout << "IMPOSSIBLE";
			return 0;
		}

		if(s[0]=='R')
		{
			R[a].pb(b);
			TR[b].pb(a);
		}
		else
		{
			L[a].pb(b);
			TL[b].pb(a);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		sort(ALL(L[i])); L[i].erase(unique(ALL(L[i])), L[i].end());
		sort(ALL(R[i])); R[i].erase(unique(ALL(R[i])), R[i].end());
		sort(ALL(TL[i])); TL[i].erase(unique(ALL(TL[i])), TL[i].end());
		sort(ALL(TR[i])); TR[i].erase(unique(ALL(TR[i])), TR[i].end());
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!min_v[i])
			dfs(i);
	}

	if(!build(1, 1, n))
	{
		cout << "IMPOSSIBLE";
		return 0;
	}

	read(1);

}