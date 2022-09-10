#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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

const int N = 1e5+7;

int q;

int divs[N];
int ok[8][8][8];
VI p = {0, 1, 2};
int a[3];
int ans[8];
int ile[8];

void solve()
{
	cin >> a[0] >> a[1] >> a[2];

	for(int i = 7; i >= 1; --i)
	{
		int g = -1;

		for(int j = 0; j < 3; ++j)
		{
			if(i&(1<<j))
			{
				if(g==-1)
					g = a[j];
				else
					g = __gcd(g, a[j]);
			}
		}

		ans[i] = divs[g];

		for(int j = i+1; j < 8; ++j)
		{
			if((j&i)==i)
				ans[i] -= ans[j];
		}
	}

	int res = 0;

	for(int i = 0; i < 8; ++i)
	{
		for(int j = i; j < 8; ++j)
		{
			for(int k = j; k < 8; ++k)
			{
				if(ok[i][j][k])
				{
					int curr = -1;
						
					if(i==j && j==k)
						curr = (ans[i]+2)*(ans[i]+1)*ans[i]/6;
					else if(i==j)
						curr = (ans[i]+1)*ans[i]/2*ans[k];
					else if(j==k)
						curr = (ans[j]+1)*ans[j]/2*ans[i];
					else if(i==k)
						curr = (ans[i]+1)*ans[i]/2*ans[j];
					else
						curr = ans[i]*ans[j]*ans[k];

					res += curr;
				}
			}
		}
	}

	cout << res << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 1; i < N; ++i)
	{
		for(int j = i; j < N; j += i)
			++divs[j];
	}

	for(int i = 0; i < 8; ++i)
	{
		for(int j = i; j < 8; ++j)
		{
			for(int k = j; k < 8; ++k)
			{
				for(int x = 0; x < 6; ++x)
				{
					if((i&(1<<p[0])) && (j&(1<<p[1])) && (k&(1<<p[2])))
						ok[i][j][k] = 1;

					next_permutation(ALL(p));
				}
			}
		}
	}

	cin >> q;

	while(q--)
		solve();
}