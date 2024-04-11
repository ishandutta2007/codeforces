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

const int N = 100179;

int n;
vector < int > e[N];
int cntb, c[N];

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		--v1;
		--v2;
		e[v1].push_back(v2);
		e[v2].push_back(v1);
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", c+i);
	
	for (int i = 0; i < n; ++i)
		for (int nv : e[i])
		{
			if (nv < i && c[i] != c[nv])
				cntb += 1;
		}
	
	for (int i = 0; i < n; ++i)
	{
		int xx = 0;
		for (int nv : e[i])
			if (c[i] != c[nv])
				++xx;
		if (xx == cntb)
		{
			cout << "YES\n" << i + 1 << "\n";
			return 0;
		}
	}
	cout << "NO\n";

    return 0;
}