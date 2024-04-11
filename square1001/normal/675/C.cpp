#include <map>
#include <iostream>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n; long long a[200009];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	map<long long, int> d;
	for (int i = 0; i < n; i++) d[a[i]]++;
	int ret = 999999999;
	for (pair<long long, int> i : d) ret = min(ret, n - i.second);
	printf("%d\n", ret);
	return 0;
}