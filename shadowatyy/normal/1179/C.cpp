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

const int N = 1<<20;

int n, m, q;

int a[N];
int b[N];

struct tree
{
	int load[2*N];
	int Min[2*N];

	void insert(int a, int b, int c, int v = 1, int l = 0, int r = N-1)
	{
		if(a>r || l>b)
			return;

		if(a<=l && r<=b)
		{
			load[v] += c;
			Min[v] += c;
			return;
		}

		insert(a, b, c, 2*v, l, (l+r)/2);
		insert(a, b, c, 2*v+1, (l+r)/2+1, r);
		Min[v] = load[v] + min(Min[2*v], Min[2*v+1]);
	}

	int znajdz(int v = 1, int path = 0, int l = 0, int r = N-1)
	{
		if(l==r)
			return l;

		if(path+load[v]+Min[2*v+1]<0)
			return znajdz(2*v+1, path+load[v], (l+r)/2+1, r);
		else if(path+load[v]+Min[2*v]<0)
			return znajdz(2*v, path+load[v], l, (l+r)/2);
		else
			return -1;
	}
}T;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		T.insert(0, a[i], -1);
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> b[i];
		T.insert(0, b[i], +1);
	}

	cin >> q;

	for(int i = 1; i <= q; ++i)
	{
		int t, ind, x;

		cin >> t >> ind >> x;

		if(t==1)
		{
			T.insert(0, a[ind], +1);
			a[ind] = x;
			T.insert(0, a[ind], -1);
		}
		else
		{
			T.insert(0, b[ind], -1);
			b[ind] = x;
			T.insert(0, b[ind], +1);
		}

		cout << T.znajdz() << endl;
	}
}