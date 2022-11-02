#include <bits/stdc++.h>
using namespace std;

#define N 333

int a[N][N], b[N][N];

int main() {
	int t;
	cin >> t;
	while(t --) {
		int n;
		cin >> n;
		vector <int> a(n+1);
		for(int i = 1; i <= n; i ++) cin >> a[i];
        auto mex = [&]() {
			vector <bool> vis(n+1, false);
			for(int i = 1; i <= n; i ++) vis[a[i]] = 1;
            int res = 0;
            while(vis[res]) res ++;
            return res;
        };
        vector <int> ans;
        auto good = [&]() {
            for(int i = 1; i < n; i ++) if(a[i] > a[i+1]) return 0;
            return 1;
        };
        int l = 1, r = n;
        while(!good()) {
            int x = mex();
            if(x == r) {
				ans.push_back(r);
				a[r] = r;
				r --;
            }
            else {
				ans.push_back(x+1);
				a[x+1] = x;
            }
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i ++) cout << ans[i] << ' ';
        cout << endl;
	}
}