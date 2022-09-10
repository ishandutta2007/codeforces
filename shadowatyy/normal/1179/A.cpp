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

#define int ll
const int N = 1e5+7;

int n, mx, q;

int a[N];

deque<int> Q;

VPII pref;

VI cykl;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> q;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		mx = max(mx, a[i]);
		Q.push_back(a[i]);
	}

	while(Q.front()!=mx)
	{
		int A = Q.front();
		Q.pop_front();
		int B = Q.front();
		Q.pop_front();
		pref.eb(A, B);
		Q.push_front(max(A, B));
		Q.push_back(min(A, B));
	}

	Q.pop_front();

	while(!Q.empty())
	{
		cykl.pb(Q.front());
		Q.pop_front();
	}

	while(q--)
	{
		int x;
		cin >> x;

		if(x<=siz(pref))
			cout << pref[x-1].st << " " << pref[x-1].nd << endl;
		else
		{
			x -= siz(pref);
			--x;
			x %= siz(cykl);
			cout << mx << " " << cykl[x] << endl;
		}
	}
}