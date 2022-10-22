#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
using namespace std;
int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	int T;
	scanf("%d", &T);
	while (T--) {
		string s;
		cin >> s;
		vector<int> bin(26);
		int pos = (int)s.size() - 1;
		per(i, (int)s.size() - 1, 0) {
			if (++bin[s[i] - 'a'] == 1) {
				pos = i;
			}
		}
		cout << s.substr(pos) << '\n';
	}
}