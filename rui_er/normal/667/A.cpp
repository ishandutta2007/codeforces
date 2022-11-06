//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const double pi = acos(-1);

double d, h, v, e;

int main() {
	scanf("%lf%lf%lf%lf", &d, &h, &v, &e);
	double r = d / 2;
	double _ = pi * r * r;
	double __ = _ * h;
	double ___ = _ * e;
	double ____ = __ / (v - ___);
	if(___ >= v) puts("NO");
	else printf("YES\n%.6lf\n", ____);
	return 0;
}