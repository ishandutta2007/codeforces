#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int main() {
#ifdef local
	freopen("a.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		string s;
		cin >> s;
		int n = s.size();
		set<int> S;
		bool err = 0;
		rep(i, 0, n - 1) {
			if (isupper(s[i])) {
				if (!S.count(s[i] - 'A' + 'a')) {
					err = 1;
				}
			}
			S.insert(s[i]);
		}
		if (err) {
			puts("NO");
		} else {
			puts("YES");
		}
	}
}