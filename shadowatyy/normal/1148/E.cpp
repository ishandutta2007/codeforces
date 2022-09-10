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
#define int ll

int n;

int s[N];
int t[N];
int curr[N];
int kon[N];

VPII S, T;

set<PII> prawo, lewo;

vector<VI> ans;

void no()
{
	cout << "NO" << endl;
	exit(0);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		cin >> s[i];
		S.eb(s[i], i);
	}

	for(int i = 1; i <= n; ++i)
	{
		cin >> t[i];
		T.eb(t[i], i);
	}

	sort(ALL(S));
	sort(ALL(T));

	for(int i = 0; i < n; ++i)
	{
		curr[S[i].nd] = S[i].st;
		kon[S[i].nd] = T[i].st;

		if(T[i].st-S[i].st>0)
			prawo.insert(S[i]);
		else if(T[i].st-S[i].st<0)
			lewo.insert(S[i]);
	}

	for(auto it:prawo)
	{
		int ind = it.nd;
		
		while(kon[ind]-curr[ind])
		{
			int chce = kon[ind]-curr[ind];
			auto wez = lewo.lower_bound(mp(it.st, -1));

			if(wez==lewo.end())
				no();

			int on = wez->nd;
			int rusz = min(chce, abs(kon[on]-curr[on]));
			ans.eb((VI){ind, on, rusz});
			curr[ind] += rusz;
			curr[on] -= rusz;

			if(curr[ind]>curr[on])
				no();

			if(curr[on]==kon[on])
				lewo.erase(wez);
		}
	}

	for(int i = 1; i <= n; ++i)
	{
		if(curr[i]!=kon[i])
			no();
	}

	cout << "YES" << endl;

	cout << siz(ans) << endl;

	for(auto it:ans)
	{
		cout << it[0] << " " << it[1] << " " << it[2] << endl;
	}
}