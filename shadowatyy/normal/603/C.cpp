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

#define N 500007

int n, k, x;

int a[N];

int t0[] = {0, 1, 2, 0, 1, 0};
int t1[] = {0, 1, 0, 1, 2, 0};

int f0(int a)
{
	if(a<6)
		return t0[a];
	else
		return (a&1)^1;
}

int f1(int a)
{
	if(a<6)
		return t1[a];
	else
	{
		if(a%2)
			return 0;
		else
		{
			if(f1(a/2)==1)
				return 2;
			else
				return 1;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	if(k%2)
		k = 1;
	else
		k = 0;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(k==0)
			x ^= f0(a[i]);
		else
			x ^= f1(a[i]);
	}

	if(x)
		cout << "Kevin";
	else
		cout << "Nicky";
}