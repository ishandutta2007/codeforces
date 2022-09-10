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

#define N 100007
#define M (1<<17)

int n;

int a[N];

int load[2*M];
int ind[2*M];
int sum[2*M];

multiset<int> S;

ll res;

void insert(int a)
{
	a += M;
	load[a] = inf;
	--sum[a];
	a /= 2;

	while(a>=1)
	{
		if(load[2*a]<=load[2*a+1])
		{
			load[a] = load[2*a];
			ind[a] = ind[2*a];
		}
		else
		{
			load[a] = load[2*a+1];
			ind[a] = ind[2*a+1];
		}

		--sum[a];
		a /= 2;
	}
}	

PII query(int a, int b)
{
	PII res = mp(inf, inf);

	a += M;
	b += M;

	if(res>mp(load[a], ind[a]))
		res = mp(load[a], ind[a]);

	if(res>mp(load[b], ind[b]))
		res = mp(load[b], ind[b]);

	while(a<b-1)
	{
		if(a%2==0 && res>mp(load[a+1], ind[a+1]))
			res = mp(load[a+1], ind[a+1]);

		if(b%2==1 && res>mp(load[b-1], ind[b-1]))
			res = mp(load[b-1], ind[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

int query_sum(int a, int b)
{
	a += M;
	b += M;

	int res = 0;

	res += sum[a];

	if(a!=b)
		res += sum[b];

	while(a<b-1)
	{
		if(a%2==0)
			res += sum[a+1];

		if(b%2==1)
			res += sum[b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
		load[i+M] = a[i];
		ind[i+M] = i;
		sum[i+M] = 1;
		S.insert(a[i]);
	}

	for(int i = n; i < M; ++i)
	{
		load[i+M] = inf;
		ind[i+M] = i;
	}

	for(int i = M-1; i >= 1; --i)
	{
		if(load[2*i]<=load[2*i+1])
		{
			load[i] = load[2*i];
			ind[i] = ind[2*i];
		}
		else
		{
			load[i] = load[2*i+1];
			ind[i] = ind[2*i+1];
		}

		sum[i] = sum[2*i]+sum[2*i+1];
	}

	int last = -1;

	while(!S.empty())
	{
		PII q = query(last+1, n-1);

		if(q.st!=*S.begin())
		{
			res += query_sum(last+1, n-1);
			last = -1;
		}
		else
		{
			res += query_sum(last+1, q.nd);
			last = q.nd;
			S.erase(S.begin());
			insert(q.nd);
		}
	}

	cout << res;
}