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

const int N = 200179;

int n;
int c[N];
vector < int > e[N];

void go(int v, int p = -1)
{
	c[v] = -c[v];
	cout << v + 1 << " ";
	for (int nv : e[v])
	{
		if (nv == p)
			continue;
		go(nv, v);
		cout << v + 1 << " ";
		c[v] = -c[v];
		if (c[nv] == -1)
		{
			cout << nv + 1 << " " << v + 1 << " ";
			c[v] = -c[v];
			c[nv] = -c[nv];
		}
	}
}

int main()
{
    ios::sync_with_stdio(false);
	cin >> n;
	bool z = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i];
		if (c[i] == -1)
			z = false;
	}
	if (z)
	{
		cout << "1\n";
		return 0;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	c[0] = -c[0];
	go(0);
	if (c[0] == -1)
	{
		int nv = e[0][0];
		cout << nv + 1 << " " << 1 << " " << nv + 1;
	}
	cout << "\n";

    return 0;
}