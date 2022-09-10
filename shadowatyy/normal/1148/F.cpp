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
const int N = 3e5+7;

int n, s;

int val[N];
int mask[N];
int low[N];

int sgn(int x)
{
	if(x>0)
		return 1;
	else if(x==0)
		return 0;
	else 
		return -1;
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> val[i] >> mask[i];
		s += val[i];
		low[i] = 63-__builtin_clzll(mask[i]&(-mask[i]));
	}

	int curr = 0;

	for(int i = 62; i >= 0; --i)
	{
		int sum = 0;

		for(int j = 1; j <= n; ++j)
		{
			if(low[j]==i)
			{
				if(__builtin_popcountll(mask[j]&curr)%2)
					sum += -val[j];
				else
					sum += val[j];
			}
		}

		if(sgn(s)==sgn(sum))
			curr ^= 1LL<<i;
	}

	int kon = 0;

	for(int i = 1; i <= n; ++i)
	{
		if(__builtin_popcountll(mask[i]&curr)%2)
			kon += -val[i];
		else
			kon += val[i];
	}

	cout << curr << endl;
}