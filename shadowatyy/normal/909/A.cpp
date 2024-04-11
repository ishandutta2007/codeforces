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

string A, B;

vector<string> ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> A >> B;

	for(int i = 1; i <= A.size(); ++i)
	{
		for(int j = 1; j <= B.size(); ++j)
		{
			string s = A.substr(0, i)+B.substr(0, j);
			ans.pb(s);
		}
	}

	sort(ALL(ans));
	cout << ans[0];
}