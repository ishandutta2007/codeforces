/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 140A
 */
#include <cstdio>
#include <cmath>

const double EPS = 1E-6;

int maximize(int R, int r){
	if (r > R)
		return 0;
	if (r * 2 >= R)
		return r * 2 == R ? 2 : 1;
	double theta = asin(r / double(R - r));
	return acos(-1) / theta + EPS;
}

int main(){
	int n, R, r;

	scanf("%d%d%d", &n, &R, &r);
	int m = maximize(R, r);
	puts(n <= m ? "YES" : "NO");
	return 0;
}