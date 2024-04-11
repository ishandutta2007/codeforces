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

int n, ans, cnt;

int a[N];

VI v;

set<int> S;
multiset<int> M;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		v.pb(i);
	}

	S.insert(0);
	S.insert(n+1);
	M.insert(n);

	sort(ALL(v), [](int p, int q)
	{
		return a[p]>a[q];
	});

	ans = a[v[0]]+1;
	cnt = 1;

	for(int i = 0; i < n; ++i)
	{
		auto it = S.lower_bound(v[i]);
		M.erase(M.find(*it - *prev(it) - 1));
		it = S.insert(v[i]).st;
		
		if(*it - *prev(it) - 1 > 0)
			M.insert(*it - *prev(it) - 1);

		if(*next(it) - *it - 1 > 0)
			M.insert(*next(it) - *it - 1);

		if(!M.empty() && *M.begin() == *M.rbegin() && cnt<=M.size())
		{
			ans = a[v[i+1]]+1;
			cnt = M.size();
		}
	}

	cout << ans << endl;
}