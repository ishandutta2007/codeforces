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
const int N = 1e6+7;

int n, k1, k2, sum, ans;

int a[N];
int b[N];

multiset<int, greater<int> > S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k1 >> k2;

	sum = k1+k2;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];

		if(a[i]!=b[i])
			S.insert(abs(a[i]-b[i]));
	}

	while(!S.empty() && sum>0)
	{
		int v = *S.begin();
		S.erase(S.begin());
		--v;
		--sum;

		if(v>0)
			S.insert(v);
	}

	if(sum>0)
		cout << sum%2 << endl;
	else
	{
		for(auto it:S)
			ans += it*it;

		cout << ans << endl;
	}
}