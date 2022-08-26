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

const int N = 100179;

unordered_map < string , int > ss;

int main()
{
    ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		string t, s;
		cin >> t >> s;
		while (sz(s) < 18)
			s = '0' + s;
		for (int i = 0; i < 18; ++i)
			if ((s[i] - '0') % 2 == 0)
				s[i] = '0';
			else
				s[i] = '1';
		if (t == "+")
			++ss[s];
		else if (t == "-")
			--ss[s];
		else
			cout << ss[s] << "\n";
	}


    return 0;
}