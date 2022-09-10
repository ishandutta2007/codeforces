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
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;
	
#define N 20007

int n, m, k, a;

bitset<N> visr;
bitset<N> vism;
bitset<N> vis;
bitset<N> juz;

VI A;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= m; ++i)
	{		
		cin >> k;

		int ile = 0, zle = 0;

		while(k--)
		{
			cin >> a;

			if(!vis[max(a, -a)])
				++ile;

			vis[max(a, -a)] = 1;

			if(a>0)
				visr[max(a, -a)] = 1;
			else
				vism[max(a, -a)] = 1;

			A.pb(a);
		}

		for(auto a:A)
		{
			if(vis[max(a, -a)] && (!vism[max(a, -a)] || !visr[max(a, -a)]) && !juz[max(a, -a)])
			{
				++zle;
				juz[max(a, -a)] = 1;
			}
		}

		if(ile==zle)
		{
			cout << "YES";
			return 0;
		}

		for(auto a:A)
		{
			vis[max(a, -a)] = vism[max(a, -a)] = visr[max(a, -a)] = juz[max(a, -a)] = 0;
		}
	}

	cout << "NO";
}