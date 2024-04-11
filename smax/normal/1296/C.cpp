
// Problem : C. Yet Another Walking Robot
// Contest : Codeforces Round #617 (Div. 3)
// URL : https://codeforces.com/contest/1296/problem/C
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
    	int n;
    	string s;
    	cin >> n >> s;
    	
    	map<pair<int, int>, int> mp;
    	mp[{0, 0}] = -1;
    	int x = 0, y = 0, len = INT_MAX, l, r;
    	for (int i=0; i<n; i++) {
    		if (s[i] == 'L') x--;
    		else if (s[i] == 'R') x++;
    		else if (s[i] == 'U') y++;
    		else y--;
    		
    		if (mp.count({x, y}) && i - mp[{x, y}] < len) {
    			len = i - mp[{x, y}];
    			l = mp[{x, y}] + 2;
    			r = i + 1;
    		}
    		mp[{x, y}] = i;
    	}
    	
    	if (len == INT_MAX)
    		cout << "-1\n";
    	else
    		cout << l << " " << r << "\n";
    }

    return 0;
}