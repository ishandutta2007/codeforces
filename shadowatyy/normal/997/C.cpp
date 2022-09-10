#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
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
using namespace std;

const int N = 1e6+7;
const int mod = 998244353;
#define int ll

int n;

int fact[N];
int inv[N];

int fpow(int a, int b)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = a*res%mod;

		a = a*a%mod;
		b /= 2;
	}

	return res;
}

int kom(int n, int k)
{
	return fact[n]*inv[k]%mod*inv[n-k]%mod;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	fact[0] = inv[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = i*fact[i-1]%mod;
		inv[i] = fpow(fact[i], mod-2);
	}

	cin >> n;

	if(n==1)
	{
		cout << 3 << endl;
		return 0;
	}

	int ans = 3*2*n*fpow(3, n*(n-1))%mod;

	for(int i = 1; i <= n; ++i)
	{
		int sum = fpow(1-fpow(3, n-i), n);
		
		if(n%2)
			sum += fpow(3, (n-i)*n);
		else
			sum -= fpow(3, (n-i)*n);

		if(n%2)
			sum = -sum;

		if(i%2)
			ans += 3*kom(n, i)*sum%mod;
		else
			ans -= 3*kom(n, i)*sum%mod;

		ans %= mod;
	}

	for(int i = 2; i <= n; ++i)
	{
		if(i%2==0)
			ans -= 2*kom(n, i)*fpow(3, i)%mod*fpow(3, (n-i)*n)%mod;
		else
			ans += 2*kom(n, i)*fpow(3, i)%mod*fpow(3, (n-i)*n)%mod;

		ans %= mod;
	}

	ans %= mod;
	ans += mod;
	ans %= mod;

	cout << ans << endl;
}