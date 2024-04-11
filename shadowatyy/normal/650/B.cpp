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
const int N = 1e6+7;

int n, a, b, T, ans;

string s;

int t[N];
int ile_w[N];

bool check(int l, int r)
{
	return r-l+1 + b*(ile_w[r]-ile_w[l-1]) + a*(r-l+min(abs(n+1-l), abs(n+1-r))) <= T;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> a >> b >> T >> s;
	s = '#'+s+s;

	for(int i = 1; i <= 2*n; ++i)
	{
		if(s[i]=='w')
			++ile_w[i];

		ile_w[i] += ile_w[i-1];
	}

	int r = n+1;

	for(int l = 2; l <= n+1; ++l)
	{
		while(r-l+1<n && check(l, r+1))
			++r;

		if(check(l, r))
			ans = max(ans, r-l+1);
	}

	cout << ans << endl;
}