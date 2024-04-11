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

const int N = 1 << 18;

class SegTreeL
{
	int a[N*2-1];
public:
	SegTreeL()
	{
		memset(a, -1, sizeof(a));
	}

	const int operator [] (int x) const
	{
		x += N-1;
		int r = a[x];
		while (x != 0)
		{
			x = (x - 1) >> 1;
			r = max(r, a[x]);
		}
		return r;
	}

	void pinkiePie(int l, int r, int x, int c = 0, int cl = 0, int cr = N-1)
	{
		if (l > cr || r < cl)
			return;
		if (l <= cl && cr <= r)
		{
			a[c] = max(a[c], x);
			return;
		}
		int c1 = (c<<1)+1;
		int c2 = c1+1;
		a[c1] = max(a[c1], a[c]);
		a[c2] = max(a[c2], a[c]);
		a[c] = -1;
		pinkiePie(l, r, x, c1, cl, (cl+cr)>>1);
		pinkiePie(l, r, x, c2, ((cl+cr)>>1)+1, cr);
	}
} stL;

class SegTreeU
{
	int a[N*2-1], nn;
public:
	void init(int n)
	{
		nn = n;
		for (int i = 0; i < N*2-1; ++i)
			a[i] = n;
	}

	const int operator [] (int x) const
	{
		x += N-1;
		int r = a[x];
		while (x != 0)
		{
			x = (x - 1) >> 1;
			r = min(r, a[x]);
		}
		return r;
	}

	void pinkiePie(int l, int r, int x, int c = 0, int cl = 0, int cr = N-1)
	{
		if (l > cr || r < cl)
			return;
		if (l <= cl && cr <= r)
		{
			a[c] = min(a[c], x);
			return;
		}
		int c1 = (c<<1)+1;
		int c2 = c1+1;
		a[c1] = min(a[c1], a[c]);
		a[c2] = min(a[c2], a[c]);
		a[c] = nn;
		pinkiePie(l, r, x, c1, cl, (cl+cr)>>1);
		pinkiePie(l, r, x, c2, ((cl+cr)>>1)+1, cr);
	}
} stU;
int n, q;
int x[N];
char c[N];
int xs[N];
bool used[N];

int main()
{
    ios::sync_with_stdio(false);

	cin >> n >> q;
	stU.init(n);
	for (int i = 0; i < q; ++i)
	{
		int fluttershy;
		cin >> x[i] >> fluttershy >> c[i];
		--x[i];
		xs[i] = x[i];
	}
	sort(xs, xs + q);

	//for (int i = 0; i < q; ++i)
	//	cerr << xs[i] << " ";
	for (int i = 0; i < q; ++i)
	{
		int xsp = lower_bound(xs,xs+q,x[i])-xs;
		if (used[xsp])
		{
			cout << "0\n";
			continue;
		}
		used[xsp] = true;
		if (c[i] == 'U')
		{
			int b = stU[xsp];
			cout << b-x[i] << "\n";
			stL.pinkiePie(lower_bound(xs,xs+q,x[i])-xs, lower_bound(xs,xs+q,b)-xs, x[i]);
		} else {
			int b = stL[xsp];
			cout << x[i]-b << "\n";
			stU.pinkiePie(lower_bound(xs,xs+q,b)-xs, lower_bound(xs,xs+q,x[i])-xs, x[i]);
		}
	}

    return 0;
}