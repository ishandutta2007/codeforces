#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

int n, k;

ll res;

int a[N];

map<ll, int> M;

ll solve(ll q)
{	
	M.clear();

	ll sum = 0, ans = 0;

	++M[0];

	for(int i = 1; i <= n; ++i)
	{
		sum += a[i];

		ans += M[sum-q];

		++M[sum];
	}

	return ans;
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

	if(k==1)
	{
		cout << solve(1);
		return 0;
	}

	if(k==-1)
	{
		cout << solve(1)+solve(-1);
		return 0;
	}

	for(ll i = 1; i <= 10000000000000000LL; i *= k)
	{
		res += solve(i);
	}

	cout << res;
}