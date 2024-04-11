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
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)
#define ll LL
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
#define siz(c) SIZ(c)
const int inf = 1e9+7;
const ll INF = 1e18L+7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " =", (x), " "

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

#define int ll 

// set<int> zle;

string bin(int x)
{
	// x /= 4;
	string ans;

	while(x)
	{
		ans += char('0'+x%2);
		x /= 2;
	}

	return ans;
}

// VI pref;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	// n = 10;

	// for(int i = 1; i <= n; ++i)
	// {
	// 	int a = 1;

	// 	while(zle.count(a))
	// 		++a;

	// 	int x = a+1;

	// 	while(zle.count(x) || zle.count(x^a))
	// 		++x;

	// 	// cout << i << "   " << bin(a) << " " << bin(x) << " " << bin(x^a) << endl;
	// 	pref.pb(a);
	// 	pref.pb(x);
	// 	pref.pb(x^a);

	// 	zle.insert(a);
	// 	zle.insert(x);
	// 	zle.insert(x^a);

	// 	// if(i%4==1)
	// 		// cout << endl;
	// }

	int t;
	cin >> t;

	for(int i = 1; i <= t; ++i)
	{
		int n = i;
		cin >> n;

		if(n<=3)
		{
			cout << n << endl;
			continue;
		}

		int tro = (n+2)/3 - 2;
		int czw = tro/4;
		int mod_czw = tro%4;

		int a = 0;
		int bit = -1;

		for(int fsb = 0; ; fsb += 2)
		{
			int ile = 1LL<<fsb;

			if(czw < ile)
			{
				bit = fsb;
				a = (1LL<<bit) + czw;
				break;
			}
			else
			{
				tro -= 4*ile;
				czw -= ile;
			}
		}

		int b = 1LL<<(bit+1);

		// debug(a, b, bit+1, tro);

		int trb = 8;

		for(int i = 0; i < bit+1; ++i)
		{
			// debug(I(i), I(trb), I(tro % (2*trb)));

			if(i%2==0)
			{
				if(tro % (2*trb) >= trb)
					b |= 1LL<<i;
			}
			else
			{
				int tmp = tro % (2*trb);

				if(trb/2 <= tmp && tmp < 3*trb/2)
					b |= 1LL<<i;
			}

			if(i%2)
				trb *= 4;
		}

		a *= 4;
		b *= 4;

		a += mod_czw;
		
		if(mod_czw==0)
			b += 0;
		else if(mod_czw==1)
			b += 2;
		else if(mod_czw==2)
			b += 3;
		else
			b += 1;

		int c = (a^b);

		// if(n%3==1)
		// 	cout << bin(a) << endl;
		// else if(n%3==2)
		// 	cout << bin(b) << endl;
		// else
		// 	cout << bin(c) << endl;

		if(n%3==1)
			cout << a << endl;
		else if(n%3==2)
			cout << b << endl;
		else
			cout << c << endl;
	}
}