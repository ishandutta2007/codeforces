#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define ll long long
#define VI vector<int>
#define VLL vector<ll>
#define PII pair<int, int>
#define VPII vector<PII>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
const int inf = 1e9L+7;
const ll INF = 1e18L+7;

const int N = 1007;

int n, s;

int a[N];
int b[N];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> s;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i];
	}

	if(a[1]==0)
		cout << "NO" << endl;
	else
	{
		if(a[s]==1)
			cout << "YES" << endl;
		else if(b[s]==0)
			cout << "NO" << endl;
		else
		{
			for(int i = s+1; i <= n; ++i)
			{
				if(a[i] && b[i])
				{
					cout << "YES" << endl;
					return 0;
				}
			}

			cout << "NO" << endl;
		}
	}
}