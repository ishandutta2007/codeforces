#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
#define ST first
#define ND second
#define V vector
#define RS resize
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
#define S(a) (int)a.size()

template<class T> void db(T a) { cerr << a; }
template<class L, class R> void db(pair<L, R> a) { cerr << "(" << a.ST << ", " << a.ND << ")"; }
template<class T> void db(V<T> v) { cerr << "{"; REP(i, S(v)) cerr << (i != 0 ? ", " : ""), db(v[i]); cerr << "}"; }
template<class T> void dump(const char *s, T a) { cerr << s << ": "; db(a); cerr << "\n"; }
template<class T, class... TS> void dump(const char *s, T a, TS... x)
{ while(*s != ',') cerr<< *s++; cerr << ": "; db(a); dump(s + 1, x...); }

#ifdef DEBUG
#define DB(...) dump(#__VA_ARGS__, __VA_ARGS__); 
#else
#define DB(...)
#endif

using LL = long long;
using PII = pair<int, int>;
using VI = V<int>;
using VLL = V<LL>;
using VVI = V<VI>;
using VPII = V<PII>;

LL mod = 998244353;

LL p(LL base, LL n)
{
	if(n == 0)
		return 1;

	if(n % 2 == 1)
		return (base * p(base, n - 1)) % mod;

	LL x = p(base, n / 2);
	return (x * x) % mod;
}

LL div(LL b) { return p(b, mod - 2); }

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    VI v(n);
    V<bool> used(n);
    int s = 0;
    REP(i, n)
    {
    	cin >> v[i];
    	if(v[i] == -1)
    		s++;
    	else
    		used[v[i] - 1] = 1;
    }

	ordered_set numbers;
	int size = 0;
	LL sure_inversions = 0;
	
	REP(i, n)
	{
		if(v[i] != -1)
		{
			numbers.insert(v[i]);
			sure_inversions += size - numbers.order_of_key(v[i]);
			sure_inversions %= mod;
			size++;
		}
	}

    LL Q = 1;
    FOR(i, 2, s)
    {
    	Q *= i;
    	Q %= mod;
    }

    LL P = Q;
    P *= (1ll * s * (s - 1)) % mod;
    P %= mod;
    P *= div(4);
    P %= mod;

    DB(P);

    VI g(n);
    REP(i, n)
    {
    	if(i != 0)
	    	g[i] = g[i - 1];
	    g[i] += !used[i];
    }

    LL q = 1;
    FOR(i, 2, s - 1)
    {
    	q *= i;
    	q %= mod;
    }

    LL l = 0, r = s;
    REP(i, n)
    {
    	if(v[i] == -1)
    	{
    		l++, r--;
    		continue;
    	}

    	LL a = (((r * g[v[i] - 1]) % mod) * q) % mod + ((( l * (s - g[v[i] - 1])) % mod ) * q) % mod;

    	P += a;
    	P %= mod;
    }

    P = ((P * div(Q)) % mod + sure_inversions) % mod;
    cout << P << "\n";
}