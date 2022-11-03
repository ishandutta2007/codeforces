#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1E5 + 10;

int n;
double ax, ay, bx, by, tx, ty;
double x[MAXN], y[MAXN];
double dis[MAXN], da[MAXN], db[MAXN];

inline double sqr(double x){
	return x * x;
}

void update(int a[], int x, double da[]){
	if (da[a[0]] > da[x])
		a[1] = a[0], a[0] = x;
	else if (da[a[1]] > da[x])
		a[1] = x;
}

int main(){
	scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &tx, &ty);
	scanf("%d", &n);
	double tot = 0.0;
	int a[2] = {0, 0}, b[2] = {0, 0};
	da[0] = db[0] = 1E100;
	for (int i = 1; i <= n; ++i){
		scanf("%lf%lf", &x[i], &y[i]);
		tot += dis[i] = sqrt(sqr(x[i] - tx) + sqr(y[i] - ty));
		da[i] = sqrt(sqr(x[i] - ax) + sqr(y[i] - ay)) - dis[i];
		db[i] = sqrt(sqr(x[i] - bx) + sqr(y[i] - by)) - dis[i];
		update(a, i, da);
		update(b, i, db);
	}
	double ans = tot * 2 + min(da[a[0]], db[b[0]]);
	if (a[0] != b[0])
		ans = min(ans, tot * 2 + da[a[0]] + db[b[0]]);
	else{
		ans = min(ans, tot * 2 + da[a[0]] + db[b[1]]);
		ans = min(ans, tot * 2 + da[a[1]] + db[b[0]]);
	}
	printf("%.8f\n", ans);
	return 0;
}