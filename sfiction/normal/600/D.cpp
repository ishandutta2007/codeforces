#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll sqr(ll x){
	return x * x;
}

int main(){
	int ax, ay, r1, bx, by, r2;
	scanf("%d%d%d", &ax, &ay, &r1);
	scanf("%d%d%d", &bx, &by, &r2);
	ll d_2 = sqr(ax - bx) + sqr(ay - by);
	ll r1_2 = sqr(r1), r2_2 = sqr(r2);
	if (d_2 >= sqr(r1 + r2))
		puts("0");
	else if (d_2 <= sqr(r1 - r2))
		printf("%.12f\n", M_PI * sqr(min(r1, r2)));
	else{
		long double d = sqrt((long double)d_2);
		long double At = (long double)(d_2 + r1_2 - r2_2) / 2.0 / r1 / d, A = acos(At);
		long double Bt = (long double)(d_2 + r2_2 - r1_2) / 2.0 / r2 / d, B = acos(Bt);
		printf("%.12f\n", (double)((long double)r1_2 * (A - sin(A) * At) + (long double)r2_2 * (B - sin(B) * Bt)));
	}

	return 0;
}