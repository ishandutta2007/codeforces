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
using namespace std;

int q;

ll l;

string p;

char c;

map<string, int> M;

void dodaj(ll a)
{
	string s = "";

	while(a)
	{
		if(a%2)
		{
			s = '1' + s;
		}
		else
		{
			s = '0' + s;
		}

		a /= 10;
	}

	while(s.size()<19)
	{
		s = '0' + s;
	}

	M[s]++;
}

void pytaj(string a)
{
	while(a.size()<19)
	{
		a = '0' + a;
	}

	cout << M[a] << endl;
}

void usun(ll a)
{
	string s = "";

	while(a)
	{
		if(a%2)
		{
			s = '1' + s;
		}
		else
		{
			s = '0' + s;
		}

		a /= 10;
	}

	while(s.size()<19)
	{
		s = '0' + s;
	}

	M[s]--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> q;

    for(int i = 1; i <= q; ++i)
    {
    	cin >> c;

    	if(c=='-')
    	{
    		cin >> l;
    		usun(l);
    	}

    	if(c=='+')
    	{
    		cin >> l;
    		dodaj(l);
    	}

    	if(c=='?')
    	{
    		cin >> p;
    		pytaj(p);
    	}
    }
}