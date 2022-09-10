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

const int K = 107;

int n, k;

int t[K];
int a[K];

void check(int x)
{
	int ile2 = 2*n+x, ile4 = n-x, ile1 = x;

	for(int i = 1; i <= k; ++i)
	{
		a[i] = t[i];

		int biore4 = min(ile4, a[i]/4);
		a[i] -= biore4*4;
		ile4 -= biore4;

		int biore2 = min(ile2, a[i]/2);
		a[i] -= biore2*2;
		ile2 -= biore2;

		int biore1 = min(ile1, a[i]);
		a[i] -= biore1;
		ile1 -= biore1;

		if(a[i]>3)
			return;

		if(a[i]==3)
		{
			if(ile4)
				--ile4;
			else if(ile2>=2)
				ile2 -= 2;
			else
				return;
		}
		else if(a[i]==2)
		{
			if(ile2)
				--ile2;
			else if(ile4)
				--ile4;
			else
				return;
		}
		else if(a[i]==1)
		{
			if(ile2)
				--ile2;
			else if(ile4)
				--ile4;
			else
				return;
		}
	}

	cout << "YES";
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= k; ++i)
	{
		cin >> t[i];
	}

	for(int i = 0; i <= n; ++i)
	{
		check(i);
	}

	cout << "NO";
}