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
#define REP(x, y) for(int x = 0; x < (y); ++x)
#define FOR(x, y, z) for(int x = y; x <= (z); ++x)
using namespace std;

string s;

bitset<307> vis;

char t[307];

int pos[307];

void generuj(int p)
{
	vis = 0;

	for(int i = 1; i <= 27; ++i)
	{
		if(vis[s[i]])
			continue;

		vis[s[i]] = 1;

		t[p] = s[i];

		pos[s[i]] = p;

		++p;

		p = (p-1)%26+1;
	}
}

bool krawedz(int a, int b)
{
	if(a==b)
		return 0;

	if(a==b-1)
		return 1;

	if(b==a-1)
		return 1;

	if(a>b)
		swap(a, b);

	b = 27-b;

	if(a==b-1)
		return 1;

	if(b==a-1)
		return 1;

	if(b==a)
		return 1;

	return 0;
}

bool sprawdz(int p)
{
	for(int i = 2; i <= 27; ++i)
	{
		if(!krawedz(pos[s[i]], pos[s[i-1]]))
			return 0;
	}

	return 1;
}

void wypisz()
{
	for(int i = 1; i <= 13; ++i)
	{
		cout << t[i];
	}

	cout << endl;

	for(int i = 26; i >= 14; --i)
	{
		cout << t[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;

	s = '#' + s;

	for(int i = 1; i <= 26; ++i)
	{
		generuj(i);

		if(sprawdz(i))
		{
			wypisz();
			return 0;
		}	
	}

	cout << "Impossible";
}