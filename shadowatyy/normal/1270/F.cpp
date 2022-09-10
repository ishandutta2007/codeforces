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

#ifndef LOCAL
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#else
#include</Users/dawid/algo/mac/ordered_set>
#endif

const int N = 2e5+7;

int n;

int a[N];
int p[N];

string s;

ll ans;

int brakuje_zer[N];
int za_duzo_zer[N];
int lewo[N];

void solve(int l, int r)
{
	if(l==r)
	{
		if(a[l])
			++ans;

		return;
	}

	int len = r-l+1;
	int s = floor(sqrt(len));
	int m = (l+r)/2;

	solve(l, m);
	solve(m+1, r);

	for(int x = 1; x <= s; ++x)
	{	
		int z = 0, j = 0;

		for(int i = m; i >= l; --i)
		{
			if(a[i])
				++j;
			else
				++z;

			int chce_zer = (x-1)*j;

			if(abs(z - chce_zer) > len)
				continue;

			if(z >= chce_zer)
				za_duzo_zer[z - chce_zer]++;
			else
				brakuje_zer[chce_zer - z]++;
		}

		z = 0;
		j = 0;

		for(int i = m+1; i <= r; ++i)
		{
			if(a[i])
				++j;
			else
				++z;

			int chce_zer = (x-1)*j;

			if(abs(z - chce_zer) > len)
				continue;

			if(z <= chce_zer)
				ans += za_duzo_zer[chce_zer - z];
			else
				ans += brakuje_zer[z - chce_zer];
		}

		for(int i = 0; i <= len; ++i)
		{
			brakuje_zer[i] = za_duzo_zer[i] = 0;
		}
	}

	//debug(I(l), I(r), I(m));

	//int x = ans;

	for(int i = m+1; i <= r; ++i)
	{
		int curr = i;

		if(!a[curr])
			curr = lewo[curr];

		for(int j = 1; j <= s && curr; ++j)
		{
			int x = max(l, lewo[curr]+1);
			int y = curr;
			y = min(y, m);
			y = min(y, i-(s+1)*j+1);

			//if(x<=y)
			//	debug(I(m), I(s), I(j), I(curr), I(i), I(x), I(y));

			if(x<=y)
			{
				int len = i - y + 1;
				int curr_mod = len%j;
				int seg = y-x;
				ans += seg/j;
				seg %= j;

				if(!curr_mod)
					++ans;
				else if(curr_mod + seg >= j)
					++ans;
			}

			curr = lewo[curr];
		}
	}

	/*x = ans - x;

	int y = 0;

	for(int a = l; a <= m; ++a)
	{
		for(int b = m+1; b <= r; ++b)
		{
			int j = p[b]-p[a-1];
			int len = b-a+1;

			if(j && len%j==0 && len/j>s)
				++y;
		}
	}*/

	/*if(x!=y)
	{
		debug(x, y);
		exit(0);
	}*/
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> s;
	n = siz(s);
	//debug(s);

	int last = 0;

	for(int i = 1; i <= n; ++i)
	{
		a[i] = s[i-1]-'0';
		lewo[i] = last;

		if(a[i])
			last = i;

		p[i] = p[i-1] + a[i];
	}

	solve(1, n);

	cout << ans << endl;
}