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

const int N = 2007;

int n;

int sito[N];
int moge[N];

VPII ans;

set<PII> ban;

int juz[N];

void solve(int x)
{
	if(!sito[x])
	{
		for(int i = 1; i < x; ++i)
		{
			ans.eb(i, i+1);
		}

		ans.eb(x, 1);
		return;
	}
	else
	{
		for(int i = 3; i < x; ++i)
		{
			if(!sito[i] && moge[x-i])
			{
				solve(x-i);

				for(int j = x-i+1; j < x; ++j)
				{
					ans.eb(j, j+1);
				}

				ans.eb(x, x-i+1);
				return;
			}
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	for(int i = 2; i < N; ++i)
	{
		for(int j = 2*i; j < N; j += i)
		{
			sito[j] = 1;
		}
	}

	for(int i = 3; i < N; ++i)
	{
		if(!sito[i])
			moge[i] = 1;
	}

	for(int i = 4; i < N; ++i)
	{
		for(int j = 3; j < i; ++j)
		{
			if(!sito[j] && moge[i-j])
				moge[i] = max(moge[i], moge[i-j]+1);
		}
	}

	/*for(int i = 3; i < N; ++i)
	{
		if(!moge[i])
			cout << i << " ";
	}*/

	cin >> n;

	if(n==4)
	{
		cout << 5 << endl;
		cout << 1 << " " << 2 << endl;
		cout << 2 << " " << 3 << endl;
		cout << 3 << " " << 4 << endl;
		cout << 4 << " " << 1 << endl;
		cout << 1 << " " << 3 << endl;
		return 0;
	}

	solve(n);

	for(auto it:ans)
		ban.insert(it);

	for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			if(!sito[siz(ans)] || juz[i] || juz[j])
				continue;

			if(!ban.count(mp(i, j)) && !ban.count(mp(j, i)))
			{
				ans.eb(i, j);
				ban.insert(mp(i, j));
				juz[i] = juz[j] = 1;
			}
		}
	}

	assert(!sito[siz(ans)]);

	cout << siz(ans) << endl;

	for(auto it:ans)
		cout << it.st << " " << it.nd << endl;
}