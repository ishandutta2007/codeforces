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

const int N = 1e5+7;
#define int long long

int n, curr = 1;

int a[N];
int t[60*N][2];
int ile[60*N];
int sub[60*N];

VI ans;

int fb(int v)
{
	return 63-__builtin_clzll(v);
}

void insert(int v, int val)
{
	int s = 1;
	VI vis;

	for(int i = 59; i >= 0; --i)
	{
		vis.pb(s);
		int chce = bool(v&(1ll<<i));

		if(!t[s][chce])
			t[s][chce] = ++curr;

		s = t[s][chce];
	}

	ile[s] += val;

	if(ile[s])
		sub[s] = 1ll<<fb(v);
	else
		sub[s] = 0;

	reverse(ALL(vis));

	for(auto it:vis)
	{
		sub[it] = sub[t[it][0]]|sub[t[it][1]];
	}
}

int find(int x)
{
	int s = 1, ans = 0;

	for(int i = 59; i >= 0; --i)
	{
		int chce = bool(x&(1ll<<i));

		if(sub[t[s][chce]]&~x)
		{
			s = t[s][chce];
			ans += (1ll<<i)*chce;
		}
		else if(sub[t[s][!chce]]&~x)
		{
			s = t[s][!chce];
			ans += (1ll<<i)*(!chce);
		}
		else
		{
			cout << "No" << endl;
			exit(0);
		}
	}

	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		insert(a[i], 1);
	}

	int x = 0;
	
	for(int i = 1; i <= n; ++i)
	{
		int f = find(x);
		x ^= f;
		ans.pb(f);
		insert(f, -1);
	}

	cout << "Yes" << endl;

	for(auto it:ans)
		cout << it << " ";
}