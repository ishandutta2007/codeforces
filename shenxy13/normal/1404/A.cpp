#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, k, a = 0, b = 0;
		scanf("%d %d", &n, &k);
		char s[n], rep[k];
		for (int i = 0; i < n; ++i) scanf(" %c", &s[i]);
		for (int i = 0; i < k; ++i) rep[i] = s[i];
		bool can = true;
		for (int i = k; i < n; ++i) {
			if (s[i] == '?') continue;
			else if (rep[i % k] == '?') rep[i % k] = s[i];
			else if (rep[i % k] != s[i]) can = false;
		}
		for (int i = 0; i < k; ++i) {
			if (rep[i] == '0') ++a;
			else if (rep[i] == '1') ++b;
		}
		if (can && a <= k / 2 && b <= k / 2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}