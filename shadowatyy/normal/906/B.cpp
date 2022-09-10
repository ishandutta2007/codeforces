#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int N = 1e5+7;

int n, m;

int g[7][7];

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool ins(int y, int x)
{
	return 0<=y && y<n && 0<=x && x<m;
}

bool check(VI v)
{
	for(int i = 0; i < n*m; ++i)
	{
		g[i/m][i%m] = v[i];
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			for(int k = 0; k < 4; ++k)
			{
				if(ins(i+Y[k], j+X[k]))
				{
					if(abs(g[i][j]-g[i+Y[k]][j+X[k]])==1 || abs(g[i][j]-g[i+Y[k]][j+X[k]])==m)
						return 0;
				}
			}
		}
	}

	return 1;
}

void wykladnik()
{
	VI v;

	int f = 1;

	for(int i = 1; i <= n*m; ++i)
	{
		v.pb(i);
		f *= i;
	}

	for(int i = 0; i < f; ++i)
	{
		next_permutation(ALL(v));

		if(check(v))
		{
			cout << "YES";

			for(int i = 0; i < n*m; ++i)
			{
				if(i%m==0)
					cout << endl;

				cout << v[i] << " ";
			}

			exit(0);
		}
	}

	cout << "NO\n";
	exit(0);
}

int ans1[N];
int ans2[N];

void wiersze()
{
	int cnt1 = 2;

	for(int i = 1; i <= m; ++i)
	{
		if(cnt1>m)
			cnt1 -= m;

		ans1[cnt1] = i;
		cnt1 += 2;

		if(m%2==0 && i==m/2)
			--cnt1;
	}

	if(m%2==1)
	{
		for(int i = 1; i <= m; ++i)
		{
			ans2[i+1] = ans1[i];
		}

		ans2[1] = ans2[m+1];
	}
	else
	{
		for(int i = 1; i <= m; ++i)
		{
			ans2[i] = m-ans1[i]+1;
		}
	}

	cout << "YES\n";

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(i%2==0)
				cout << ans1[j]+(i-1)*m << " ";
			else
				cout << ans2[j]+(i-1)*m << " ";
		}

		cout << endl;
	}
}

void kolumny()
{
	int cnt1 = 2;

	for(int i = 1; i <= n; ++i)
	{
		if(cnt1>n)
			cnt1 -= n;

		ans1[cnt1] = i;
		cnt1 += 2;

		if(n%2==0 && i==n/2)
			--cnt1;
	}

	if(n%2==1)
	{
		for(int i = 1; i <= n; ++i)
		{
			ans2[i+1] = ans1[i];
		}

		ans2[1] = ans2[n+1];
	}
	else
	{
		for(int i = 1; i <= n; ++i)
		{
			ans2[i] = n-ans1[i]+1;
		}
	}

	cout << "YES\n";

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			if(j%2==0)
				cout << j+(ans1[i]-1)*m << " ";
			else
				cout << j+(ans2[i]-1)*m << " ";
		}

		cout << endl;
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	if(n*m<=9)
		wykladnik();

	if(m>=4)
		wiersze();
	else
		kolumny();
}