#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);

	int t;
	cin >> t;
	while (t --) {
		int n; 
		string s;
		cin >> n >> s;

		int rem = n, cnt = 0;
		for (int i = 0, j = 0; i < n; i = j) {
			if (i == n-1) break;
			// )(
			if (s[i] == ')' and s[i+1] == '(') {
				j = i + 1;
				while (j < n and s[j] == '(') j ++;
				if (j < n and s[j] == ')') {
					rem = n - 1 - j; cnt ++;
					j ++;
				}
			} else {
				rem -= 2; cnt ++; j += 2;
			}
		}
		cout << cnt << " " << rem << "\n";
	}
}