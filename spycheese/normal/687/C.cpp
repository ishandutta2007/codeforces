#include <bits/stdc++.h>

#define sz(x) ((int)((x).size()))
#define X first
#define Y second
#ifndef LOCAL
    #define cerr 1/0
#endif

using namespace std;

template < class T > T gcd(T x, T y) { return y == 0 ? x : gcd(y, x % y); }

typedef long long ll;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
typedef long double ld;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double DINF = numeric_limits<double>::infinity();
const double EPS = 1e-8;
const int MOD = 1000000007;
const int DX[] = {1, 0, -1,  0, 1, -1, -1,  1};
const int DY[] = {0, 1,  0, -1, 1, -1,  1, -1};

const int N = 505;

int n, k;
bool d[N][N];

int main()
{
    ios::sync_with_stdio(false);

	d[0][0] = true;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		for (int v1 = k; v1 >= 0; --v1)
			for (int v2 = k; v2 >= 0; --v2)
				d[v1][v2] |= (v1 >= c ? d[v1 - c][v2] : false) || (v2 >= c ? d[v1][v2 - c] : false);
	}
	vector < int > ans;
	for (int i = 0; i <= k; ++i)
		if (d[i][k-i])
			ans.push_back(i);
	cout << sz(ans) << "\n";
	for (int x : ans)
		cout << x << " ";
	cout << "\n";

    return 0;
}