#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T; cin >> T;
    while (T --) {
    	int n, k;
    	cin >> n >> k;
    	vector<int> ans;
    	for (int i = n; i >= 1; i --) if (i != k && 2 * i >= k) {
    		ans.push_back(i);
    	}
    	cout << ans.size() << endl;
    	for (auto x: ans) {
    		cout << x << " ";
    	}
    	cout << endl;
    }	
}