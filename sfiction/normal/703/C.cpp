#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int n, w, v, u;
	scanf("%d%d%d%d", &n, &w, &v, &u);
	bool flag = true;
	double ans = 0;
	for (int x, y, i = 0; i < n; ++i){
		scanf("%d%d", &x, &y);
		flag &= 1ll * v * y - 1ll * u * x <= 0;
		ans = max(ans, x - 1.0 * y / u * v);
	}
	if (flag)
		ans = 1.0 * w / u;
	else
		ans = ans / v + 1.0 * w / u;
	printf("%.12f\n", ans);
	return 0;
}