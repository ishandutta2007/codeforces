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

#define N 100007
#define int long long

int n, m, off;

int t[N];

set<int> S, C;

int fpow(int a, int b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%m;

	if(b%2)
		return (a*fpow(a, b-1))%m;
	else
	{
		int q = fpow(a, b/2);
		return (q*q)%m;
	}
}

void solve()
{
	int x = (t[1]-t[2]+m)%m;
	int ile = 0;

	for(auto it:S)
	{
		if(S.find((it+x)%m)!=S.end())
			++ile;
	}

	//ile = n-(k-1)+1
	int k = n-ile;
	int r = (x*fpow(k, m-2))%m;
	int d = 1;
	int a = t[1];
	int b = t[1];

	while(S.find((b+r)%m)!=S.end())
	{
		++d;
		b = (b+r)%m;
	}

	while(S.find((a-r+m)%m)!=S.end())
	{
		++d;
		a = (a-r+m)%m;
	}

	if(d==n)
	{
		cout << (a+r*off)%m << " " << r;
		exit(0);
	}	
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		S.insert(t[i]);
	}

	if(n==1)
	{
		cout << t[1] << " " << 0;
		exit(0);
	}
	else if(n==m)
	{
		cout << 0 << " " << 1;
		exit(0);
	}

	if(2*n<=m)
	{
		solve();
		swap(t[1], t[2]);
		solve();
	}
	else
	{
		for(int i = 0; i < m; ++i)
		{
			if(S.find(i)==S.end())
				C.insert(i);
		}

		swap(S, C);
		int c = 0;

		for(auto it:S)
			t[++c] = it;

		n = off = S.size();

		solve();
		swap(t[1], t[2]);
		solve();
	}

	cout << -1;
		
}