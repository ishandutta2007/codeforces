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
const int M = 1<<17;

int n, m;

int r[N];
int l[N];
int cnt[N];
int pref[N];
int suf[N];

int load[2*M];

void insert(int a, int v)
{
	a += M;

	while(a>=1)
	{
		load[a] = max(load[a], v);
		a /= 2;
	}
}

int query(int a, int b)
{
	if(a>b)
		return 0;

	a += M;
	b += M;

	int res = max(load[a], load[b]);

	while(a<b-1)
	{
		if(a%2==0)
			res = max(res, load[a+1]);

		if(b%2==1)
			res = max(res, load[b-1]);

		a /= 2;
		b /= 2;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> l[i] >> r[i];
		++cnt[l[i]];
		--cnt[r[i]+1];
	}

	for(int i = 1; i <= m; ++i)
	{
		cnt[i] += cnt[i-1];
	}

	for(int i = 1; i <= m; ++i)
	{
		pref[i] = 1+query(0, cnt[i]);
		insert(cnt[i], pref[i]);
	}

	memset(load, 0, sizeof load);

	for(int i = m; i >= 1; --i)
	{
		suf[i] = 1+query(0, cnt[i]);
		insert(cnt[i], suf[i]);
	}

	int ans = 0;

	for(int i = 1; i <= m; ++i)
	{
		ans = max(ans, pref[i]+suf[i]-1);
	}

	cout << ans << endl;
}