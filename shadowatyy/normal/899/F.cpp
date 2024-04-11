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
const int M = 1<<18;

int n, m;

string s;

set<int> S[256];

int sub[2*M];

void insert(int a)
{
	a += M-1;

	while(a)
	{
		--sub[a];
		a /= 2;
	}
}

int kth(int k, int v = 1, int l = 1, int r = M)
{
	if(l==r)
		return l;

	if(sub[2*v]>=k)
		return kth(k, 2*v, l, (l+r)/2);
	else
		return kth(k-sub[2*v], 2*v+1, (l+r)/2+1, r);
}

void build(int v = 1, int l = 1, int r = M)
{
	sub[v] = r-l+1;

	if(l==r)
		return;

	build(2*v, l, (l+r)/2);
	build(2*v+1, (l+r)/2+1, r);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> s;
	s = '#'+s;

	for(int i = 1; i <= n; ++i)
	{
		S[s[i]].insert(i);
	}

	build();

	while(m--)
	{
		int l, r;
		char c;
		cin >> l >> r >> c;

		l = kth(l);
		r = kth(r);

		auto it = S[c].lower_bound(l);

		while(it!=S[c].end() && *it<=r)
		{
			insert(*it);
			S[c].erase(it);
			it = S[c].lower_bound(l);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(S[s[i]].find(i)!=S[s[i]].end())
			cout << s[i];
	}

	cout << endl;
}