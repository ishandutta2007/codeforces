#include <bits/stdc++.h>
#include <unistd.h>
#define int long long
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
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
using namespace std;

#define N 200007

int n, m, a;

bool zero = 1;

bitset<N> zle;

VI v[N];

int dp[N];

int p[N];

PII ext(int a, int b)
{
	if(b==0)
		return mp(1, 0);

	PII q = ext(b, a%b);

	return mp(q.nd, q.st-q.nd*(a/b));
}

int znajdz(int a, int b, int k)
{
	int g = __gcd(a, k);

	a /= g;
	b /= g;
	k /= g;

	return ((b*ext(k, a).nd)%k+k)%k;
}

VI pro, res;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a;

		zle[a] = 1;
	}

	for(int i = 1; i < m; ++i)
	{
		if(!zle[i])
			v[__gcd(m, i)].pb(i);
	}

	for(int i = 1; i < m; ++i)
	{
		dp[i] = v[i].size();
	}

	for(int i = m-1; i >= 1; --i)
	{
		for(int j = 1; j*j <= i; ++j)
		{
			if(i%j==0)
			{
				if(i!=i/j && dp[i/j]<v[i/j].size()+dp[i])
				{
					dp[i/j] = v[i/j].size()+dp[i];
					p[i/j] = i;
				}

				if(i!=j && dp[j]<v[j].size()+dp[i])
				{
					dp[j] = v[j].size()+dp[i];
					p[j] = i;
				}
			}
		}
	}

	int q = 1;

	for(int i = 1; i < m; ++i)
	{
		if(dp[i]>dp[q])
			q = i;
	}

	if(!v[q].empty())
	{
		for(int i = 0; i < v[q].size(); ++i)
		{
			pro.pb(v[q][i]);
		}

		while(p[q])
		{
			q = p[q];

			for(int i = 0; i < v[q].size(); ++i)
			{
				pro.pb(v[q][i]);
			}
		}
	}

	if(!pro.empty())
		res.pb(pro[0]);

	for(int i = 0; i < (int)pro.size()-1; ++i)
	{
		res.pb(znajdz(pro[i], pro[i+1], m));
	}

	if(!zle[0])
		res.pb(0);

	cout << res.size() << endl;

	for(auto it:res)
	{
		cout << it << " ";
	}
}