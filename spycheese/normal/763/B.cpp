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

int main()
{
    ios::sync_with_stdio(false);

	int n;
	scanf("%d", &n);
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
	{
		ll x1, y1, x2, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		x1 += 2000000000LL;
		y1 += 2000000000LL;
		x1 %= 2;
		y1 %= 2;
		cout << 1 + x1 + 2*y1 << "\n";
	}

    return 0;
}