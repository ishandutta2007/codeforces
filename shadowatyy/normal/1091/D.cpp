#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define eb emplace_back
#define mp make_pair
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "

#define int ll
const int mod = 998244353;
const int N = 1e6+7;

int n;

int fact[N];
int lcp[N];
int inv[N];

int fpow(int a, int b)
{
	int res = 1;

	while(b)
	{
		if(b&1)
			res = res*a%mod;

		a = a*a%mod;
		b /= 2;
	}

	return res;
}

int kom(int n, int k)
{
	if(k<0 || k>n)
		return 0;

	return fact[n]*inv[n-k]%mod*inv[k]%mod;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	fact[0] = 1;

	for(int i = 1; i < N; ++i)
	{
		fact[i] = i*fact[i-1]%mod;
	}

	inv[N-1] = fpow(fact[N-1], mod-2);

	for(int i = N-2; i >= 0; --i)
	{
		inv[i] = (i+1)*inv[i+1]%mod;
	}

	int ans = fact[n];
	//int sum = 0;

	for(int i = n-2; i >= 1; --i)
	{
		/*lcp[i] = kom(n, i)*fact[i]%mod*(fact[n-i]*fact[n-i-1]/2%mod)%mod;
		lcp[i] -= sum;
		lcp[i] %= mod;
		sum += lcp[i];
		sum %= mod;*/
		//ans += (n*(n-1)/2)%mod*kom(n-2, i)%mod*fact[i]%mod*fact[n-i-1]%mod*fact[n-i-1]%mod;
		ans += kom(n, i)*fact[i]%mod*(fact[n-i]-1)%mod;
		//debug(i, kom(n, i), fact[i], (fact[n-i]*(fact[n-i]-1)/2));
		ans %= mod;
	}

	//ans += sum;

	cout << ans << endl;
}