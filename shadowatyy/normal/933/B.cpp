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

#define int long long
const int N = 107;

int p, k, s;

int ans[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> p >> k;

	k = -k;

	for(int i = 0; i < N; ++i)
	{
		ans[i] = p%k;
		p /= k;

		if(ans[i])
			s = i;
	}

	for(int i = 0; i < N; ++i)
	{
		while(ans[i]<0)
		{
			ans[i] -= k;
			ans[i+1] += 1;
		}

		while(ans[i]>=-k)
		{
			ans[i] += k;
			ans[i+1] -= 1;
		}
	}

	for(int i = 0; i < N; ++i)
	{
		if(ans[i])
			s = i;
	}

	cout << s+1 << endl;

	for(int i = 0; i <= s; ++i)
	{
		cout << ans[i] << " ";
	}
}