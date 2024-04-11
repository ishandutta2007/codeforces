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

#define N 100007
#define int long long

int n;

int a[N];

map<int, int> Log;
map<int, int> Pot;

int ile[107];

multiset<int> K, P;
multiset<int> Sk, Sp;

bool check(int k)
{
	Sk = K;
	Sp = P;

	for(int i = 0; i < k; ++i)
	{
		int u = *Sp.begin();
		Sp.erase(Sp.begin());

		while(u)
		{
			Sk.insert(u);
			u /= 2;
		}	
	}

	if(Sp.size()<Sk.size())
		return 0;

	for(auto itp = Sp.begin(), itk = Sk.begin(); itk!=Sk.end(); ++itp)
	{
		if(itp==Sp.end())
			return 0;

		if(2*(*itp)<(*itk))
			continue;
		else
			++itk;
			
	}

	return 1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1, k = 0; i < INF; i *= 2, ++k)
	{
		Log[i] = k;
		Pot[k] = i;
	}

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];

		if(Log.find(a[i])==Log.end())
			K.insert(a[i]);
		else
			++ile[Log[a[i]]];
	}

	for(int i = 1; i < 60; ++i)
	{
		while(ile[i]>ile[i-1])
		{
			--ile[i];
			K.insert(Pot[i]);
		}
	}

	for(int i = 0; i < 60; ++i)
	{
		for(int j = 0; j < ile[i]-ile[i+1]; ++j)
		{
			P.insert(Pot[i]);
		}
	}

	int l = 0, r = (ll)P.size()-1;

	while(l<r)
	{
		int m = (l+r)/2;

		if(l==m)
			++m;

		if(check(m))
			l = m;
		else
			r = m-1;
	}

	if(!check(l))
		cout << -1;
	else
	{
		for(int i = (ll)P.size()-l; i <= P.size(); ++i)
			cout << i << " ";
	}
}