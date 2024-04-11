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

#define int long long
#define N 127

int n;

int a[N][7];

int ok[7];

int score(int a, int b)
{
	if(2*a>b)
		return 500;

	if(4*a>b)
		return 1000;

	if(8*a>b)
		return 1500;

	if(16*a>b)
		return 2000;

	if(32*a>b)
		return 2500;

	return 3000;
}

bool check(int k)
{
	int vs = 0, ps = 0;

	for(int i = 1; i <= 5; ++i)
	{
		if(a[1][i]==-1 && a[2][i]==-1)
			continue;

		if(a[1][i]==-1)
		{
			if(a[1][i]!=-1) vs += score(ok[i], n+k)-score(ok[i], n+k)/250*a[1][i];
			if(a[2][i]!=-1) ps += score(ok[i], n+k)-score(ok[i], n+k)/250*a[2][i];
			continue;
		}

		if(a[2][i]==-1)
		{
			if(a[1][i]!=-1) vs += score(ok[i], n+k)-score(ok[i], n+k)/250*a[1][i];
			if(a[2][i]!=-1) ps += score(ok[i], n+k)-score(ok[i], n+k)/250*a[2][i];
			continue;
		}

		if(a[1][i]>a[2][i])
		{
			if(a[1][i]!=-1) vs += score(ok[i]+k, n+k)-score(ok[i]+k, n+k)/250*a[1][i];
			if(a[2][i]!=-1) ps += score(ok[i]+k, n+k)-score(ok[i]+k, n+k)/250*a[2][i];
		}
		else
		{
			if(a[1][i]!=-1) vs += score(ok[i], n+k)-score(ok[i], n+k)/250*a[1][i];
			if(a[2][i]!=-1) ps += score(ok[i], n+k)-score(ok[i], n+k)/250*a[2][i];
		}
	}

	return vs>ps;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= 5; ++j)
		{
			cin >> a[i][j];

			if(a[i][j]!=-1)
				++ok[j];
		}
	}

	for(int i = 0; i < 120*33; ++i)
	{
		if(check(i))
		{
			cout << i;
			return 0;
		}
	}

	cout << -1;
	return 0;
}