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

#define N 1007
#define MAX 1000000000

int n, res;

int t[N];

map<int, int> ile;

VI used;

int sprawdz(int a, int b)
{
 	int res = 2;

 	for(auto it:used)
 		++ile[it];

 	used.clear();

 	--ile[a];
 	--ile[b];
 	used.pb(a);
 	used.pb(b);

 	while(true)
 	{
 		if(a==0 && b==0)
 			return res+ile[0];

 		if((a>MAX && b>MAX) || (a<-MAX && b<-MAX))
 			return res;

 		int c = b+a;

 		if(ile[c]==0)
 			return res;
 		else
 		{
 			++res;
 			--ile[c];
 			used.pb(c);
 			a = b;
 			b = c;
 		}
 	}
}	

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		++ile[t[i]];
	}

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(i!=j)
				res = max(res, sprawdz(t[i], t[j]));
		}
	}

	cout << res;
}