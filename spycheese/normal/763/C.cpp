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
mt19937 tw(179239);
int rnd(int x, int y)
{
	static uniform_int_distribution<int> d;
	return d(tw) % (y - x + 1) + x;
}

// ========================================================================= //

const int N = 200179;



int mod, n;
int a[N];

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d%d", &mod, &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	if (n == 1)
	{
		cout << a[0] << " " << 0 << "\n";
		return 0;
	}
	if (n == 2)
	{
		cout << a[0] << " " << (mod+a[1]-a[0]) % mod << "\n";
		return 0;
	}
	if (n == mod)
	{
		cout << "0 1\n";
		return 0;
	}
	
	bool swd = false;
	if (n+n > mod)
	{
		swd = true;
		static bool h[N];
		for (int i = 0; i < n; ++i)
			h[a[i]] = true;
		n = 0;
		for (int i = 0; i < mod; ++i)
			if (!h[i])
				a[n++] = i;
		if (n == 1)
		{
			int ansX = a[0];
			int ansD = 1;
			ansX = (ansX - ansD + mod) % mod;
			ansD = (mod - ansD) % mod;
			cout << ansX << " " << ansD << "\n";
			return 0;
		}
		if (n == 2)
		{
			int ansX = a[0];
			int ansD = (a[1] + mod - a[0]) % mod;
			ansX = (ansX - ansD + mod) % mod;
			ansD = (mod - ansD) % mod;
			cout << ansX << " " << ansD << "\n";
			return 0;
		}
	} else
		sort(a, a + n);
	a[n] = IINF;

	map < int , int > ds;
	for (int i = 0; i < 200; ++i)
	{
		int ind = rnd(0, n - 1);
		int x = a[ind];
		int k1 = 0, k2 = 0;
		while (k1 < n && k2 < n)
		{
			int d1 = (a[ind+k1 >= n ? ind+k1-n : ind+k1] - x);
			if (d1 < 0)
				d1 += mod;
			int d2 = (x - a[ind-k2 < 0 ? ind-k2+n : ind-k2]);
			if (d2 < 0)
				d2 += mod;
			if (d1 < d2)
				++k1;
			else if (d1 > d2)
				++k2;
			else
			{
				++ds[d1];
				++k1;
				++k2;
			}
		}
	}

	vector < ipair > dsc;
	for (auto pp : ds)
		if (pp.X != 0)
			dsc.emplace_back(pp.Y, pp.X);
	sort(dsc.begin(), dsc.end(), greater<ipair>());

	int ansX = -1, ansD = -1;
	for (auto dd : dsc)
	{
		if (dd.X != dsc[0].X)
		{
			cout << "-1\n";
			return 0;
		}
		int d = dd.Y;
		int cnt = 1;
		int x = a[0];
		while (true)
		{
			x += d;
			if (x >= mod)
				x -= mod;
			if (*lower_bound(a, a + n, x) != x)
				break;
			++cnt;
		}
		x = a[0];
		while (true)
		{
			x -= d;
			if (x < 0)
				x += mod;
			if (*lower_bound(a, a + n, x) != x)
				break;
			++cnt;
		}
		x += d;
		if (x >= mod)
			x -= mod;
		if (cnt == n)
		{
			ansD = d;
			ansX = x;
			break;
		}
	}
	if (ansX == -1)
	{
		cout << "-1\n";
		return 0;
	}

	if (swd)
	{
		ansX = (ansX - ansD + mod) % mod;
		ansD = (mod - ansD) % mod;
	}
	cout << ansX << " " << ansD << "\n";
	
    return 0;
}