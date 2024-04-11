#include "bits/stdc++.h"

#define int long long
#define forn(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
    	int n, m;
    	cin >> n >> m;
    	vector<int> p(n, -1);
    	forn (i, m) {
    		int x, y;
    		cin >> x >> y;
    		x--;
    		y--;
    		p[x] = y;
    	}
    	vector<bool> used(n);
    	int ans = m;
    	forn (i, n) {
    		if (p[i] == i) {
    			ans--;
    			continue;
    		}
    		if (used[i]) {
    			continue;
    		}
    		int cur = i;
    		while (true) {
    			used[cur] = true;
    			cur = p[cur];
    			if (cur == i) {
    				ans++;
    				break;
    			}
    			if (cur == -1) {
    				break;
    			}
    			if (used[cur]) {
    				break;
    			}
    		}
    	}
    	cout << ans << endl;
    }
}