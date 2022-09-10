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
#define SIZE(x) (int)(x).size()
using namespace std;

#define int long long

int n, k, ile2, ile5;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	int curr = n;

	for(int i = 1; i <= k; ++i)
	{
		if(curr%2==0)
		{
			curr /= 2;
			++ile2;
		}

		if(curr%5==0)
		{
			curr /= 5;
			++ile5;
		}
	}

	for(int i = ile2+1; i <= k; ++i)
	{
		n *= 2;
	}

	for(int i = ile5+1; i <= k; ++i)
	{
		n *= 5;
	}

	cout << n;
}