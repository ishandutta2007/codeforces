#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <complex>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

typedef complex<double> dComp;
typedef complex<int64> iComp;

iComp a, b, c;

dComp conv(iComp z) {
	return dComp(double(z.real()), double(z.imag()));
}

bool Divides(iComp x, iComp y) {
	cerr << x << " " << y << endl;
	if (y == iComp(0, 0))
		return (x == iComp(0, 0));

	dComp xdy = conv(x) / conv(y);
	cerr << xdy << endl;
	iComp q(int64(xdy.real()), int64(xdy.imag()));
	cerr << q << endl;

	const int S = 5;
	for (int dx = -S; dx <= S; dx++)
		for (int dy = -S; dy <= S; dy++) {
			iComp qp = q + iComp(dx, dy);
			if (qp * y == x)
				return true;
		}

	return false;
}

int main() {
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif	
	int x, y;

	scanf("%d%d", &x, &y);
	a = iComp(x, y);
	scanf("%d%d", &x, &y);
	b = iComp(x, y);
	scanf("%d%d", &x, &y);
	c = iComp(x, y);
	
	bool ans = false;

	iComp rot(0, 1);
	for (int i = 0; i<4; i++) {
		ans |= Divides(b - a, c);
		a *= rot;
	}

	printf("%s\n", (ans ? "YES" : "NO"));

	return 0;
}