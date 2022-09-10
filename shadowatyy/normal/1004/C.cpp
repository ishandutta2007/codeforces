#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

#define int ll
const int N = 1e5+7;

int n, ans;

int a[N];
int vis[N];
int pier[N];

set<int> S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(!vis[a[i]])
			pier[i] = 1;

		vis[a[i]] = 1;
	}

	for(int i = n; i >= 1; --i)
	{
		if(pier[i])
			ans += S.size();

		S.insert(a[i]);
	}

	cout << ans << endl;
}