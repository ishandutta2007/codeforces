
// Problem : B. Food Buying
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t;
    cin >> t;
    while (t--) {
    	int s;
    	cin >> s;
    	
    	int ret = 0;
    	while (s >= 10) {
    		int change = s / 10;
    		ret += change * 10;
    		s = s % 10 + change;
    	}
    	
    	cout << ret + s << "\n";
    }

    return 0;
}