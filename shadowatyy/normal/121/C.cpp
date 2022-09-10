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

#define N 27

int n, k;

VI ln;

map<int, int> lucky;

ll fact[N];

bitset<N> used;

int kth(int k)
{
	for(int i = 1; i <= n; ++i)
	{
		if(!used[i])
			--k;

		if(k==0)
			return i;
	}

	return -1;
}

int brut()
{	
	int res = 0;

	for(int i = 1; i <= n; ++i)
	{
		int ile = k/fact[n-i];

		k -= fact[n-i]*ile;

		if(kth(ile+1)==-1)
			return -1;

		if(lucky[i] && lucky[kth(ile+1)])
			++res;

		used[kth(ile+1)] = 1;
	}

	return res;
}

int solve()
{
	int res = 0, skip = n-15;

	for(auto it:ln)
	{
		if(it<=skip)
			++res;
	}

	for(int i = 1; i <= 15; ++i)
	{
		int ile = k/fact[n-i-skip];

		k -= fact[n-i-skip]*ile;

		if(lucky[skip+i] && lucky[skip+kth(ile+1)])
			++res;

		used[kth(ile+1)] = 1;
	}

	return res;
}

void generuj(int l, int p)
{
	if(l)
		ln.pb(l);

	if(l+4ll*p<=n)
		generuj(l+4*p, 10*p);

	if(l+7ll*p<=n)
		generuj(l+7*p, 10*p);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i;
	}	

	cin >> n >> k;
	--k;

	generuj(0, 1);
	sort(ALL(ln));

	for(auto it:ln)
		lucky[it] = 1;

	if(n<=20)
		cout << brut();
	else
		cout << solve();	
}