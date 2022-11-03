/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 549H
 */
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double INFF = 1E10;
const double dire[4][2] = {{1, 1}, {-1, 1}, {-1, -1}, {1, -1}};

struct VEC{
	double x, y;

	VEC(double xx = 0, double yy = 0):x(xx),y(yy){
	}

	void read(){
		scanf("%lf%lf", &x, &y);
	}
};

VEC a[2];

bool intersect(VEC a, VEC b, VEC c){
	return (a.x * b.y - a.y * b.x) * (a.x * c.y - a.y * c.x) <= 0;
}

bool check(double d){
	VEC b[2][5];
	for (int i=0;i<2;++i){
		for (int j=0;j<4;++j)
			b[i][j] = VEC(a[i].x + dire[j][0] * d, a[i].y + dire[j][1] * d);
		b[i][4] = a[i];
	}


	for (int i=0;i<2;++i){
		for (int j=0;j<5;++j){
			for (int k=0;k<4;++k)
				if (intersect(b[i][j], b[i ^ 1][k], b[i ^ 1][(k + 1) & 3]))
					return true;
			if (intersect(b[i][j], b[i ^ 1][0], b[i ^ 1][2]))
				return true;
			if (intersect(b[i][j], b[i ^ 1][1], b[i ^ 1][3]))
				return true;
		}
	}

	return false;
}

int main(){
	a[0].read();
	a[1].read();

	double high = min(max(abs(a[0].x), abs(a[0].y)), max(abs(a[1].x), abs(a[1].y))), low = 0, mid;
	for (int i=0;i<1000;++i){
		mid = (high + low) / 2;
		if (check(mid))
			high = mid;
		else
			low = mid;
	}
	printf("%.10lf", high);

	return 0;
}