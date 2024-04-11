#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		int a[n];
		set<int> s;
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) s.insert(((i + a[i]) % n + n) % n);
		if (s.size() == n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}