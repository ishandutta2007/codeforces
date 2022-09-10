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

#define N 100007
#define M inf

ll res;

string s;

int n, k;

int a[N];

ll fact[N];
ll pot[N];
ll sum[N];

ll fpow(ll a, int w)
{
	if(w==0)
		return 1;

	if(w==1)
		return a%M;

	if(w%2)
		return fpow(a, w-1)*a%M;
	else
	{
		ll q = fpow(a, w/2);
		return q*q%M;
	}
}

ll inv(ll a)
{
	return fpow(a, M-2);
}

ll dwumian(int n, int k)
{
	if(k>n)
		return 0;

	return fact[n]*inv(fact[k])%M*inv(fact[n-k])%M;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = pot[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = fact[i-1]*i%M;
		pot[i] = pot[i-1]*10%M;
	}

	cin >> n >> k >> s;

	reverse(ALL(s));

	for(int i = 0; i < n; ++i)
	{
		a[i] = s[i]-'0';
		sum[i] += a[i];
		sum[i] %= M;
		sum[i+1] += sum[i];
	}

	for(int p = 0; p < n; ++p)
	{
		res += pot[p]*(sum[n-1]-sum[p])%M*dwumian(n-p-2, k-1)%M;
		res += pot[p]*a[p]%M*dwumian(n-p-1, k)%M;
		res %= M;
		res += M;
		res %= M;
	}	

	cout << res;
}