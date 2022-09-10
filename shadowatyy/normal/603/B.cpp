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

#define N 1000007
#define M 1000000007

int p, k;

int r[N];
int s[N];

int Find(int a)
{
	if(a!=r[a])
		r[a] = Find(r[a]);

	return r[a];
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a!=b)
	{
		s[a] += s[b];
		s[b] = 0;
		r[b] = a;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> p >> k;

	if(k==0)
	{
		ll res = 1;

		for(int i = 1; i < p; ++i)
		{
			res = (res*p)%M;
		}

		cout << res;
		return 0;
	}
	else if(k==1)
	{
		ll res = 1;

		for(int i = 0; i < p; ++i)
		{
			res = (res*p)%M;
		}

		cout << res;
		return 0;
	}

	for(int i = 0; i < p; ++i)
	{
		r[i] = i;
		s[i] = 1;
	}

	for(int i = 0; i < p; ++i)
	{
		Union(i, (ll)k*i%p);
	}

	ll res = 1;

	for(int i = 1; i < p; ++i)
	{
		if(s[i]>0)
			res = (res*p)%M;
	}

	cout << res;
}