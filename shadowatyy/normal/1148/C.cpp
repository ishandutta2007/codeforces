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

const int N = 3e5+7;

int n;

int gdzie[N];
int p[N];

VPII ans;

void swapnij(int a, int b)
{
	swap(gdzie[p[a]], gdzie[p[b]]);
	swap(p[a], p[b]);
	ans.eb(a, b);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		gdzie[p[i]] = i;
	}

	for(int i = 2; i <= n-1; ++i)
	{
		if(p[i]==i)
			continue;

		if(gdzie[i]>n/2)
			swapnij(1, gdzie[i]);
		else
			swapnij(n, gdzie[i]);

		if(2*abs(i-gdzie[i])<n)
			swapnij(1, n);

		swapnij(i, gdzie[i]);
	}

	if(p[1]!=1)
		swapnij(1, n);

	for(int i = 1; i <= n; ++i)
	{
		assert(p[i]==i);
	}

	cout << siz(ans) << endl;

	for(auto it:ans)
		cout << it.st << " " << it.nd << endl;
}