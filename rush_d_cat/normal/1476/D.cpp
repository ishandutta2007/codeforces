#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;	
    while (t --) {
    	int n; cin >> n;
    	string s; cin >> s; s = "0" + s;

    	vector<int> pre(n + 2, 0), suf(n + 2, 0);
    	for (int i = 1; i <= n; i ++) {
    		if (s[i] != s[i-1]) pre[i] = pre[i-1] + 1;
    		else pre[i] = 1;
    	}
    	for (int i = n; i >= 1; i --) {
    		if (s[i] != s[i+1]) suf[i] = suf[i+1] + 1;
    		else suf[i] = 1; 
    	} 
    	for (int i = 0; i <= n; i ++) {
    		int ans = 1;
    		if (s[i+1] == 'R') ans += suf[i+1];
    		if (s[i] == 'L') ans += pre[i];
    		cout << ans << (" \n"[i==n]);
    	}
    }
}