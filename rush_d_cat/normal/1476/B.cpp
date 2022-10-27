#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;	
    while (t --) {
    	int n, k;
    	cin >> n >> k;
    	vector<int> p(n + 1);
    	for (int i = 1; i <= n; i ++) cin >> p[i];
    	LL lef = -1, rig = 1e13;
    	while (rig - lef > 1) {
    		LL mid = (lef + rig) >> 1;
    		bool ok = true;
    		LL sum = mid;
    		for (int i = 1; i < n; i ++) {
    			sum += p[i];
    			// a[i+1] / sum <= k / 100
    			if (!(1LL * 100 * p[i+1] <= k * sum)) {
    				ok = false;
    			} 
    		}
    		if (ok) rig = mid;
    		else lef = mid;
    	}
    	cout << rig << endl;
    }
}