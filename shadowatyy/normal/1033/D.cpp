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
#define siz(c) SIZ(c)
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

namespace RP{

	const int maxv = 50;
	const int maxc = 5007;
	const int maxp = 1e6 + 7;
	
	int cnt;
	int ptot;
	int d[maxp];	
	int pr[maxp];
	LL ans[maxc];
	
	inline LL mod(LL a, LL n){
		if(a >= n)	a -= n;
		return a;
	}
	
	inline LL add(LL a, LL b, LL n){
		a += b; mod(a, n);
		return a;
	}
	
	inline LL mul(LL x, LL y, LL p) {
		LL ret = x * y - (LL)((long double)x * y / p + 0.5) * p;
		return ret < 0 ? ret + p : ret;
	}
	
	LL fast(LL x, LL k, LL p){
		LL ret = 1%p;
		for(; k > 0; k >>= 1, x = mul(x, x, p))
			(k & 1) && (ret = mul(ret, x, p));
		return ret;
	}
	
	bool rabin(LL n){
		if(n == 2) return 1;
		if(n < 2 || !(n & 1))
			return 0;

		LL s = 0, r = n - 1;
		for(; !(r & 1); r >>= 1, ++s);
		for(int i = 0; pr[i] < n && pr[i] < maxv; ++i) {
			LL cur = fast(pr[i], r, n), nxt;
			for(int j = 0; j < s; ++j) {
				nxt = mul(cur, cur, n);
				if(nxt == 1 && cur != 1 && cur != n - 1) return false;
				cur = nxt;
			}

			if(cur != 1) return false;
		}

		return true;
	}

	#define ull unsigned LL

	ull gcd(ull u, ull v)
	{
	    int shift;
	    if (u == 0) return v;
	    if (v == 0) return u;
	    shift = __builtin_ctz(u | v);
	    u >>= __builtin_ctz(u);
	    do {
	        v >>= __builtin_ctz(v);
	        if (u > v) {
	            ull t = v;
	            v = u;
	            u = t;
	        }  
	        v = v - u;
	    } while (v != 0);
	    return u << shift;
	}
	
	LL factor(LL n) {
		static LL seq[maxp];
		while(true){
			LL x = rand()%n, y = x, c = rand()%n;
			LL *px = seq, *py = seq, tim = 0, prd = 1;
			
			while(true){
				*py++ = y = add(mul(y, y, n), c, n);
				*py++ = y = add(mul(y, y, n), c, n);
				if((x = *px++) == y) break;
				LL tmp = prd;
				prd = mul(prd, abs(y - x), n);
				if(!prd) return gcd(tmp, n);
				if((++tim) == maxv){
					if((prd = gcd(prd, n)) > 1 && prd < n) return prd;
					tim = 0;
				}
			}
			if(tim && (prd = gcd(prd, n)) > 1 && prd < n) return prd;
		}
	}

	void decompose(LL n) {

		for(int i = 0; i < cnt; ++i)
		{
			while(n%ans[i]==0)
			{
				n /= ans[i];
				ans[cnt++] = ans[i];
			}
		}

		if(n < maxp){
			while(n > 1)
				ans[cnt++] = d[n], n /= d[n];
		}
		else if(rabin(n))
			ans[cnt++] = n;
		else{
			LL fact = factor(n);
			decompose(fact), decompose(n / fact);
		}
	}
	
	void init(){
		d[1] = 1;
		for(int i = 2; i * i < maxp; ++i)
			if(!d[i])
				for(int j = i * i; j < maxp; j += i)
					d[j] = i;
		
		for(int i = 2; i < maxp; ++i)
			if(!d[i]){
				d[i] = i;
				pr[ptot++] = i;
			}
	}
	
	void clear(){
		cnt = 0;
	}
}

const ll mod = 998244353;

map<ll, int> mapa;

int n;

int32_t main()
{
	RP::init();

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		ll x;
		cin >> x;
		RP::decompose(x);
	}

	for(int i = 0; i < RP::cnt; ++i)
	{
		++mapa[RP::ans[i]];
	}

	ll ans = 1;

	for(auto it:mapa)
	{
		ans *= (it.nd+1);
		ans %= mod;
	}

	cout << ans << endl;
	fflush(stdout);
}