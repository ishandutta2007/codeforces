    #pragma GCC diagnostic ignored "-Wunused-result"
    #include <bits/stdc++.h>
    #define all(v) v.begin(), v.end()
    using namespace std;
    typedef long long ll;
     
    void solve() {
    	int n;
    	cin >> n;
    	vector<int> a(n + 1);
    	for (auto &x : a) cin >> x;
    	bool perfect = true;
    	for (int i = 1; i <= n; i++) {
    		if (a[i] > 1 && a[i - 1] > 1) perfect = false;
    	}
    	if (perfect) {
    		cout << "perfect\n";
    		return;
    	}
    	cout << "ambiguous\n";
    	vector<int> v1 = {0}, v2 = {0};
    	int prev = 0;
    	for (int h = 1; h <= n; h++) {
    		for (int i = 0; i < a[h]; i++) {
    			v1.push_back(prev + 1);
    			v2.push_back(prev + (a[h - 1] == 1 ? 0 : -i % 2) + 1);
    		}
    		prev += a[h];
    	}
     
    	for (auto x : v1) cout << x << " ";
    	cout << "\n";
    	for (auto x : v2) cout << x << " ";
    	cout << "\n";
    }
     
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	solve();
    #ifdef MADE_BY_SERT
    	int T = 2;
    	for (int i = 1; i < T; i++) solve();	
    #endif
    }