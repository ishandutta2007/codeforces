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

int n1, n2;
int s1, s2, sb;

int main()
{
    ios::sync_with_stdio(false);

	cin >> n1 >> n2;
	unordered_set < string > w;
	for (int i = 0; i < n1; ++i)
	{
		string s;
		cin >> s;
		w.insert(s);
		++s1;
	}
	for (int i = 0; i < n2; ++i)
	{
		string s;
		cin >> s;
		if (w.count(s) == 1)
		{
			--s1;
			++sb;
		} else
			++s2;
	}

	for (int i = 0;; i ^= 1)
	{
		if (sb != 0)
			--sb;
		else if (s1 != 0)
			--s1;
		else
		{
			if (i == 0)
				cout << "NO\n";
			else
				cout << "YES\n";
			return 0;
		}
		swap(s1, s2);
	}

    return 0;
}