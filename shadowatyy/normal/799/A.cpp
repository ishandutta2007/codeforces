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

int n, t, k, d, r1, r2, curr;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> t >> k >> d;

	curr = 0;

	for(int i = 0; i <= 1e7; ++i)
	{
		if(i%t==0 && i/t>0)
			curr += k;

		if(curr>=n)
		{
			r1 = i;
			break;
		}
	}

	curr = 0;

	for(int i = 0; i <= 1e7; ++i)
	{
		if(i%t==0 && i/t>0)
			curr += k;

		if((i-d)%t==0 && i-d>=t)
			curr += k;

		if(curr>=n)
		{
			r2 = i;
			break;
		}
	}

	if(r2<r1)
		cout << "YES";
	else
		cout << "NO";
}