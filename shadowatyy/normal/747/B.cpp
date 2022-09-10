#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

int n;

string s;

int c[1<<8];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	s = '#' + s;

	for(int i = 1; i <= n; ++i)
	{
		++c[s[i]];
	}

	for(int i = 1; i <= n; ++i)
	{
		if(s[i]=='?')
		{
			if(c['A']<n/4)
			{
				s[i] = 'A';
				++c['A'];
				continue;
			}

			if(c['C']<n/4)
			{
				s[i] = 'C';
				++c['C'];
				continue;
			}

			if(c['G']<n/4)
			{
				s[i] = 'G';
				++c['G'];
				continue;
			}

			if(c['T']<n/4)
			{
				s[i] = 'T';
				++c['T'];
				continue;
			}	

			s[i] = 'A';
		}
	}

	c['A'] = 0;
	c['C'] = 0;
	c['G'] = 0;
	c['T'] = 0;

	for(int i = 1; i <= n; ++i)
	{
		++c[s[i]];
	}

	if(c['A']!=n/4)
	{
		cout << "===";
		return 0;
	}

	if(c['T']!=n/4)
	{
		cout << "===";
		return 0;
	}

	if(c['G']!=n/4)
	{
		cout << "===";
		return 0;
	}

	if(c['C']!=n/4)
	{
		cout << "===";
		return 0;
	}

	cout << s.substr(1, inf);
}