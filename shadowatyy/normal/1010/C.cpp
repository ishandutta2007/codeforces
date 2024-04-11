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

const int N = 1e5+7;

int n, k, g;

int a[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	g = k;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		g = __gcd(g, a[i]);
	}

	cout << k/g << endl;

	for(int i = 0; i < k; i += g)
	{
		cout << i << " ";
	}

	cout << endl;
}