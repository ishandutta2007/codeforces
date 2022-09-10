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

const int N = 1<<19;

struct tree
{
	ll load[2*N];
	ll sub[2*N];
	ll lazy[2*N];

	void push(int v)
	{
		int u = v<<1;
		lazy[u] += lazy[v];
		sub[u] += lazy[v];
		lazy[u^1] += lazy[v];
		sub[u^1] += lazy[v];
		lazy[v] = 0;
	}

	void insert(int a, int b, ll c, int v = 1, int l = 0, int r = N-1)
	{
		if(a>r || l>b)
			return;

		if(a<=l && r<=b)
		{
			lazy[v] += c;
			sub[v] += c;
			return;
		}

		push(v);
		insert(a, b, c, 2*v, l, (l+r)/2);
		insert(a, b, c, 2*v+1, (l+r)/2+1, r);
		sub[v] = min(sub[2*v], sub[2*v+1]);
	}

	ll query(int a, int b, int v = 1, int l = 0, int r = N-1)
	{
		if(a>r || l>b)
			return INF;

		if(a<=l && r<=b)
			return sub[v];

		push(v);
		ll ans = min(query(a, b, 2*v, l, (l+r)/2), query(a, b, 2*v+1, (l+r)/2+1, r));
		sub[v] = min(sub[2*v], sub[2*v+1]);
		return ans;
	}
};

int n;

ll sum;

tree raz, dwa, trzy;

int a[N];
ll pref[N];
ll suf[N];

ll sufiks(int x, int minuj)
{
	if(x==n)
		return 0;

	int l = x+1, r = n+1;

	while(l<r)
	{
		int m = (l+r)/2;

		if(a[m]<=minuj)
			r = m;
		else
			l = m+1;
	}

	//debug(l);

	//debug(pref[n] - pref[l-1]);

	return (ll)minuj*(l-1-x) + pref[n] - pref[l-1];
}	

bool moja(int d, int poz)
{
	return (ll)poz*(poz-1) + sufiks(poz-1, poz) - (pref[poz-1]+d) >= 0;
}

bool check(int d)
{
	if((sum+d)%2)
		return 0;

	int l = 1, r = n+1;

	while(l<r)
	{
		int m = (l+r)/2;

		if(a[m]<=d)
			r = m;
		else
			l = m+1;
	}

	int poz = l;
	debug(I(poz));
	debug(I(raz.query(1, 1)));

	raz.insert(d+1, poz-1, d);
	dwa.insert(poz, n, -d);

	bool ok = 1;

	if(raz.query(d+1, poz-1)<0)
		ok = 0;

	if(dwa.query(poz, n)<0)
		ok = 0;

	debug(I(dwa.query(poz, poz)), I(poz));

	if(trzy.query(1, d)<0)
		ok = 0;

	if(!moja(d, poz))
		ok = 0;

	raz.insert(d+1, poz-1, -d);
	dwa.insert(poz, n, d);

	debug(I(ok));
	return ok;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a+1, a+1+n);
	reverse(a+1, a+1+n);

	for(int i = 1; i <= n; ++i)
	{
		pref[i] = pref[i-1] + a[i];
	}

	for(int i = 1; i <= n; ++i)
	{
		debug(I(i), I(a[i]));
	}

	//debug(sufiks(1, 1));
	//return 0;

	//debug(sufiks(14, 14));
	//debug(pref[14]+21);
	//return 0;

	for(int i = 1; i <= n; ++i)
	{
		raz.insert(i, i, (ll)i*(i-1));
		raz.insert(i, i, -pref[i]);
		raz.insert(i, i, sufiks(i, i));
		debug(I(i), raz.query(i, i));

		dwa.insert(i, i, (ll)i*(i+1));
		dwa.insert(i, i, -pref[i]);
		dwa.insert(i, i, sufiks(i, i+1));
	}

	trzy = raz;

	for(int i = 1; i <= n; ++i)
	{
		trzy.insert(i, i, i);
	}

	//debug(check(0));
	//return 0;
	//debug(I(dwa.query(14, 14)));
	//return 0;

	VI ans;
 
	for(int i = 0; i <= n; ++i)
	{
		if(check(i))
			ans.pb(i);
	}

	if(ans.empty())
		cout << -1 << endl;
	else
	{
		for(auto it:ans)
			cout << it << " ";

		cout << endl;
	}
}