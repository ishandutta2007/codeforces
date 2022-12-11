    #pragma GCC diagnostic ignored "-Wunused-result"
    #include <bits/stdc++.h>
    #define all(v) v.begin(), v.end()
    using namespace std;
    typedef long long ll;
    const int INF = (int)1e9 + 41;
     
     
    void solve() {
    	int n;
    	cin >> n;
    	vector<map<int, int>> nxC(n + 1);
    	vector<int> a(n), nx(n, -1);
    	for (int i = 0; i < n; i++) {
    		cin >> a[i];
    	}    

    	for (int i = n - 1; i >= 0; i--) {
    		if (nxC[i + 1].count(a[i])) {
    			nx[i] = nxC[i + 1][a[i]];
    			swap(nxC[i], nxC[nx[i] + 1]);
    			if (nx[i] + 1 < n) {
    				nxC[i][a[nx[i] + 1]] = nx[i] + 1;
    			}
    		}
    		nxC[i][a[i]] = i;
    	}

    	vector<int> jmp(n + 1, 0);
    	for (int i = n - 1; i >= 0; i--) {
    		if (nx[i] != -1) jmp[i] = 1 + jmp[nx[i] + 1];
    	}
     
    	ll ans = 0;
    	for (int i = 0; i < n; i++) {
    		ans += jmp[i];
    	}
     
    	cout << ans << "\n";
    }
     
    int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	int t;
    	cin >> t;
    	while (t--) solve();
    }