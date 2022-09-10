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

int n;

VI ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	if(n%4==0 || n%4==3)
	{
		cout << 0 << endl;
		
		int curr = n*(n+1)/4;

		for(int i = n; i >= 1; --i)
		{
			if(curr>=i)
			{
				curr -= i;
				ans.pb(i);
			}
		}

		cout << ans.size() << " ";

		for(auto it:ans)
			cout << it << " ";
	}
	else
	{
		cout << 1 << endl;
		
		int curr = n*(n+1)/4;

		for(int i = n; i >= 1; --i)
		{
			if(curr>=i)
			{
				curr -= i;
				ans.pb(i);
			}
		}

		cout << ans.size() << " ";

		for(auto it:ans)
			cout << it << " ";
	}
}