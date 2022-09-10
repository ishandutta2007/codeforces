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

#define N 300007

int n, f, b;

multiset<char> Smin, Lmin;
multiset<char, greater<char> > Smax, Lmax;

string s, l;

char res[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s >> l;

	n = s.size();

	for(char it:s)
	{
		Smax.insert(it);
	}

	while(Smax.size()>(n+1)/2)
		Smax.erase(Smax.begin());

	for(auto it:Smax)
		Smin.insert(it);

	for(char it:l)
	{
		Lmin.insert(it);
	}

	while(Lmin.size()>n/2)
		Lmin.erase(Lmin.begin());

	for(auto it:Lmin)
		Lmax.insert(it);

	f = 1;
	b = n;

	for(int i = 1; i <= n; ++i)
	{
		if(i%2)
		{
			if(*Smin.begin()<*Lmax.begin())
			{
				res[f++] = *Smin.begin();
				Smax.erase(Smax.find(*Smin.begin()));
				Smin.erase(Smin.begin());
			}
			else
			{
				res[b--] = *Smax.begin();
				Smin.erase(Smin.find(*Smax.begin()));
				Smax.erase(Smax.begin());
			}
		}
		else
		{
			if(*Lmax.begin()>*Smin.begin())
			{
				res[f++] = *Lmax.begin();
				Lmin.erase(Lmin.find(*Lmax.begin()));
				Lmax.erase(Lmax.begin());
			}
			else
			{
				res[b--] = *Lmin.begin();
				Lmax.erase(Lmax.find(*Lmin.begin()));
				Lmin.erase(Lmin.begin());
			}
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		cout << res[i];
	}
}