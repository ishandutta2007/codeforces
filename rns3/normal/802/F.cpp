#include <bits/stdc++.h>
using namespace std;

int a[255], mx, T;
double tag;

int main() {
	scanf("%d", &T);
	while (T --)  {
		tag = 0, mx = 0;
		for (int i = 1; i <= 250; i ++) {
			scanf("%d", &a[i]);
			tag += a[i] * a[i];
			mx = max(mx, abs(a[i]));
		}
		tag /= (250.0 * mx * mx);
		if (tag < 0.25) puts("poisson");
		else puts("uniform");
	}
	return 0;
}