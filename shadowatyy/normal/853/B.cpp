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

const int N = 1e6+700;

int n, m, k;

ll res = INF;

int d[N];
int f[N];
int t[N];
ll c[N];

VI Q;

ll currA[N];
ll currB[N];

ll sumA[N];
ll sumB[N];

bitset<N> okA;
bitset<N> okB;

int calc(int a)
{
	if(f[a]!=0)
		return d[a]+1;
	else
		return d[a]-k;
}

bool compA(int a, int b)
{
	return calc(a)>calc(b);
}

bool compB(int a, int b)
{
	return calc(a)<calc(b);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for(int i = 1; i <= m; ++i)
	{
		cin >> d[i] >> f[i] >> t[i] >> c[i];
	}

	for(int i = 1; i <= m; ++i)
	{
		if(f[i]!=0)
			Q.pb(i);
	}

	sort(ALL(Q), compA);

	ll curr = 0;
	int ile_ok = 0;

	for(int i = 1; i+k-1 <= 1e6+7; ++i)
	{
		while(!Q.empty() && calc(Q.back())==i)
		{
			int l = Q.back();
			Q.pop_back();

			if(!okA[f[l]])
			{
				currA[f[l]] = c[l];
				++ile_ok;
				curr += c[l];
				okA[f[l]] = 1;
			}
			else
			{
				curr -= max(0ll, currA[f[l]]-c[l]);
				currA[f[l]] = min(currA[f[l]], c[l]);
			}
		}

		if(ile_ok==n)
			sumA[i] = curr;
		else
			sumA[i] = INF;
	}

	Q.clear();

	for(int i = 1; i <= m; ++i)
	{
		if(f[i]==0)
			Q.pb(i);
	}

	sort(ALL(Q), compB);

	curr = 0;
	ile_ok = 0;

	for(int i = 1e6+7-k+1; i >= 1; --i)
	{
		while(!Q.empty() && calc(Q.back())==i)
		{
			int l = Q.back();
			Q.pop_back();

			if(!okB[t[l]])
			{
				currB[t[l]] = c[l];
				++ile_ok;
				curr += c[l];
				okB[t[l]] = 1;
			}
			else
			{
				curr -= max(0ll, currB[t[l]]-c[l]);
				currB[t[l]] = min(currB[t[l]], c[l]);
			}
		}

		if(ile_ok==n)
			sumB[i] = curr;
		else
			sumB[i] = INF;
	}

	for(int i = 1; i+k-1 <= 1e6; ++i)
	{
		res = min(res, sumA[i]+sumB[i]);
	}

	if(res==INF)
		cout << -1;
	else
		cout << res;
}