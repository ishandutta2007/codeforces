#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int t; cin >> t;
	while (t --) {
		int n; cin >> n;
		string ans = "";
	
		if (n>1){
			for (int i = 1; i <= n / 2; i ++) ans += "a";
			ans += "b";
			for (int i = 1; i < n / 2; i ++) ans += "a";
		}
		if (n & 1) ans += "c";
		cout << ans << endl;
	}
}
/*
aaabbb
*/