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

const int N = 70007;

int n;

string s[N];

unordered_map<string, int> M;
unordered_map<string, int> S[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];

		for(int j = 0; j < s[i].size(); ++j)
		{
			for(int l = 1; l <= s[i].size()-j; ++l)
			{
				M[s[i].substr(j, l)]++;
				S[i][s[i].substr(j, l)]++;
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		string res = "XXXXXXXXXXXXXXX";

		for(int j = 0; j < s[i].size(); ++j)
		{
			for(int l = 1; l <= s[i].size()-j; ++l)
			{
				if(M[s[i].substr(j, l)]==S[i][s[i].substr(j, l)] && res.size()>l)
					res = s[i].substr(j, l);
			}
		}

		cout << res << endl;
	}
}