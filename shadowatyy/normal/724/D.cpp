#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000000
#define INF 1000000000000000000LL
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define endl '\n'
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

#define N 100007
#define M (1<<17)

int m, Index, n, last = -inf;

char Max = 'a';

int ile[307];

int ileres[307];

string s;

vector<char> res;

int load[2*M];

void build()
{
	for(int i = 1; i <= n; ++i)
	{
		load[i+M] = i;
	}

	for(int i = M-1; i >= 1; --i)
	{
		if(s[load[i*2]]>=s[load[i*2+1]])
			load[i] = load[i*2+1];
		else
			load[i] = load[i*2];
	}
}

int query(int a, int b)
{
	int res = b;

	a += M;
	b += M;

	if(s[load[a]]<s[res])
		res = load[a];

	if(s[load[b]]<s[res])
		res = load[b];

	if(s[load[a]]==s[res] && res<load[a])
		res = load[a];

	if(s[load[b]]==s[res] && res<load[b])
		res = load[b];

	while(a<b-1)
	{
		if(a%2==0 && s[load[a+1]]<s[res])
			res = load[a+1];

		if(b%2==1 && s[load[b-1]]<s[res])
			res = load[b-1];

		if(a%2==0 && s[load[a+1]]==s[res] && res<load[a+1])
			res = load[a+1];

		if(b%2==1 && s[load[b-1]]==s[res] && res<load[b-1])
			res = load[b-1];

		a /= 2;
		b /= 2;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m >> s;

	n = s.size();

	s = '#' + s;

	build();

	for(int i = 1; i <= n; ++i)
	{
		++ile[s[i]];
	}

	for(int i = 1; i <= n-m+1; ++i)
	{	
		Index = query(i, i+m-1);

		if(last>=i && s[last]<=s[Index])
			continue;

		res.pb(s[Index]);

		Max = max(Max, s[Index]);

		++ileres[s[Index]];

		last = max(last, Index);
	}

	for(int i = 'a'; i < Max; ++i)
	{
		for(int j = 1; j <= ile[i]; ++j)
		{
			cout << (char)i;
		}
	}

	for(int j = 1; j <= ileres[Max]; ++j)
	{
		cout << (char)Max;
	}
}