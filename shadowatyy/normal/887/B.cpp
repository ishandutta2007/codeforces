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
using namespace std;

int n;

bitset<1007> vis;

int a[3][6];

int per[] = {0, 1, 2};

void go(int curr, int val)
{
	if(curr==n)
	{
		vis[val] = 1;
		return;
	}

	int k = per[curr];

	for(int i = 0; i < 6; ++i)
	{
		if(a[k][i] || val>0)
		{
			go(curr+1, val*10+a[k][i]);
		}
	}

	go(curr+1, val);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < 6; ++j)
		{
			cin >> a[i][j];
		}
	}

	for(int i = 0; i < 6; ++i)
	{
		next_permutation(per, per+n);
		go(0, 0);
	}

	for(int i = 1; i <= 1000; ++i)
	{
		if(!vis[i])
		{
			cout << i-1;
			break;
		}	
	}
}