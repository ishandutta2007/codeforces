#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

int u, v, p;

unordered_map<int, int> dist[2], skad[2];

queue<int> q[2];

int fpow(int a, int b, int mod)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = (ll)res*a%mod;

		b >>= 1;
		a = (ll)a*a%mod;
	}

	return res;
}

void wypisz(int x)
{
	VI p1, p2;

	int curr = x;
	p1.pb(curr);

	while(curr!=u)
	{
		curr = skad[0][curr];
		p1.pb(curr);
	}

	curr = x;
	p2.pb(curr);

	while(curr!=v)
	{
		curr = skad[1][curr];
		p2.pb(curr);
	}

	reverse(ALL(p1));
	p1.pop_back();
	p1.insert(p1.end(), ALL(p2));

	cout << p1.size()-1 << endl;

	for(int i = 0; i+1 < p1.size(); ++i)
	{
		if(p1[i+1]==(p1[i]+1)%p)
			cout << 1 << " ";
		else if(p1[i+1]==(p1[i]+p-1)%p)
			cout << 2 << " ";
		else
			cout << 3 << " ";
	}

	cout << endl;
	exit(0);
}

void go(int i)
{
	int x = q[i].front();
	q[i].pop();

	if(dist[i^1].find(x)!=dist[i^1].end())
		wypisz(x);

	if(dist[i][x]<100)
	{
		int y = (x+1)%p;

		if(dist[i].find(y)==dist[i].end())
		{
			dist[i][y] = dist[i][x]+1;
			skad[i][y] = x;
			q[i].push(y);
		}

		y = (x+p-1)%p;

		if(dist[i].find(y)==dist[i].end())
		{
			dist[i][y] = dist[i][x]+1;
			skad[i][y] = x;
			q[i].push(y);
		}

		y = fpow(x, p-2, p);

		if(dist[i].find(y)==dist[i].end())
		{
			dist[i][y] = dist[i][x]+1;
			skad[i][y] = x;
			q[i].push(y);
		}	
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> u >> v >> p;

	dist[0][u] = 0;
	dist[1][v] = 0;
	q[0].push(u);
	q[1].push(v);

	while(true)
	{
		go(0);
		go(1);
	}
}