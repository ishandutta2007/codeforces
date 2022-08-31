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

const int N = 1111;

int main()
{
    ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	if (k == 1)
		cout << "-1\n";
	else if (k == 2)
	{
		if (n <= 4)
			cout << "-1\n";
		else
		{
			cout << n - 1 << "\n";
			for (int i = 0; i < n - 1; ++i)
				cout << i + 1 << " " << i + 2 << "\n";
		}
	} else if (k == 3)
	{
		if (n < 4)
			cout << "-1\n";
		else
		{
			cout << 3 + (n-4)*2 << "\n";
			cout << "1 2\n";
			cout << "2 3\n";
			cout << "3 4\n";
			for (int i = 5; i <= n; ++i)
			{
				cout << i << " 1\n";
				cout << i << " 2\n";
			}
		}
	} else
		cout << "-1\n";

    return 0;
}