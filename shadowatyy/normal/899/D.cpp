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

#define int ll

int n, res;

int cnt(int s)
{
	return max(0ll, (s-1)/2-max(s-n, 1ll)+1);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	int curr = 0, pot = 1;

	while(10*curr+9<=2*n-1)
	{
		curr = 10*curr+9;
		pot *= 10;
	}

	for(int i = 0; i <= 9 && pot*i+curr<=2*n-1; ++i)
		res += cnt(pot*i+curr);

	cout << res;
}