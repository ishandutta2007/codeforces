#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
typedef long long ll;
int n, a[100009], p[100009]; ll c[100009], sum[100009]; vector<int> g[100009];
void rec1(int pos) {
	for (int i : g[pos]) {
		sum[i] = max(sum[pos] + c[i], 0LL);
		rec1(i);
	}
}
int rec2(int pos) {
	if (a[pos] < sum[pos]) return 0;
	int ret = 1;
	for (int i : g[pos]) ret += rec2(i);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++) {
		scanf("%d%lld", &p[i], &c[i]), p[i]--;
		g[p[i]].push_back(i);
	}
	rec1(0);
	int ret = rec2(0);
	printf("%d\n", n - ret);
	return 0;
}