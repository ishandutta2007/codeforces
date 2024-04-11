#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

#define int ll
const int N = 1e5+7;

int n, m, l, ans;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> l;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(a[i]>l)
			++ans;
	}

	for(int i = 1; i < n; ++i)
	{
		if(a[i]>l && a[i+1]>l)
			--ans;
	}

	while(m--)
	{
		int t;
		cin >> t;

		if(t==0)
			cout << ans << endl;
		else
		{
			int p, d;
			cin >> p >> d;

			if(a[p]<=l && a[p]+d>l)
			{
				++ans;

				if(p!=1 && a[p-1]>l)
					--ans;

				if(p!=n && a[p+1]>l)
					--ans;
			}

			a[p] += d;
		}
	}
}