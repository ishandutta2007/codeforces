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
using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;

int n;

ll res;

string A, B;

ll fact[N];
ll inv[N];

int cnt[256];

ll fpow(ll a, int b)
{
	ll res = 1;

	for(int i = 0; i < 30; ++i)
	{
		if(b&(1<<i))
			res = res*a%MOD;

		a = a*a%MOD;
	}

	return res;
}

ll go(string X)
{
	ll res = 0;

	memset(cnt, 0, sizeof cnt);

	for(int i = 0; i < n; ++i)
	{
		++cnt[A[i]];
	}

	ll curr_suf = fact[n];

	for(int i = 'a'; i <= 'z'; ++i)
	{
		curr_suf *= inv[cnt[i]];
		curr_suf %= MOD;
	}

	for(int i = 0; i < n; ++i)
	{
		curr_suf *= inv[n-i];
		curr_suf %= MOD;
		curr_suf *= fact[n-i-1];
		curr_suf %= MOD;

		for(int j = X[i]+1; j <= 'z'; ++j)
		{
			if(cnt[j])
			{
				curr_suf *= fact[cnt[j]];
				curr_suf %= MOD;
				curr_suf *= inv[cnt[j]-1];
				curr_suf %= MOD;
				res += curr_suf;
				curr_suf *= fact[cnt[j]-1];
				curr_suf %= MOD;
				curr_suf *= inv[cnt[j]];
				curr_suf %= MOD;
			}
		}

		if(!cnt[X[i]])
			break;

		curr_suf *= fact[cnt[X[i]]];
		curr_suf %= MOD;
		--cnt[X[i]];
		curr_suf *= inv[cnt[X[i]]];
		curr_suf %= MOD;
	}

	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = inv[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%MOD;
		inv[i] = fpow(fact[i], MOD-2);
	}

	cin >> A >> B;

	n = A.size();

	res += go(A);
	res -= go(B);

	VI la, lb;

	for(auto it:A)
		la.pb(it);

	for(auto it:B)
		lb.pb(it);

	sort(ALL(la));
	sort(ALL(lb));

	if(la==lb)
		--res;

	cout << (res%MOD+MOD)%MOD;
}