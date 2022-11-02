#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 1010;
struct Point{
	Point(){}
	Point(double _x, double _y){ x = _x; y = _y; }
	double x, y;
}p[maxn];
Point operator - (const Point &a, const Point &b){
	return Point(a.x - b.x, a.y - b.y);
}
double operator * (const Point &a, const Point &b){
	return a.x * b.x + a.y * b.y;
}
double operator ^ (const Point &a, const Point &b){
	return a.x * b.y - a.y * b.x;
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%lf%lf", &p[i].x, &p[i].y);
	double ans = 2e10;
	for(int i = 0; i < n; i++){
		int x = i, y = (i + 1) % n, z = (i + 2) % n;
		ans = min(ans, ((p[z]-p[x])^(p[y]-p[x]))/sqrt((p[z]-p[x])*(p[z]-p[x]))/2);
	}
	printf("%.12lf\n", ans);
	return 0;
}