#include <bits/stdc++.h>

#ifndef LOCAL
#define cerr ksgkfjasdhf
#define stderr dfjgdfjkghd
#endif

#define sz(x) ((int)x.size())
#define mp(x,y) make_pair(x, y)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int , int > ipair;
typedef pair < ll , ll > lpair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const double EPS = 1e-8;
const int DX[] = {1, 0, -1,  0, 1, -1,  1, -1};
const int DY[] = {0, 1,  0, -1, 1, -1, -1,  1};

const int N = 100179;

int nxt[N];

int main()
{
    ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	
	memset(nxt, -1, sizeof(nxt));
	for (int i = 0; i < k; ++i)
	{
		int m;
		cin >> m;
		int px;
		for (int j = 0; j < m; ++j)
		{
			int x;
			cin >> x;
			--x;
			if (j != 0)
				nxt[px] = x;
			px = x;
		}
	}
	int ll = 0;
	int cc = 0;
	while (true)
	{
		++ll;
		if (nxt[cc] != cc + 1)
			break;
		cc = nxt[cc];
	}

	cout << (n-ll) + (n-cc-k) << "\n";
    return 0;
}