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
const int IINF = 1010179179;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = numeric_limits<double>::infinity();
const ll MOD = 1000000007;
const double EPS = 1e-9;
const int DX[] = { 1,  0, -1,  0,  1, -1,  1, -1};
const int DY[] = { 0,  1,  0, -1,  1, -1, -1,  1};

// ========================================================================= //

const int N = 1 << 18;

class SegTree
{
	int tmin0[N*2-1], tmin1[N*2-1];
	int tadd0[N*2-1], tadd1[N*2-1];
public:
	int getMin(int l, int r, int c = 0, int cl = 0, int cr = N - 1)
	{
		if (l > cr || r < cl)
			return IINF;
		if (l <= cl && cr <= r)
		{
			if (cl == cr)
			{
				if (cl & 1)
					return tmin1[c];
				else
					return tmin0[c];
			}
			return min(tmin0[c], tmin1[c]);
		}
		int c1 = c*2+1, c2=c*2+2;
		tmin0[c1] += tadd0[c];
		tmin1[c1] += tadd1[c];
		tadd0[c1] += tadd0[c];
		tadd1[c1] += tadd1[c];
		tmin0[c2] += tadd0[c];
		tmin1[c2] += tadd1[c];
		tadd0[c2] += tadd0[c];
		tadd1[c2] += tadd1[c];
		tadd0[c] = tadd1[c] = 0;
		return min(getMin(l, r, c1, cl, (cl+cr)/2),
				   getMin(l, r, c2, (cl+cr)/2+1, cr));
	}
	int getMin0(int l, int r, int c = 0, int cl = 0, int cr = N - 1)
	{
		if (l > cr || r < cl)
			return IINF;
		if (l <= cl && cr <= r)
		{
			if (cl == cr && (cl & 1))
				return IINF;
			return tmin0[c];
		}
		int c1 = c*2+1, c2=c*2+2;
		tmin0[c1] += tadd0[c];
		tmin1[c1] += tadd1[c];
		tadd0[c1] += tadd0[c];
		tadd1[c1] += tadd1[c];
		tmin0[c2] += tadd0[c];
		tmin1[c2] += tadd1[c];
		tadd0[c2] += tadd0[c];
		tadd1[c2] += tadd1[c];
		tadd0[c] = tadd1[c] = 0;
		return min(getMin0(l, r, c1, cl, (cl+cr)/2),
				   getMin0(l, r, c2, (cl+cr)/2+1, cr));
	}
	int getMin1(int l, int r, int c = 0, int cl = 0, int cr = N - 1)
	{
		if (l > cr || r < cl)
			return IINF;
		if (l <= cl && cr <= r)
		{
			if (cl == cr && !(cl & 1))
				return IINF;
			return tmin1[c];
		}
		int c1 = c*2+1, c2=c*2+2;
		tmin0[c1] += tadd0[c];
		tmin1[c1] += tadd1[c];
		tadd0[c1] += tadd0[c];
		tadd1[c1] += tadd1[c];
		tmin0[c2] += tadd0[c];
		tmin1[c2] += tadd1[c];
		tadd0[c2] += tadd0[c];
		tadd1[c2] += tadd1[c];
		tadd0[c] = tadd1[c] = 0;
		return min(getMin1(l, r, c1, cl, (cl+cr)/2),
				   getMin1(l, r, c2, (cl+cr)/2+1, cr));
	}

	void add0(int l, int r, int val, int c = 0, int cl = 0, int cr = N - 1)
	{
		if (l > cr || r < cl)
			return;
		if (l <= cl && cr <= r)
		{
			tadd0[c] += val;
			tmin0[c] += val;
			return;
		}
		int c1 = c*2+1, c2=c*2+2;
		tmin0[c1] += tadd0[c];
		tmin1[c1] += tadd1[c];
		tadd0[c1] += tadd0[c];
		tadd1[c1] += tadd1[c];
		tmin0[c2] += tadd0[c];
		tmin1[c2] += tadd1[c];
		tadd0[c2] += tadd0[c];
		tadd1[c2] += tadd1[c];
		tadd0[c] = tadd1[c] = 0;
		add0(l, r, val, c1, cl, (cl+cr)/2);
		add0(l, r, val, c2, (cl+cr)/2+1, cr);
		if (cl + 1 == cr)
			tmin0[c] = tmin0[c1];
		else
			tmin0[c] = min(tmin0[c1], tmin0[c2]);
	}

	void add1(int l, int r, int val, int c = 0, int cl = 0, int cr = N - 1)
	{
		if (l > cr || r < cl)
			return;
		if (l <= cl && cr <= r)
		{
			tadd1[c] += val;
			tmin1[c] += val;
			return;
		}
		int c1 = c*2+1, c2=c*2+2;
		tmin0[c1] += tadd0[c];
		tmin1[c1] += tadd1[c];
		tadd0[c1] += tadd0[c];
		tadd1[c1] += tadd1[c];
		tmin0[c2] += tadd0[c];
		tmin1[c2] += tadd1[c];
		tadd0[c2] += tadd0[c];
		tadd1[c2] += tadd1[c];
		tadd0[c] = tadd1[c] = 0;
		add1(l, r, val, c1, cl, (cl+cr)/2);
		add1(l, r, val, c2, (cl+cr)/2+1, cr);
		if (cl + 1 == cr)
			tmin1[c] = tmin1[c2];
		else
			tmin1[c] = min(tmin1[c1], tmin1[c2]);
	}
} st;

int n;

void segAdd(int l, int r, int k)
{
	++r;
	if ((r - l) & 1)
	{
		st.add0(r, n, (r & 1 ? -k : k));
		st.add1(r, n, (r & 1 ? k : -k));
	}
	if (l & 1)
		st.add0(l + 1, r - 1, k);
	else
		st.add1(l + 1, r - 1, k);
}

int main()
{
    ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int aa;
		cin >> aa;
		--aa;
		segAdd(i, i, aa);
	}
	
	int q;
	cin >> q;
	while (q--)
	{
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
		{
			int k;
			cin >> k;
			segAdd(l, r, k);
		} else {
			int ls = st.getMin(l, l);
			if (st.getMin(r + 1, r + 1) - ls * ((r - l) & 1 ? 1 : -1) == 0 &&
				st.getMin0(l, r + 1) - ls * (l & 1 ? -1 : 1) >= 0 &&
				st.getMin1(l, r + 1) - ls * (l & 1 ? 1 : -1) >= 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}

    return 0;
}