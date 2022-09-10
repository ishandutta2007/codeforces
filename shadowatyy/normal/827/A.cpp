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

#define N 100007

int n, l, k, p;

string t[N];

string res;

VPII w;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i] >> k;

		while(k--)
		{
			cin >> p;
			w.eb(p, i);
			l = max(l, p+(int)t[i].size()-1);
		}
	}

	sort(ALL(w));

	int curr = -1, zasieg = -1, ktore = -1, pozycja = -1;

	for(int i = 1; i <= l; ++i)
	{
		while(curr+1<(int)w.size() && w[curr+1].st==i)
		{
			++curr;

			if(i+(int)t[w[curr].nd].size()-1>zasieg)
			{
				zasieg = i+(int)t[w[curr].nd].size()-1;
				pozycja = w[curr].st;
				ktore = w[curr].nd;
			}
		}

		if(zasieg>=i)
			res += t[ktore][i-pozycja];
		else
			res += 'a';
	}

	cout << res;
}