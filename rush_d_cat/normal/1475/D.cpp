#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t; cin >> t;
    while (t --) {
    	int n, m; cin >> n >> m;
    	vector<int> a(n), b(n);
    	for (int i = 0; i < n; i ++) cin >> a[i];
    	for (int i = 0; i < n; i ++) cin >> b[i];
    	vector<LL> v1, v2;
    	for (int i = 0; i < n; i ++) {
    		if (b[i] == 1) v1.push_back(a[i]); else v2.push_back(a[i]);
    	}
    	sort(v1.begin(),v1.end(),greater<>());
    	sort(v2.begin(),v2.end(),greater<>());
    	
    	LL sum = accumulate(v2.begin(), v2.end(), 0LL);
    	int score = v2.size() * 2;
    	int ans = 1e9;
    	for (int i = 0, j = (int)v2.size() - 1; i <= v1.size(); i ++) {
    		while (j >= 0 && sum - v2[j] >= m) {
    			sum -= v2[j]; -- j; score -= 2;
    		}
    		if (sum >= m) {
    			ans = min(ans, score);
    		}
    		score ++; if (i < v1.size()) sum += v1[i];
    	}
    	if (ans == 1e9) ans = -1;
    	cout << ans << endl;
    }	
}