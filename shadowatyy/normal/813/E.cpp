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
#define flush fflush(stdout)
using namespace std;

#define N 100007
#define M (1<<17)

int n, k, ans, l, r, q;

int a[N];

VI load[2*M];

VI wyst[N];

int query(int a, int b, int k)
{
	int res = 0;

	a += M;
	b += M;

	res += load[a].size()-(upper_bound(ALL(load[a]), k)-load[a].begin());

	if(a!=b)
		res += load[b].size()-(upper_bound(ALL(load[b]), k)-load[b].begin());

	while(a<b-1)
	{
		if(a%2==0)
			res += load[a+1].size()-(upper_bound(ALL(load[a+1]), k)-load[a+1].begin());

		if(b%2==1)
			res += load[b-1].size()-(upper_bound(ALL(load[b-1]), k)-load[b-1].begin());

		a /= 2;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = n; i >= 1; --i)
	{
		if(wyst[a[i]].size()<k)
			load[i+M].pb(inf);
		else
			load[i+M].pb(wyst[a[i]][wyst[a[i]].size()-k]);

		wyst[a[i]].pb(i);
	}

	for(int i = M-1; i >= 1; --i)
	{
		load[i].insert(load[i].end(), ALL(load[2*i]));
		load[i].insert(load[i].end(), ALL(load[2*i+1]));
		sort(ALL(load[i]));
	}

	cin >> q;

	while(q--)
	{
		cin >> l >> r;

		l = (l+ans)%n+1;
		r = (r+ans)%n+1;

		if(l>r)
			swap(l, r);

		cout << (ans = query(l, r, r)) << endl;
	}
}