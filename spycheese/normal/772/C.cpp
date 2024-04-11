#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr dolor_sit_amet
#endif

#define mp make_pair
#define sz(x) ((int)((x).size()))
#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll sqr(ll x) { return x*x; } ll sqr(int x) { return (ll)x*x; }
double sqr(double x) { return x*x; } ld sqr(ld x) { return x*x; }

// ========================================================================= //

const int N = 200179;

int n, m;
bool forb[N];
vector < int > cnums[N];
int d[N], dnext[N];
vector < int > wws;

ll gcd1(ll a, ll b, ll & x, ll & y)
{
	if (!a)
	{
		x = 0;
		y = 1;
		return b;
	}
	ll x1, y1;
	ll k = gcd1(b % a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return k;
}

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		forb[x] = 1;
	}

	for (int i = 0; i < m; ++i)
		if (!forb[i])
			cnums[gcd(i, m)].push_back(i);
	for (int i = 1; i <= m; ++i)
		if (!cnums[i].empty())
			wws.push_back(i);
	
	for (int i = sz(wws) - 1; i >= 0; --i)
	{
		dnext[i] = -1;
		for (int j = i + 1; j < sz(wws); ++j)
			if (wws[j] % wws[i] == 0 && d[j] > d[i])
			{
				d[i] = d[j];
				dnext[i] = j;
			}
		d[i] += sz(cnums[wws[i]]);
	}

	int start = 0;
	for (int i = 0; i < sz(wws); ++i)
		if (d[i] > d[start])
			start = i;
	cout << d[start] << "\n";

	int p = 1;
	while (start != -1)
	{
		for (int x : cnums[wws[start]])
		{
			ll aa, bb;
			ll g = gcd1(p, m, aa, bb);
			cout << ((aa * (x / g)) % m + m) % m << " ";
			p = x;
		}
		start = dnext[start];
	}
	cout << "\n";
	
    return 0;
}