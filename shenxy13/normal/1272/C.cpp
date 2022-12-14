#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main() {
	int n, k, ptr = -1;
	scanf("%d %d", &n, &k);
	char s[n], c;
	for (int i = 0; i < n; ++i) scanf(" %c", &s[i]);
	set<char> aval;
	for (int i = 0; i < k; ++i) {
		scanf(" %c", &c);
		aval.insert(c);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		if (aval.find(s[i]) == aval.end()) ptr = i;
		else ans += i - ptr;
	}
	printf("%lld", ans);
	return 0;
}