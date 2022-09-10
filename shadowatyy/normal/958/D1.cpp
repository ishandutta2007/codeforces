#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
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

const int N = 2e5+7;

int m;

int a[N];
int b[N];
int c[N];

bool skip = 1;

int ile[1007][1007];

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> m;

	for(int i = 1; i <= m; ++i)
	{
		char x;

		cin >> x;

		if(skip)
			cin >> x;

		a[i] = x-'0';

		cin >> x;

		if(x!='+')
		{
			a[i] = 10*a[i] + x-'0';
			cin >> x;
		} 

		cin >> x;

		b[i] = x-'0';

		cin >> x;

		if(x!=')')
		{
			b[i] = 10*b[i] + x-'0';
			cin >> x;
		}

		cin >> x >> x;

		c[i] = x-'0';

		bool ok = 0;

		ok = (bool)(cin >> x);

		if(ok)
		{
			if(x=='(')
				skip = 0;
			else
			{
				skip = 1;
				c[i] = 10*c[i] + x-'0';
			}
		}

		a[i] += b[i];
		int g = __gcd(a[i], c[i]);
		a[i] /= g;
		c[i] /= g;
		++ile[a[i]][c[i]];
	}

	for(int i = 1; i <= m; ++i)
	{
		cout << ile[a[i]][c[i]] << endl;
	}
}