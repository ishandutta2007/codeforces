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

#define int ll
const int N = 2007;

int t, n, m, mus;

int p[N];

int a[N];
int b[N];

set<PII, greater<PII> > S;

void ja()
{		
	if(mus)
	{
		cout << mus << endl;
		fflush(stdout);
		S.erase(mp(p[mus], mus));
		return;
	}

	if(S.size()==1)
	{
		cout << S.begin()->nd << endl;
		fflush(stdout);
		S.erase(S.begin());
		return;
	}

	int ind = -1;
	int zysk = S.begin()->st - next(S.begin())->st;

	for(int i = 1; i <= m; ++i)
	{
		if(S.count(mp(p[a[i]], a[i])) && S.count(mp(p[b[i]], b[i])))
		{
			if(p[a[i]]<p[b[i]])
				swap(a[i], b[i]);

			int curr = p[a[i]]-p[b[i]];

			if(curr>zysk)
			{
				zysk = curr;
				ind = i;
			}
		}
	}

	if(ind==-1)
	{
		cout << S.begin()->nd << endl;
		fflush(stdout);
		S.erase(S.begin());
	}
	else
	{
		cout << a[ind] << endl;
		fflush(stdout);
		S.erase(mp(p[a[ind]], a[ind]));
	}
}

void oni()
{
	mus = 0;
	int x;
	cin >> x;
	S.erase(mp(p[x], x));

	for(int i = 1; i <= n; ++i)
	{
		if(a[i]==x && S.count(mp(p[b[i]], b[i])))
			mus = b[i];

		if(b[i]==x && S.count(mp(p[a[i]], a[i])))
			mus = a[i];
	}
}

int32_t main()
{
	cin >> n >> m;

	for(int i = 1; i <= 2*n; ++i)
	{
		cin >> p[i];
		S.insert(mp(p[i], i));
	}

	for(int i = 1; i <= m; ++i)
	{
		cin >> a[i] >> b[i];
	}

	cin >> t;

	for(int i = 1; i <= n; ++i)
	{
		if(t==1)
		{
			ja();
			oni();
		}
		else
		{
			oni();
			ja();
		}
	}
}