#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int ans[N], b[N], _, n;

int main() {
	cin.tie(0)->ios::sync_with_stdio(false);
	cin >> _;
	while (_ --) {
		cin >> n;
		memset(b, 0, sizeof b);
		memset(ans, 0, sizeof ans);
		for (int i = 2; i <= n; i += 2) {
			cin >> ans[i];
			b[ans[i]] = i;
		}	
		bool flag = true;
		priority_queue<int> q;
		for (int i = n; i; i --) {
			if (b[i]) q.push(b[i]);
			else {
				if (q.empty()) {
					flag = false;
					break;
				}
				ans[q.top() - 1] = i;
				q.pop();
			}
		}
		if (flag) {
			for (int i = 1; i <= n; i ++) 
			cout << ans[i] << " \n"[i == n];	
		} else {
			cout << "-1\n";
		}
	}
	return 0;	
}