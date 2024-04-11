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

const int N = 50179;

int n, m;
vector < int > e[N];
int ans[N];
int t;
vector < int > k[N];

int main()
{
	srand(time(nullptr) + 179422);
    ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int v = 0; v < n; ++v)
	{
		int e0 = 0, e1 = 0;
		for (int nv : e[v])
			if (nv < v)
				++(ans[nv] == 0 ? e0 : e1);
		if (e0 > e1)
			ans[v] = 1;
		else
			ans[v] = 0;
	}

	for (int i = 0; i < n; ++i)
	{
		int l;
		cin >> l;
		while (l--)
		{
			int qq;
			cin >> qq;
			--qq;
			t = max(qq + 1, t);
			k[i].push_back(qq);
		}
	}

	while (true)
	{
		static int ta[1000179];
		for (int i = 0; i < t; ++i)
			ta[i] = rand() & 1;
		bool ok = true;
		for (int i = 0; i < n; ++i)
		{
			bool cok = false;
			for (int tt : k[i])
				if (ans[i] == ta[tt])
				{
					cok = true;
					break;
				}
			if (!cok)
			{
				ok = false;
				break;
			}
		}
		if (!ok)
			continue;
		for (int i = 0; i < n; ++i)
			for (int tt : k[i])
				if (ans[i] == ta[tt])
				{
					cout << tt + 1 << " ";
					break;
				}
		cout << "\n";
		for (int i = 0; i < t; ++i)
			cout << ta[i] + 1 << " ";
		cout << "\n";
		return 0;
	}

    return 0;
}