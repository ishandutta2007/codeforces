#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define inf 1000000007
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

int k, curr;

string s;

VI v;

bool check(int d)
{
	int c = 0, l = 0;

	for(auto it:v)
	{
		if(c+it>d)
		{
			c = it;
			++l;
		}
		else
			c += it;

		if(c>d)
			return 0;
	}

	if(c)
		++l;

	return l<=k;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	getline(cin, s);

	for(int i = s.size()-1, w = 1; i >= 0; --i, w *= 10)
		k += (s[i]-'0')*w;

	getline(cin, s);

	for(int i = 0; i < s.size(); ++i)
	{
		++curr;

		if(i==s.size()-1 || s[i]==' ' || s[i]=='-')
		{
			v.pb(curr);
			curr = 0;
		}
	}

	int l = 1, r = 1e6;

	while(l<r)
	{
		int m = (l+r)/2;

		if(r==m)
			--m;

		if(check(m))
			r = m;
		else
			l = m+1;
	}

	cout << l;
}