#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef pair<int, double> PID;

PID getX(double x){
	return x > 1.0 ? PID(1, log(log(x))) : x < 1.0 ? PID(-1, log(-log(x))) : PID(0, 0.0);
}

PID typeA(double x, double y, double z){
	PID ret = getX(x);
	ret.nd += z * log(y);
	ret.nd *= ret.st;
	return ret;
}

PID typeB(double x, double y, double z){
	PID ret = getX(x);
	ret.nd += log(z) + log(y);
	ret.nd *= ret.st;
	return ret;
}

int main(){
	double x, y, z;
	scanf("%lf%lf%lf", &x, &y, &z);
	PID a[12] = {
		typeA(x, y, z), typeA(x, z, y), typeB(x, y, z), typeB(x, z, y),
		typeA(y, x, z), typeA(y, z, x), typeB(y, x, z), typeB(y, z, x),
		typeA(z, x, y), typeA(z, y, x), typeB(z, x, y), typeB(z, y, x)
	};
	char *b[12] = {
		"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
		"y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
		"z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"
	};
/*	for (int i = 0; i < 12; ++i)
		printf("%d %.12lf\n", a[i].st, a[i].nd);*/
	puts(*(b + (max_element(a , a + 12) - a)));
	return 0;
}