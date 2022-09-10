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
#define flush fflush(stdout)
using namespace std;

#define M (1<<20)
#define N 1000007
#define typ pair<int, PII>

int n, q, a, b;

string s;

int res[2*M];
int o[2*M];
int c[2*M];

void build(int v, int l, int r)
{
	if(l==r)
	{
		if(1<=l && l<=n)
		{
			if(s[l]=='(')
				++o[v];
			else
				++c[v];
		}

		return;
	}

	build(2*v, l, (l+r)/2);
	build(2*v+1, (l+r)/2+1, r);

	int tmp = min(o[2*v], c[2*v+1]);
	res[v] = res[2*v]+res[2*v+1]+tmp;
	o[v] = o[2*v]+o[2*v+1]-tmp;
	c[v] = c[2*v]+c[2*v+1]-tmp;
}

typ query(int v, int l, int r, int a, int b)
{
	if(a>r || l>b)
		return mp(0, mp(0, 0));

	if(a<=l && r<=b)
		return mp(res[v], mp(o[v], c[v]));

	typ L = query(2*v, l, (l+r)/2, a, b);
	typ R = query(2*v+1, (l+r)/2+1, r, a, b);

	int tmp = min(L.nd.st, R.nd.nd);
	return mp(L.st+R.st+tmp, mp(L.nd.st+R.nd.st-tmp, L.nd.nd+R.nd.nd-tmp));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = s.size();
	s = '#'+s;
	
	build(1, 0, M-1);	

	cin >> q;

	while(q--)
	{
		cin >> a >> b;
		cout << 2*query(1, 0, M-1, a, b).st << endl;
	}
}