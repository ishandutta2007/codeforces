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

const int N = 107;

int n;

int g[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n/2; ++i)
	{
		cin >> g[i];
	}

	sort(g+1, g+1+n/2);

	int a1 = 0, a2 = 0;

	for(int i = 1; i <= n/2; ++i)
	{
		a1 += abs(2*i-g[i]);
		a2 += abs(2*i-1-g[i]);
	}

	cout << min(a1, a2) << endl;
}