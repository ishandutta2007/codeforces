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

string s;

set<char> znalezione;
set<char> dowypisania;

bool sprawdz(int p)
{
	dowypisania.clear();
	znalezione.clear();

	int Count = 0;

	for(int i = 1; i <= 26; ++i)
	{
		dowypisania.insert((char)(i+64));
	}

	for(int i = p; i <= p+25; ++i)
	{
		if(s[i]=='?')
			++Count;
		else
		{
			znalezione.insert(s[i]);
			if(dowypisania.find(s[i])!=dowypisania.end())
				dowypisania.erase(s[i]);
		}
	}

	if(Count+(int)znalezione.size()<26)
		return 0;

	for(int i = 1; i < p; ++i)
	{
		if(s[i]!='?')
			cout << s[i];
		else
			cout << 'A';
	}

	for(int i = p; i <= p+25; ++i)
	{
		if(s[i]=='?')
		{
			cout << *dowypisania.begin();
			dowypisania.erase(dowypisania.begin());
		}
		else
			cout << s[i];
	}

	for(int i = p+26; i < s.size(); ++i)
	{
		if(s[i]!='?')
			cout << s[i];
		else
			cout << 'A';
	}

	return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> s;

    s = '#' + s;

    for(int i = 1; i+25 < s.size(); ++i)
    {
    	if(sprawdz(i))
    		return 0;
    }

    cout << -1;
}