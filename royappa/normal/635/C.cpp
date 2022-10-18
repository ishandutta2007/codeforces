#include <bits/stdc++.h>

using namespace std;

using LL = long long;

#define SQR(x) ((x)*(x))
#define DIST(ax,ay,bx,by) sqrt(SQR((ax)-(bx))+SQR((ay)-(by)))

LL S, X;
LL memo[61][2][2][2];
const int n = 61;

LL f(int p, int carry, int az, int bz) {
	if (p == n) {
		return carry == 1 ? 0 : (az && bz);
	}
	LL& res = memo[p][carry][az][bz];
	if (res != -1) {
		return res;
	}
	res = 0;
	int xb = (X>>p)&1;
	int sb = (S>>p)&1;
	for (int a = 0; a <= 1; a++) {
		for (int b = 0; b <= 1; b++) {
			if (a^b != xb) continue;
			if ((a+b+carry)%2 != sb) continue;
			res += f(p+1, (a+b+carry)/2, az || (a != 0), bz || (b != 0));
		}
	}
	return res;
}
int main()
{
	cin >> S >> X;
	memset(memo, -1, sizeof(memo));

	cout << f(0, 0, 0, 0) << endl;

	exit(0);
}