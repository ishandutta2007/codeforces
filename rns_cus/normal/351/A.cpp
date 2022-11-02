#include <bits/stdc++.h>
using namespace std;

#define ep 1e-9

double xx;
long long sum, sum1, sum2, x, y;
int gas, n, tot;

int main() {
	//freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i ++) {
		scanf("%lf", &xx);
		x = (xx + (1e-8)) * 1000ll;
		//cout << x << endl;
		y = x / 1000 * 1000;
		sum += x;
		sum1 += y;
		if(x == y) gas ++;
	}
	int en = n - max(0, gas - n);
	int st = n - min(gas, n);
	long long ans = 1ll << 62;
	for (int i = st; i <= en; i ++) {
		ans = min(ans, abs(sum - sum1 - i * 1000));
	}
	printf("%.3lf\n", ans * 0.001);
}