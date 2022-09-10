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

int n, s, l; 

VI res[N];

set<int, greater<int> > S;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	l = n+1;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s;

		S.insert(s);

		while(!S.empty() && *S.begin()==l-1)
		{
			res[i].pb(*S.begin());
			--l;
			S.erase(S.begin());
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		for(auto it:res[i])
		{
			cout << it << " ";
		}

		cout << endl;
	}
	
}