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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 100007
#define S 320

int n;

int a[N];

int ile[N];

int ans[N];

int brut(int k)
{
	int res = 0, last = 0, d = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(++ile[a[i]]==1)
			++d;

		if(d==k && !ile[a[i+1]])
		{
			++res;

			for(int j = last+1; j <= i; ++j)
			{
				ile[a[j]] = 0;
			}

			d = 0;
			last = i;
		}
	}

	if(last!=n)
	{
		++res;

		for(int j = last+1; j <= n; ++j)
		{
			ile[a[j]] = 0;
		}
	}
	
	return res;
}

void dq(int a, int b, int l, int r)
{
	if(l==r)
	{
		for(int i = a; i <= b; ++i)
		{
			ans[i] = l;
		}

		return;
	}

	int m = (a+b)/2;

	ans[m] = brut(m);

	if(a<=m-1)
		dq(a, m-1, ans[m], r);

	if(m+1<=b)
		dq(m+1, b, l, ans[m]);	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	dq(1, n, 1, n);

	for(int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}
}