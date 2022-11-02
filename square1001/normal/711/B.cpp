#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
typedef long long ll;
using namespace std;
int n; ll a[509][509];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%lld", &a[i][j]);
	}
	if (n == 1) puts("1");
	else {
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll s = 0; bool flag = true;
			for (int j = 0; j < n; j++) {
				s += a[i][j];
				if (a[i][j] == 0) flag = false;
			}
			if (flag) {
				sum = s;
				break;
			}
		}
		ll ret = 0;
		for (int i = 0; i < n; i++) {
			ll s = 0, p = -1;
			for (int j = 0; j < n; j++) {
				s += a[i][j];
				if (a[i][j] == 0) p = j;
			}
			if (p != -1) {
				ret = sum - s;
				a[i][p] = ret;
				break;
			}
		}
		bool res = true;
		ll s1 = 0, s2 = 0;
		for (int i = 0; i < n; i++) {
			ll s = 0, t = 0;
			for (int j = 0; j < n; j++) {
				s += a[i][j];
				t += a[j][i];
			}
			if (s != sum || t != sum) res = false;
			s1 += a[i][i], s2 += a[i][n - i - 1];
		}
		if (s1 != sum || s2 != sum) res = false;
		if (!res || ret <= 0) puts("-1");
		else printf("%lld\n", ret);
	}
	return 0;
}