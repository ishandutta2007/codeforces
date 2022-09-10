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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;
	
int a, b, c, d;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> a >> b >> c >> d;

	for(int i = 1; i <= 100000; ++i)
	{
		if(b==d)
		{
			cout << b;
			return 0;
		}

		if(b>d)
			d += c;
		else
			b += a;	
	}

	cout << -1;	
}