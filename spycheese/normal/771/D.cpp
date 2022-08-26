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

const int N = 80;

int n;
string s;
vector < int > pv, pk, pz;
int d[N][N][N], dnv[N][N][N];

int main()
{
    ios::sync_with_stdio(false);

	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'V')
			pv.push_back(i);
		else if (s[i] == 'K')
			pk.push_back(i);
		else
			pz.push_back(i);
	
	for (int len = 1; len <= n; ++len)
		for (int cv = 0; cv <= min(len, sz(pv)); ++cv)
			for (int ck = 0; ck <= min(len - cv, sz(pk)); ++ck)
			{
				int cz = len - cv - ck;
				if (cz > sz(pz))
					continue;
				
				int dv = IINF, dk = IINF, dz = IINF;
				if (cv > 0)
				{
					int pos = pv[cv - 1];
					dv = d[cv-1][ck][cz];
					dv += abs(ck - (lower_bound(pk.begin(), pk.end(), pos) - pk.begin()));
					dv += abs(cz - (lower_bound(pz.begin(), pz.end(), pos) - pz.begin()));
				}
				if (ck > 0)
				{
					int pos = pk[ck - 1];
					dk = dnv[cv][ck-1][cz];
					dk += abs(cv - (lower_bound(pv.begin(), pv.end(), pos) - pv.begin()));
					dk += abs(cz - (lower_bound(pz.begin(), pz.end(), pos) - pz.begin()));
				}
				if (cz > 0)
				{
					int pos = pz[cz - 1];
					dz = d[cv][ck][cz-1];
					dz += abs(ck - (lower_bound(pk.begin(), pk.end(), pos) - pk.begin()));
					dz += abs(cv - (lower_bound(pv.begin(), pv.end(), pos) - pv.begin()));
				}

				d[cv][ck][cz] = min({dv, dk, dz});
				dnv[cv][ck][cz] = min(dk, dz);
			}
	
	cout << d[sz(pv)][sz(pk)][sz(pz)] / 2 << "\n";

    return 0;
}