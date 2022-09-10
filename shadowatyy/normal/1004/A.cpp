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

const int N = 107;

int n, d, ans;

int x[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> d;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i];
	}

	for(int i = 1; i < n; ++i)
	{
		if(x[i+1]-x[i]==2*d)
			++ans;
		else if(x[i+1]-x[i]>2*d)
			ans += 2;
	}

	cout << ans+2 << endl;
}