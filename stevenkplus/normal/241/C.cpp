#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 110;
const int MAXW = 100100;
int points[MAXN];
int T[MAXW];
int F[MAXW];
bool taken[MAXN];
int Hl,Hr,N;
int main() {	
	scanf("%d %d %d", &Hl,&Hr,&N);
	for(int i = 0; i < MAXW; ++i) {
		T[i] = -1;
		F[i] = -1;
	}
	for(int i = 0; i < N; ++i) {
		int v,a,b;
		char c;
		scanf("%d %c %d %d", &v, &c, &a, &b);
		points[i] = v;
		for(int j = a; j <= b; ++j) {
			if (c == 'T') {
				T[j] = i;
			}
			else {	
				F[j] = i;
			}
		}
	}
	int maxsc = 0;
	for(int bounce = -MAXN; bounce < MAXN; ++bounce) {
		if ( bounce == 0) continue;
		for(int i = 0; i < N; ++i) {
			taken[i] = false;
		}
		int k = Hl;
		if (bounce % 2 != 0) {
			k = 100 - Hl;
		}
		int dy = 100 * bounce + k - Hr;
		double xc = 100000;
		int yc = Hr;
		bool dir = dy > 0;
		int  score = 0;
		{
			int nc = dir?100:0;
		//	printf("dy = %d\n",dy);
		//	printf("yc = %d\n",yc);
			double xm = 100000. * fabs(double(nc - yc) / dy);
			xc -= xm;
			yc = nc;
		}
	//	printf("Starting. bounce = %d\n",bounce);
		while(xc > 0) {
			int xl = int(xc + .00000001), xr = xl + 1;
			if (bounce == -1) {
			//	printf("yc = %d\n", yc);
			//	printf("%d %d\n", xl, xr);
			}
			int p;
			if (dir) {
				p = T[xl];
				if (p != T[xr]) break;
			} else {
				p = F[xl];
				if (p != F[xr]) break;
			}
			if (p < 0 || taken[p]) break;
			score += points[p];
			taken[p] = true;
			dir = !dir;
			int nc = dir?100:0;
			double xm = 100000. * fabs(double(nc - yc) / dy);
			yc = nc;
			xc -= xm;
		}
		if (xc <= 0) {
		//	printf("bounce = %d score = %d\n", bounce, score);
			maxsc = max (maxsc, score);
		}
	}
	printf("%d\n", maxsc);
	return 0;
}