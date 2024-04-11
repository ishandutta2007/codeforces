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

const int N = 1e5+7;

int n, k;

int t[N];

VI B, C;

void f()
{
	cout << "tokitsukaze" << endl;
	exit(0);
}

void s()
{
	cout << "quailty" << endl;
	exit(0);
}

void d()
{
	cout << "once again" << endl;
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	for(int i = 1; i <= n; ++i)
	{
		char c;
		cin >> c;
		t[i] = c-'0';

		if(t[i])
			C.pb(i);
		else
			B.pb(i);
	}

	if(C.empty() || B.empty() || B.back()-B[0]+1<=k || C.back()-C[0]+1<=k)
		f();

	debug(C, B);

	bool lose = 1;

	for(int i = 1; i+k-1 <= n; ++i)
	{	
		for(int j = 0; j < 2; ++j)
		{
			//maluje na czarno

			int l = i;
			int r = i+k-1;
			int lb = inf, rb = -inf;

			auto it = upper_bound(ALL(B), r);

			if(it!=B.end())
				mini(lb, *it);

			if(B[0]<l)
				mini(lb, B[0]);

			it = lower_bound(ALL(B), l);

			if(it!=B.begin())
			{
				--it;
				maxi(rb, *it);
			}

			if(B.back()>r)
				maxi(rb, B.back());

			int lc = min(C[0], l);
			int rc = max(C.back(), r);

			if(rc-lc+1>k && rb-lb+1>k)
				lose = 0;

			debug(lc, rc, lb, rb);

			swap(B, C);
		}
	}

	if(lose)
		s();
	else
		d();
}