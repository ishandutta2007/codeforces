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

const int N = 1000179;

int t[N];

void inc(int x)
{
	for (; x < N; x |= (x+1))
		++t[x];
}
int sum(int x)
{
	int s = 0;
	for (--x; x >= 0; x = (x&(x+1))-1)
		s += t[x];
	return s;
}

int n, k;

int main()
{
    ios::sync_with_stdio(false);
	
	cin >> n >> k;
	if (k*2 > n)
		k = n - k;
	int x = 0;
	ll ans = 1;
	for (int i = 0; i < n; ++i)
	{
		inc(x);
		int x2 = x + k;
		ans += 1;
		if (x2 < n)
			ans += (sum(x2) - sum(x+1)) * 2;
		else
		{
			ans += (sum(n) - sum(x+1)) * 2;
			ans += (sum(x2 - n)) * 2;
			if (x2 != n)
				--ans;
		}
		x = (x2 >= n ? x2 - n : x2);
		cout << ans << " ";
	}
	cout << "\n";

    return 0;
}