#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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
#define flush fflush(stdout)
using namespace std;

#define int long long
#define y1 jfsjfise

int x1, y1, x2, y2, x, y;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> x1 >> y1 >> x2 >> y2 >> x >> y;







	if(x1>x2)
		swap(x1, x2);  

	if(y1>y2)
		swap(y1, y2);

	if((x2-x1)%x!=0)
	{
		cout << "NO";
		return 0;
	}

	if((y2-y1)%y!=0)
	{
		cout << "NO";
		return 0;
	}

	if(((x2-x1)/x)%2!=((y2-y1)/y)%2)
	{
		cout << "NO";
		return 0;
	}

	cout << "YES";
}