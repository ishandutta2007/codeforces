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

const LD eps = 1e-9;
const int N = 1<<20;

int n, R, ans;

LD r;

LD x[N];
LD y[N];

vector<LD> val;

vector<pair<LD, LD> > P;

int load[2*N];
int sub[2*N];

int lewo[N];
int prawo[N];

void insert(int a, int b, int c, int v = 1, int l = 0, int r = N-1)
{
	if(a>r || l>b)
		return;

	if(a<=l && r<=b)
	{
		load[v] += c;
		sub[v] += c;
		return;
	}

	insert(a, b, c, 2*v, l, (l+r)/2);
	insert(a, b, c, 2*v+1, (l+r)/2+1, r);
	sub[v] = max(sub[2*v], sub[2*v+1]) + load[v];
}

void add(int ind)
{
	insert(lewo[ind], prawo[ind], 1);
}

void del(int ind)
{
	insert(lewo[ind], prawo[ind], -1);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	LD pi = acos(-1);
	LD cosa = cos(pi/4);
	LD sina = sin(pi/4);

	cin >> n >> R;

	r = R*sqrt(2);

	for(int i = 1; i <= n; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		x[i] = cosa*X - sina*Y;
		y[i] = sina*X + cosa*Y;
		P.eb(x[i], y[i]);
		val.pb(y[i]);
		val.pb(y[i]+r);
	}

	sort(ALL(val));
	sort(ALL(P));

	for(int i = 0; i < n; ++i)
	{
		lewo[i] = lower_bound(ALL(val), P[i].nd-eps) - val.begin();
		prawo[i] = upper_bound(ALL(val), P[i].nd+r+eps) - val.begin() - 1;
	}

	int kon = -1;

	for(int poc = 0; poc < n; ++poc)
	{
		while(kon+1 < n && P[kon+1].st-P[poc].st<r+eps)
		{
			++kon;
			add(kon);
		}

		ans = max(ans, sub[1]);
		del(poc);
	}

	cout << ans << endl;
}