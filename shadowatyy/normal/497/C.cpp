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

const int N = 2e5+7;

int n, m;

int a[N];
int b[N];
int k[N];

int res[N];
 
bool comp_sort(int A, int B)
{
	if(a[A]==a[B])
		return A>B;

	return a[A]<a[B];
}

VI e;

struct comp_set
{
	bool operator()(int A, int B)
	{
		return mp(b[A], A)<mp(b[B], B);
	}
};

set<int, comp_set> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i] >> b[i];
		e.pb(i);
	}

	cin >> m;

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[n+i] >> b[n+i] >> k[n+i];
		e.pb(n+i);
	}

	sort(ALL(e), comp_sort);

	for(auto it:e)
	{
		if(it>n)
			S.insert(it);
		else
		{
			auto l = S.lower_bound(it);

			if(l==S.end())
			{
				cout << "NO";
				exit(0);
			}

			res[it] = *l-n;
			--k[*l];

			if(!k[*l])
				S.erase(l);
		}
	}

	cout << "YES" << endl;

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i] << " ";
	}
}