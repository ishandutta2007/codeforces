#include <bits/stdc++.h>

using namespace std;

stack<int> s, t;
char a[200005];
int b[200005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n + n; ++i) {
		getchar();
		scanf("%c", &a[i]);
		if (a[i] == '-') scanf("%d", &b[i]);
	}
	for (int i = n + n - 1; i >= 0; --i) {
		if (a[i] == '+') {
			if (s.empty()) {
				puts("NO");
				return 0;
			}
			t.push(s.top());
			s.pop();
		} else {
			if (!s.empty() && b[i] > s.top()) {
				puts("NO");
				return 0;
			}
			s.push(b[i]);
		}
	}
	puts("YES");
	while (!t.empty()) {
		printf("%d ", t.top());
		t.pop();
	}
	return 0;
}