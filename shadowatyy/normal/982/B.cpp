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

const int N = 2e5+7;

int n;

int a[N];

set<PII> w;
set<PII, greater<PII> > z;

string t;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		w.emplace(a[i], i);
	}

	cin >> t;

	for(int i = 0; i < 2*n; ++i)
	{
		if(t[i]=='0')
		{
			auto it = *w.begin();
			w.erase(it);
			cout << it.nd << " ";
			z.insert(it);
		}
		else
		{
			auto it = *z.begin();
			z.erase(it);
			cout << it.nd << " ";
		}
	}
}