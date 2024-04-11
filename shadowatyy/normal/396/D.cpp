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

const int N = 1e6+7;
const int MOD = 1e9+7;
const int inv4 = 250000002;
const int inv2 = 500000004;

int n;

ll ans;

ll pref[N];
ll suf[N];

int p[N];
int f[N];
ll fact[N];

int query(int a, int b)
{
	if(a>b)
		return 0;

	--a;

	int res = 0;

	while(a>0)
	{
		res -= f[a];
		a -= (a&-a);
	}

	while(b>0)
	{
		res += f[b];
		b -= (b&-b);
	}

	return res;
}

void insert(int a, int v)
{
	while(a<=n)
	{
		f[a] += v;
		a += (a&-a);
	}
}

void prefiks()
{
	fill(f, f+N, 0);

	for(int i = 1; i <= n; ++i)
	{
		pref[i] = (pref[i-1]+query(p[i]+1, n))%MOD;
		insert(p[i], 1);
	}
}


void sufiks()
{
	fill(f, f+N, 0);

	for(int i = n; i >= 1; --i)
	{
		suf[i] = (suf[i+1]+query(1, p[i]-1))%MOD;
		insert(p[i], 1);
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = (fact[i-1]*i)%MOD;
	}

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	sufiks();
	prefiks();

	fill(f, f+N, 0);

	for(int i = 1; i <= n; ++i)
	{
		insert(i, 1);
	}

	for(int i = 1; i <= n; ++i)
	{
		ll q = query(1, p[i]-1);

		ans += q*fact[n-i]%MOD*(n-i)%MOD*(n-i-1)%MOD*inv4%MOD;
		ans += q*pref[i-1]%MOD*fact[n-i]%MOD;
		ans += q*fact[n-i]%MOD*(pref[n]-pref[i-1]-suf[i]+2*MOD)%MOD;
		ans += fact[n-i]*q%MOD*(q-1)%MOD*inv2%MOD;
		ans %= MOD;

		insert(p[i], -1);
	}

	cout << (ans+pref[n])%MOD;
}