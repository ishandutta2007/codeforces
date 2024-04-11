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

VI v;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 0; i < 3; ++i)
	{
		int x;
		cin >> x;
		v.pb(x);
	}

	sort(ALL(v));

	bool ans = 0;

	if(v[0]==1)
		ans = 1;

	if(v[0]==2 && v[1]==2)
		ans = 1;

	if(v[0]==2 && v[1]==4 && v[2]==4)
		ans = 1;

	if(v[0]==3 && v[1]==3 && v[2]==3)
		ans = 1;

	if(ans)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}