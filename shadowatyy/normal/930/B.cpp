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

const int N = 5007;

int n;

string s;

int ile[N][26][26];

VI p[26];

double ans;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();

	for(int i = 0; i < n; ++i)
	{
		p[s[i]-'a'].pb(i);
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 1; j < n; ++j)
		{
			++ile[j][s[i]-'a'][s[(i+j)%n]-'a'];
		}
	}

	for(int i = 0; i < 26; ++i)
	{
		double best = -1;

		for(int j = 1; j < n; ++j)
		{
			int all = 0, ok = 0;

			for(int k = 0; k < 26; ++k)
			{
				all += ile[j][i][k];

				if(ile[j][i][k]==1)
					++ok;
			}

			best = max(best, (double)ok/all);
		}

		ans += (double)p[i].size()/n*best;
	}

	cout << fixed << setprecision(15) << ans << endl;
}