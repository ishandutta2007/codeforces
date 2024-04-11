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

#define N 2007
#define MOD inf

int n, k;

string s;

ll dpc[N][N];
ll dpn[N][N];
ll sufc[N][N];
ll sufn[N][N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k >> s;

	s = 'b'+s;

	dpn[n+1][0] = 1;

	for(int i = n+1; i >= 0; --i)
	{
		for(int l = 0; l <= k; ++l)
		{
			if(l-(n-i+1)>=0) 
			{
				dpc[i][l] += ('z'-s[i])*sufn[i+1][l-(n-i+1)];
				dpc[i][l] %= MOD;
			}

			dpn[i][l] += (s[i]-'a')*sufn[i+1][l];
			dpn[i][l] %= MOD;

			sufc[i][l] = (sufc[i+1][l]+dpc[i][l])%MOD;
			sufn[i][l] = (sufn[i+1][l]+dpn[i][l])%MOD;

			for(int j = i-1; l+(i-j-1)*(n-i+1)+(n-j+1) <= k && j >= 0; --j)
			{
				dpc[j][l+(i-j-1)*(n-i+1)+(n-j+1)] += ('z'-s[j])*dpc[i][l];
				dpc[j][l+(i-j-1)*(n-i+1)+(n-j+1)] %= MOD;
			}

			for(int j = i-1; l+(i-j-1)*(n-i+1) <= k && j >= 0; --j)
			{
				dpn[j][l+(i-j-1)*(n-i+1)] += (s[j]-'a')*dpc[i][l];
				dpn[j][l+(i-j-1)*(n-i+1)] %= MOD;
			}
		}
	}

	cout << dpn[0][k];
}