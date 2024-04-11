//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int cnt[N];
int ans[N];
int main() {
	int n; cin >> n;
	int in = 0,res = 0;
	for(int i = 1; i <= n; ++i) {
		char c; int x;
		cin >> c >> x;
		if(c == '+') cnt[x]++,in++;
		if(c == '-' && !cnt[x]) {
			for(int j = 0; j < i; ++j) ans[j]++;
		}
		if(c == '-' && cnt[x]) cnt[x]--,in--;
		ans[i] = in;
	}
	for(int i = 0; i <= n; ++i) res = max(res,ans[i]);
	cout << res << endl;
	return 0;
}