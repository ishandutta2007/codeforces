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

const int N = 55;

string genName()
{
	static int x = 1500;
	++x;
	string q;
	int y = x;
	for (int i = 0; i < 5; ++i, y /= 10)
		q += 'a' + y % 10;
	q[0] = q[0] - 'a' + 'A';
	return q;
}

int n, k;
bool isOk[N];
string ans[N];

int main()
{
    ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n - k + 1; ++i)
	{
		string q;
		cin >> q;
		isOk[i] = (q == "YES");
	}
	for (int i = 0; i < k - 1; ++i)
		ans[i] = genName();
	for (int i = k - 1; i < n; ++i)
	{
		if (isOk[i - k + 1])
			ans[i] = genName();
		else
			ans[i] = ans[i - k + 1];
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << "\n";

    return 0;
}