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

string s;

bitset<26> vis;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	for(auto it:s)
	{
		if(!vis[it-'a'])
		{
			for(int i = 0; i < it-'a'; ++i)
			{
				if(!vis[i])
				{
					cout << "NO";
					return 0;
				}
			}
		}

		vis[it-'a'] = 1;
	}

	cout << "YES";
}