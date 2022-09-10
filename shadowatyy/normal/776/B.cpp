#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define inf 1000000007
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define N 100007

int n;

bitset<N> sito;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	cin >> n;

	for(int i = 2; i <= n+1; ++i)
	{
		if(!sito[i])
		{
			for(ll j = (ll)i*i; j <= n+1; j += i)
			{
				sito[j] = 1;
			}
		}
	}

	if(n==1 || n==2)
		cout << 1 << endl;
	else
		cout << 2 << endl;

	for(int i = 2; i <= n+1; ++i)
	{
		if(!sito[i])
			cout << 1 << " ";
		else
			cout << 2 << " ";
	}
}