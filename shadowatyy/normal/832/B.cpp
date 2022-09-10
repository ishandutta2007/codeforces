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

int q, pos = -1, ile = -1;

string g, p, s;

bitset<256> good;

bool check1()
{
	if(SIZE(p)!=SIZE(s))
		return 0;

	for(int i = 0; i < SIZE(s); ++i)
	{
		if(s[i]!=p[i])
		{
			if(p[i]!='?')
				return 0;

			if(!good[s[i]])
				return 0;
		}
	}

	return 1;
}

bool check2()
{
	if(SIZE(p)-1>SIZE(s))
		return 0;

	for(int i = 0; i < pos; ++i)
	{
		if(s[i]!=p[i])
		{
			if(p[i]!='?')
				return 0;

			if(!good[s[i]])
				return 0;
		}
	}

	int last = SIZE(s);

	for(int i = 1; i <= ile; ++i)
	{
		if(s[SIZE(s)-i]!=p[SIZE(p)-i])
		{
			if(p[SIZE(p)-i]!='?')
				return 0;

			if(!good[s[SIZE(s)-i]])
				return 0;
		}

		last = SIZE(s)-i;
	}

	for(int i = pos; i < last; ++i)
	{
		if(good[s[i]])
			return 0;
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> g >> p >> q;

	for(auto it:g)
		good[it] = 1;

	for(int i = 0; i < p.size(); ++i)
	{
		if(p[i]=='*')
		{
			pos = i;
			ile = SIZE(p)-i-1;
		}
	}

	while(q--)
	{
		cin >> s;

		if(pos==-1)
		{
			if(check1())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
		{
			if(check2())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}