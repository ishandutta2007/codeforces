/* by Hyperhydrochloric Acid */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

template<typename tp, const tp &f(const ll&, const ll&)> struct Min25 {
	ll n;
	int lim, cnt, tot;
	vector<int> pr, shy, id1, id2;
	vector<ll> dd;
	vector<tp> fp, sm, nsm, tmp;
	void inline init(ll _n) {
		n = _n; pr.pub(0);
		lim = (ll)sqrtl(n) + 1;
		shy.resize(lim + 1);
		circ(i, 2, lim) {
			if(!shy[i]) pr.pub(i);
			cont(j, SZ(pr) - 1) {
				if(1ll * i * pr[j] > lim) break;
				shy[i * pr[j]] = 1;
				if(!(i % pr[j])) break;
			}
		}
		cnt = SZ(pr) - 1;
		sm.resize(cnt + 1); nsm.resize(cnt + 1);
		id1.resize(lim + 1);
		id2.resize(lim + 1);
		for(ll l = 1, r; l <= n; l = r + 1) {
			ll x = n / l; r = n / x;
			if(x <= lim) id1[x] = SZ(dd), dd.pub(x);
			else id2[n / x] = SZ(dd), dd.pub(x);
		}
		tot = SZ(dd);
		tmp.resize(tot);
		fp.assign(tot, 0);
	}
	int inline getid(ll x) {return x <= lim ? id1[x] : id2[n / x];}
	//  g gp x = add(x, nx) 
	template<typename T1, typename T2, typename T3>
	void inline addfunc(const T1 &g, const T2 &gp, const T3 &add) {
		cont(i, cnt) sm[i] = sm[i - 1] + g(pr[i]), nsm[i] = add(nsm[i], sm[i]);
		loop(i, tot) tmp[i] = gp(dd[i]) - 1;
		cont(i, cnt) {
			int p = pr[i];
			loop(j, tot) {
				ll n = dd[j];
				if(1ll * p * p > n) break;
				tmp[j] -= (tmp[getid(n / p)] - sm[i - 1]) * g(p);
			}
		}
		loop(i, tot) fp[i] = add(fp[i], tmp[i]);
	}
	// 
	tp inline get(ll n, int i) {
		if(i > cnt) return fp[getid(n)] - nsm[i - 1];
		int p = pr[i];
		if(n <= 1 || p > n) return 0;
		tp res = fp[getid(n)] - nsm[i - 1];
		circ(j, i, cnt) {
			if(1ll * pr[j] * pr[j] > n) break;
			ll np = pr[j];
			int k = 1;
			while(np * pr[j] <= n) {
				res += f(pr[j], k) * get(n / np, j + 1);
				res += f(pr[j], k + 1);
				++k; np *= pr[j];
			}
		}
		return res;
	}
	tp inline get() {
		return get(n, 1) + 1;
	}
};

Min25<ll, max> m25;
ll n;

int main() {
	cin >> n;
	m25.init(n);
	m25.addfunc([&](ll a) {return 1;}, [&](ll a) {return a;}, [&](ll a, ll b) {return a + b;});
	ll ans = 0, lst = 0;
	for(ll l = 1, r; l <= n; l = r + 1) {
		ll x = n / l; r = n / x;
		ll s = m25.fp[m25.getid(r)];
		ans += (s - lst) * m25.fp[m25.getid(x)];
		lst = s;
	}
	for(ll i = 2; i * i <= n; ++i) ans -= !m25.shy[i];
	ans >>= 1;
	for(ll i = 2; i * i * i <= n; ++i) ans += !m25.shy[i];
	printf("%lld\n", ans);
	return 0;
}