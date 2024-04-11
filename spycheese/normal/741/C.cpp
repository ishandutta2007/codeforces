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

const int N = 200179;

int n;
int p1[N], p2[N];
int p[N];
int ans[N];

int main()
{
    ios::sync_with_stdio(false);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &p1[i], &p2[i]);
		--p1[i];
		--p2[i];
		p[p1[i]] = p2[i];
		p[p2[i]] = p1[i];
	}

	for (int i = 0; i < n*2; ++i)
	{
		int j = i;
		while (!ans[j])
		{
			ans[j] = 1;
			j ^= 1;
			ans[j] = 2;
			j = p[j];
		}
	}

	for (int i = 0; i < n; ++i)
		printf("%d %d\n", ans[p1[i]], ans[p2[i]]);

    return 0;
}