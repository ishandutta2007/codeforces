#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 100007

int n, m;

int d[N];
int c[N];

int o[N]; //optymalny wybor dla kroku bsearcha

bool bs(int a)
{
	int Count = 0, s = 0;

	for(int i = 1; i <= m; ++i)
	{
		o[i] = -1;
	}

	for(int i = a; i >= 1; --i)
	{
		if(o[d[i]]==-1)
			o[d[i]] = i;
	}

	for(int i = 1; i <= a; ++i)
	{
		if(d[i]==0 || o[d[i]]!=i)
		{
			++s;
		}
		else
		{
			if(s>=c[d[i]])
			{
				s -= c[d[i]];
				++Count;
			}
		}
	}

	return Count==m;	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> d[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> c[i];
	}

	int l = 1, r = n, k;

	while(l<r)
	{
		k = (l+r)/2;

		if(k==r)
			--k;

		if(bs(k))
			r = k;
		else
			l = k+1;
	}

	if(bs(l))
		cout << l;
	else
		cout << -1;

}