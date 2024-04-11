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

// ========================================================================= //

const int N = 100179;

int n, p[N];
bool was[N];

int main()
{
    ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i];
		--p[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int x = i;
		for (int j = 0; j < 5; ++j)
			x = p[x];
		int mx = x;
		for (int j = 0; j < 5; ++j)
		{
			x = p[x];
			mx = min(x, mx);
		}
		if (!was[mx])
		{
			was[mx] = true;
			++ans;
		}
	}
	cout << ans << "\n";


    return 0;
}