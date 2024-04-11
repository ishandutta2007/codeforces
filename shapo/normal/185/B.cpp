#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;

int s, a, b, c;
double x, y, z;
double ds, da, db, dc;
double dl, dr, dm1, dm2, dk1, dk2;

double find_sum(const double &xx){
	double rest = ds - xx, sum_res = 0;
	x = da * rest / (da + db);
	y = db * rest / (da + db);
	sum_res = da * log(x) + db * log(y) + dc * log(xx);
	return sum_res;
}

int main(){

	scanf("%d%d%d%d", &s, &a, &b, &c);
	ds = s; da = a; db = b; dc = c;
	x = y = z = 0.0;
	if(a != 0 && b != 0 && c != 0){
		dl = 0; dr = ds;
		for(int i = 1; i <= 300; ++i){
			dm1 = (2 * dl + dr) / 3;
			dm2 = (dl + 2 * dr) / 3;
			dk1 = find_sum(dm1);
			dk2 = find_sum(dm2);
			if(dk1 > dk2)dr = dm2;else dl = dm1;
		}
		z = (dl + dr) / 2;
		dk1 = find_sum(z);
	}
	else{
		if(a == 0 && b == 0 && c == 0)x = ds;
		if(a == 0 && b == 0 && c != 0)z = ds;
		if(a == 0 && b != 0 && c == 0)y = ds;
		if(a != 0 && b == 0 && c == 0)x = ds;
		if(a != 0 && b != 0 && c == 0){
			x = da * ds / (da + db);
			y = db * ds / (da + db);
		}
		if(a != 0 && b == 0 && c != 0){
			x = da * ds / (da + dc);
			z = dc * ds / (da + dc);
		}
		if(a == 0 && b != 0 && c != 0){
			y = db * ds / (db + dc);
			z = dc * ds / (db + dc);
		}
	}

	printf("%.15lf %.15lf %.15lf\n", x, y, z);

	return 0;
}