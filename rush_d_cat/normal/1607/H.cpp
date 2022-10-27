#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		vector<int> a(n), b(n), c(n);
		for (int i = 0; i < n; i ++)
			cin >> a[i] >> b[i] >> c[i];

		map<int, vector<tuple<int,int,int> > > mp;
		for (int i = 0; i < n; i ++) {
			// a[i] >= x
			// x >= c[i] - b[i]
			mp[a[i] + b[i] - c[i]].push_back({a[i] - min(a[i], c[i]), a[i] - max(c[i] - b[i], 0), i});
		}
		
		vector<int> res(n, 0);
		auto cal = [&](vector<tuple<int,int,int> > v) {
			sort(v.begin(), v.end(), [](tuple<int,int,int> x, tuple<int,int,int>  y){
				return get<1>(x) < get<1>(y);
			});

			int las = -1e9;
			int ans = 0;
			for (auto [x, y, i]: v) {
				//printf("%d %d %d\n", x, y, i);
				if (x <= las) {
					//printf("res[%d] = %d\n", i, las);
					res[i] = las;
					continue;
				}
				las = y; 
				res[i] = las;
				ans ++;
			}
			return ans;
		};
		int ans = 0;
		for (auto p: mp) {
			ans += cal(p.second);
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i ++)
			cout << a[i] - res[i] << " " << (c[i] - (a[i] - res[i])) << "\n";
			
	}
}