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

int x, d;

VI ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> x >> d;

	int curr = 1;

	for(int i = 0; i < 30; ++i)
	{
		if(x&(1<<i))
		{
			for(int j = 0; j < i; ++j)
			{
				ans.pb(curr);
			}

			curr += d+1;
			ans.pb(curr);
			curr += d+1;
		}
	}

	cout << ans.size() << endl;

	for(auto it:ans)
		cout << it << " ";
}