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
const int MAX = 1e18L;
const int N = 1<<17;

int n, q;

int s[N];

PII pref[N];

PII norm(PII a)
{
	while(a.st<0)
	{
		a.st += MAX;
		a.nd -= 1;
	}

	a.nd += a.st/MAX;
	a.st %= MAX;
	return a;
}

PII mult(PII a, int b)
{
	a = norm(a);

	if(b==0)
		return mp(0LL, 0LL);

	if(b==1)
		return a;

	if(b%2==0)
	{
		PII ans = mult(mp(2*a.st, 2*a.nd), b/2);
		return norm(ans);
	}
	else
	{
		PII ans = mult(mp(2*a.st, 2*a.nd), b/2);
		ans.st += a.st;
		ans.nd += a.nd;
		return norm(ans);
	}
}

PII add(PII a, PII b)
{
	return norm(mp(a.st+b.st, a.nd+b.nd));
}

PII sub(PII a, PII b)
{
	return norm(mp(a.st-b.st, a.nd-b.nd));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	VI val;

	for(int i = 1; i <= n; ++i)
	{	
		int x;
		cin >> x;
		val.pb(x);
	}

	sort(ALL(val));
	val.erase(unique(ALL(val)), val.end());

	VI vec;

	for(int i = 0; i+1 < siz(val); ++i)
	{
		vec.pb(val[i+1]-val[i]-1);
	}

	sort(ALL(vec));

	for(int i = 0; i < siz(vec); ++i)
	{
		pref[i].st += vec[i];
		pref[i] = norm(pref[i]);

		pref[i+1].st += pref[i].st;
		pref[i+1].nd += pref[i].nd;
		pref[i+1] = norm(pref[i+1]);
	}

	cin >> q;

	while(q--)
	{
		int l, r;
		cin >> l >> r;

		int ind = upper_bound(ALL(vec), -(l-r))-vec.begin();
		PII ans = mp(val.back()+r - (val[0]+l) + 1, 0LL);
		PII sum = pref[siz(vec)-1];

		if(ind!=0)
			sum = sub(sum, pref[ind-1]);
	
		int ile = siz(vec)-ind;
		sum = sub(sum, mult(mp(r-l, 0LL), ile));
		ans = sub(ans, sum);

		int res = ans.st + MAX*ans.nd;

		cout << res  << endl;
	}
}