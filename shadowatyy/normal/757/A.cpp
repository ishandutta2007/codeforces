#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
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

int n, res = inf;

string s;

int c[256];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	n = s.size();

	for(int i = 0; i < n; ++i)
	{
		++c[s[i]];
	}

	res = min(res, c['B']);
	res = min(res, c['u']/2);
	res = min(res, c['l']);
	res = min(res, c['b']);
	res = min(res, c['a']/2);
	res = min(res, c['s']);
	res = min(res, c['a']/2);
	res = min(res, c['u']/2);
	res = min(res, c['r']);

	cout << res;

}