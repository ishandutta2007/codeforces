#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
//define s second
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

const int N = 2507;

int n, curr;

ll ans, cnt;

int x[N];
int y[N];

bool prawo(int a, int b, int c)
{
	return (ll)(x[c]-x[a])*(y[b]-y[a])-(ll)(x[b]-x[a])*(y[c]-y[a]) > 0;
}

bool comp(int a, int b)
{
	return prawo(curr, b, a);
}

void solve(int s)
{
	VI u, l;

	for(int i = 1; i <= n; ++i)
	{
		if(i==s)
			continue;

		if(y[i]>y[s] || (y[i]==y[s] && x[i]>x[s]))
			u.pb(i);
		else
			l.pb(i);
	}

	curr = s;
	sort(ALL(u), comp);
	sort(ALL(l), comp);

	u.insert(u.end(), ALL(l));

	int far = 0;
	int k = n-1;

	for(int i = 0; i < k; ++i)
	{
		while((far+1)%k!=i && prawo(u[i], curr, u[(far+1)%k]))
			far = (far+1)%k;

		int ile = far - i;

		if(ile<0)
			ile += k;

		//debug(curr, u[i], u[far], ile);

		cnt += (ll)ile*(k-1-ile);

		if(far == i)
			far = (far+1)%k;
	}

	/*for(int i = 0; i < n-1; ++i)
	{
		for(int j = i+1; j < n-1; ++j)
		{
			for(int k = j+1; k < n-1; ++k)
			{
				if(prawo(u[i], curr, u[j]) && prawo(u[j], curr, u[k]) && prawo(u[k], curr, u[i]))
					++ans, debug(curr, u[i], u[j], u[k]);
			}
		}
	}*/
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> x[i] >> y[i];
	}

	ll p = (ll)n*(n-1)*(n-2)*(n-3)/24;

	for(int i = 1; i <= n; ++i)
		solve(i);

	debug(cnt);
	cout << (cnt-4*p)*(n-4)/4 << endl;
}