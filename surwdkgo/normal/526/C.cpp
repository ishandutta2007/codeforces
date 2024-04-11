#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
long long c, ha, hb, wa, wb;
long long ans;
void check(long long x) {
	if (x < 0 || x * wa > c) return;
	long long x2 = (c - wa * x) / wb;
	long long nn = x * ha + x2 * hb;
	ans = max(ans, nn);
	return;
}
int main() {
	cin >> c >> ha >> hb >> wa >> wb;
	if (wa < wb) {
		swap(wa, wb);
		swap(ha, hb);
	}
	for (int i=0; i<wb && wa * i <= c; i++) check(i);
	long long mx = c / wa;
	for (int i=mx; i>mx-wb && i>=0; i--) check(i);
	cout << ans << endl;
	return 0;
}