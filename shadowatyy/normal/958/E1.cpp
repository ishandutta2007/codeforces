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

const int N = 17;

int n, m;

struct pkt
{
	int x, y;
};

pkt a[N];
pkt b[N];

int match[N];
int vis[N];

bool prawo(pkt a, pkt b, pkt c)
{
	return (a.x-c.x)*(b.y-c.y) - (b.x-c.x)*(a.y-c.y) > 0;
}

bool inter(pkt a, pkt b, pkt c, pkt d)
{
	return prawo(c, a, b)!=prawo(d, a, b) && prawo(a, c, d)!=prawo(b, c, d);
}

void go(int curr)
{
	if(curr==n+1)
	{
		cout << "YES" << endl;
		exit(0);
	}

	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			bool ok = 1;

			for(int j = 1; j < i; ++j)
			{
				if(inter(a[curr], b[i], a[j], b[match[j]]))
				{
					ok = 1;
					break;
				}
			}

			if(ok)
			{
				match[curr] = i;
				go(curr+1);
				match[curr] = 0;
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	if(n!=m)
	{
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i].x >> b[i].y;
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> b[i].x >> b[i].y;
	}

	go(1);

	cout << "NO" << endl;
}