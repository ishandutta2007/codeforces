#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

vector<int> g[N];

int main() {
	for (int i = 1; i < N; i ++) for (int j = i; j < N; j += i) g[j].push_back(i);

	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);		
    int t; cin >> t;

    while (t --) {
    	int n; cin >> n;
    	vector<int> cnt(N, 0); 
    	for (int i = 1; i <= n; i ++) {
    		int x; cin >> x; cnt[x] ++;
    	}
    	vector<int> dp(N, 0);
    	for (int i = 1; i < N; i ++) {
    		dp[i] = cnt[i];
    		for (auto x: g[i]) {
    			if (i > x) {
    				dp[i] = max(dp[i], dp[x] + cnt[i]);
    			}
    		}
    	}
    	cout << ( n - (*max_element(dp.begin(), dp.end()))) << endl;
    }
}