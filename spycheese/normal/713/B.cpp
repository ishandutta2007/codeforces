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

int n;

int ask(int x1, int y1, int x2, int y2)
{
	++x1; ++y1; ++x2; ++y2;
	if (x1 > x2 || y1 > y2)
		return 0;
	cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	cout.flush();
	int a;
	cin >> a;
	return a;
}

int askSide(int side, int cnt)
{
	switch (side)
	{
	case 0: return ask(0, 0, cnt - 1, n-1);
	case 1: return ask(0, 0, n-1, cnt - 1);
	case 2: return ask(n-cnt, 0, n-1, n-1);
	case 3: return ask(0, n-cnt, n-1, n-1);
	}
	return -1;
}

bool check(int x1, int y1, int x2, int y2)
{
	return ask(x1, y1, x2, y2) == 1 &&
		ask(x1+1, y1, x2, y2) == 0 &&
		ask(x1, y1+1, x2, y2) == 0 &&
		ask(x1, y1, x2-1, y2) == 0 &&
		ask(x1, y1, x2, y2-1) == 0;
}

int main()
{
    ios::sync_with_stdio(false);

	cin >> n;
	vector < int > x1, x2, y1, y2;

	int bl, br;

	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(0, mid+1) == 0)
			bl = mid + 1;
		else
			br = mid;
	}
	x2.push_back(bl);
	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(0, mid+1) <= 1)
			bl = mid + 1;
		else
			br = mid;
	}
	x2.push_back(bl);

	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(1, mid+1) == 0)
			bl = mid + 1;
		else
			br = mid;
	}
	y2.push_back(bl);
	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(1, mid+1) <= 1)
			bl = mid + 1;
		else
			br = mid;
	}
	y2.push_back(bl);

	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(2, mid+1) == 0)
			bl = mid + 1;
		else
			br = mid;
	}
	x1.push_back(n-1-bl);
	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(2, mid+1) <= 1)
			bl = mid + 1;
		else
			br = mid;
	}
	x1.push_back(n-1-bl);

	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(3, mid+1) == 0)
			bl = mid + 1;
		else
			br = mid;
	}
	y1.push_back(n-1-bl);
	bl = 0; br = n - 1;
	while (bl < br)
	{
		int mid = (bl + br) / 2;
		if (askSide(3, mid+1) <= 1)
			bl = mid + 1;
		else
			br = mid;
	}
	y1.push_back(n-1-bl);

	for (int cx2 = 0; cx2 < 2; ++cx2)
		for (int cy1 = 0; cy1 < 2; ++cy1)
			for (int cy2 = 0; cy2 < 2; ++cy2)
				if (check(x1[0], y1[cy1], x2[cx2], y2[cy2]))
				{
					cout << "! " << x1[0]+1 << " " << y1[cy1]+1 << " " << x2[cx2]+1 << " " << y2[cy2]+1 << " " << 
						x1[1]+1 << " " << y1[1-cy1]+1 << " " << x2[1-cx2]+1 << " " << y2[1-cy2]+1 << "\n";
					cout.flush();
					return 0;
				}

    return 0;
}