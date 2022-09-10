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

#define int long long
#define double long double

const int N = 1e5+7;

int n, m, r, k, my, mx;

double ans;

struct comp
{
	inline bool operator()(const PII &a, const PII &b)
	{
		return mp(a.st*a.nd, a.st)>mp(b.st*b.nd, b.st);
	}
};

set<PII, comp> S;

int R[N];
int C[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> r >> k;

	for(int i = 1; i <= n; ++i)
	{
		int a = max(1ll, i-r+1);
		int b = min(n-r+1, i);
		++R[b-a+1];
		my = max(my, b-a+1);
	}

	for(int i = 1; i <= m; ++i)
	{
		int a = max(1ll, i-r+1);
		int b = min(m-r+1, i);
		++C[b-a+1];
		mx = max(mx, b-a+1);
	}

	S.emplace(my, mx);

	while(k>0)
	{
		PII v = *S.begin();
		S.erase(S.begin());

		int moge = R[v.st]*C[v.nd];

		ans += v.st*v.nd*min(k, moge);
		k -= min(k, moge);

		if(v.st>1)
			S.emplace(v.st-1, v.nd);

		if(v.nd>1)
			S.emplace(v.st, v.nd-1);
	}

	ans /= (n-r+1)*(m-r+1);
	cout << fixed << setprecision(10) << ans;
}