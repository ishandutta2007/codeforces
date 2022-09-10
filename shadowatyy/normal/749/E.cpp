#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

const int N = 100007;
const int M = 1<<17;

int n;

int a[N];

double res, inw, den;

ll load[2*M];

void insert(int a, int v)
{
	a += M;

	while(a>=1)
	{
		load[a] += v;
		a /= 2;
	}
}

ll query(int a, int b)
{
	a += M;
	b += M;

	ll res = 0;

	res += load[a];

	if(a!=b)
		res += load[b];

	while(a<b-1)
	{
		if(a%2==0)
			res += load[a+1];

		if(b%2==1)
			res += load[b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

void clear()
{
	for(int i = 1; i < 2*M; ++i)
	{
		load[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	den = (double)n*(n+1)/2;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = n; i >= 1; --i)
	{
		res -= query(1, a[i])*i;

		insert(a[i], n-i+1);
	}

	for(int i = 2; i <= n; ++i)
	{
		res += (double)i*(i-1)/4*(n-i+1);
	}

	clear();

	for(int i = n; i >= 1; --i)
	{
		inw += query(1, a[i]);

		insert(a[i], 1);
	}

	cout << setprecision(10) << fixed << inw+res/den;

}