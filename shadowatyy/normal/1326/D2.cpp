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

//Wzite std http://codeforces.com/blog/entry/12143
//zapisuje w tablicy p[0] promienie parzyste a w p[1] promienie nieparzyste
//promie nieparzystego p[1][x] to liczba liter w jednej powce nie liczc rodowej,
//tj. maksymalny palindrom to s[x - p[1][x]] ... s[x + p[1][x]]
//promie parzystego p[0][x] to liczba liter w powce palindromu o rodku midzy s[x - 1] i s[x]
//tj. maksymalny palindrom to s[x - p[0][x]] ... s[x + p[0][x] - 1] UWAGA w uywaniu tego wzorku na palindrom dugoci 0
//Przetestowane na zadaniu z serocka
const int N = 1e6 + 44;
int p[2][N];
//dostaje stringa indexowanego od 0
void manacher(int n, char * s) {
	for (int z = 0, l = 0, r = 0; z < 2; z++, l = 0, r = 0)
		for (int i = 0; i < n; i++)
		{
			if (i < r) p[z][i] = min(r - i + !z, p[z][l + r - i + !z]);
			int L = i - p[z][i], R = i + p[z][i] - !z;
			while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;
			if (R > r) l = L, r = R;
		}
}
//Sowo od l do r wcznie
bool is_palindrome(int l, int r) {
	return p[(l + r + 1) % 2][(l + r + 1) / 2] >= (r - l + 1) / 2;
}

int t;

int n;
string s;
char lit[N];
int pref[N];
int suf[N];

void clear()
{
	s.clear();

	for(int i = 0; i <= n; ++i)
	{
		lit[i] = pref[i] = suf[i] = 0;
		p[0][i] = p[1][i] = 0;
	}
}

void solve()
{
	cin >> s;
	n = siz(s);

	for(int i = 0; i < n; ++i)
		lit[i] = s[i];

	manacher(n, lit);

	for(int i = 0; i < n; ++i)
	{
		if(i <= n-1-i)
			maxi(pref[i-p[1][i]], 2*p[1][i]+1);
		
		if(i >= n-1-i)
			maxi(suf[i+p[1][i]], 2*p[1][i]+1);
		
		if(i - 1 <= n-1-i)
			maxi(pref[i-p[0][i]], 2*p[0][i]);

		if(i > n-1-i && i+p[0][i]-1>=0)
			maxi(suf[i+p[0][i]-1], 2*p[0][i]);
	}

	for(int i = 1; i < n; ++i)
	{	
		maxi(pref[i], pref[i-1]-2);
	}

	for(int i = n-2; i >= 0; --i) 
	{
		maxi(suf[i], suf[i+1]-2);
	}

	/*debug(s);

	for(int i = 0; i < n; ++i)
	{
		debug(i, pref[i]);
	}*/

	if(is_palindrome(0, n-1))
	{
		//cout << siz(s) << endl;
		cout << s << endl;
		clear();
		return;
	}

	int len = -1, best = -1, czy_lewo = -1;

	for(int i = 0; i-1 < n-i; ++i)
	{
		if(i && s[i-1]!=s[n-i])
			break;

		int lewo = pref[i];
		
		if(2*i+lewo > len)
		{
			len = 2*i+lewo;
			czy_lewo = 1;
			best = i;
		}

		int prawo = suf[n-i-1];

		if(2*i+prawo > len)
		{
			len = 2*i+prawo;
			czy_lewo = 0;
			best = i;
		}
	}

	//debug(suf[n-2]);

	string pisz;
	int i = best;

	if(czy_lewo)
	{
		//debug(i, pref[i]);
		pisz = s.substr(0, i + pref[i]) + s.substr(n - i, inf);
	}
	else
	{	
		//debug(i, suf[n-i-1]);
		pisz = s.substr(0, i) + s.substr(n - i - suf[n-i-1], inf);
	}

	//cout << siz(pisz) << endl;
	cout << pisz << endl;
	clear();
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> t;

	while(t--)
		solve();
}