#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define y1 fewgwegwe

int x1, x2, y1, y2, n;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	cout << "YES\n";

	while(n--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += inf;
		y1 += inf;
		cout << 2*(x1%2)+y1%2+1 << endl;
	}
}