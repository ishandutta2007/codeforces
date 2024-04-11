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

// ========================================================================= //

const int N = 3333;

int n, a[N], b[N];
ll d[N][N];

int main()
{
    ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i] -= i;
	}
	memcpy(b, a, sizeof(a));
	sort(b, b + n);

	for (int j = 0; j < n; ++j)
		d[0][j] = abs(a[0] - b[j]);
	for (int i = 1; i < n; ++i)
	{
		ll mm = LINF;
		for (int j = 0; j < n; ++j)
		{
			mm = min(mm, d[i-1][j]);
			d[i][j] = abs(a[i] - b[j]) + mm;
		}
	}

	ll ans = LINF;
	for (int i = 0; i < n; ++i)
		ans = min(ans, d[n-1][i]);
	cout << ans << "\n";

    return 0;
}