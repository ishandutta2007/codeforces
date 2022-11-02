#include <set>
#include <cstdio>
#include <algorithm>
#pragma warning(disable : 4996)
using namespace std;
int n, a[100009]; long long sum = 0;
bool solve() {
	set<long long> s; long long x = sum;
	for (int i = n - 1; i >= 0; i--) {
		s.insert(a[i]); x -= a[i];
		if (s.find(sum / 2 - x) != s.end()) return true;
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]), sum += a[i];
	if (sum % 2 == 1) printf("NO\n");
	else {
		if (solve()) printf("YES\n");
		else {
			reverse(a, a + n);
			printf(solve() ? "YES\n" : "NO\n");
		}
	}
	return 0;
}