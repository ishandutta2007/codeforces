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

const int N = 100179;

int n, m;
vector < int > e[N];
int col[N];

void dfs(int v, int cc)
{
	if (col[v])
	{
		if (col[v] != cc)
		{
			cout << "-1\n";
			exit(0);
		}
		return;
	}
	col[v] = cc;
	for (int nv : e[v])
		dfs(nv, 3-cc);
}

int main()
{
    ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i< m; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int cc = 1;
	for (int i = 0; i < n; ++i)
		if (col[i] == 0)
			dfs(i, cc = 3 - cc);
	vector < int > a[3];
	for (int i = 0; i < n; ++i)
		a[col[i]].push_back(i);
	cout << sz(a[1]) << "\n";
	for (int x : a[1])
		cout << x + 1 << " ";
	cout << "\n";
	cout << sz(a[2]) << "\n";
	for (int x : a[2])
		cout << x + 1 << " ";
	cout << "\n";

    return 0;
}