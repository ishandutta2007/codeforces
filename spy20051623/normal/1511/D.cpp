#include <bits/stdc++.h>

#define ll long long
using namespace std;
int t;
int n, k;

int main() {
// 	freopen("in.txt", "r", stdin);
	cin >> n >> k;
	if (k == 1) {
		for (int i = 1; i <= n; i++) {
			cout << 'a';
		}
		puts("");
	} else {
		string s;
//		s = 'a' + k - 1;
		bool vis[28] = {0};
		for (int i = 0; i < k; i++) {
			if (vis[i] == 0) {
				s += 'a' + i;
				vis[i] = 1;
			}
			for (int j = i + 1; j < k; j++) {
				s += 'a' + i;
				s += 'a' + j;
				if (vis[j] == 0) {
					s += 'a' + j;
					vis[j] = 1;
				}
			}
		}
//		cout<<s;

//		string tem=s;
		while (n >= s.length()) {
			cout << s;
			n -= s.length();
		}
		if (n > 0) {
			for (int i = 0; i < n; i++) {
				cout << s[i];
			}
		}
		puts("");
// 		cout << s.length();
	}
	return 0;
}