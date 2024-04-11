#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<ii> v;
	for(int i = 0; i< n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	int ans = 0;
	for(int www = 0; www < 2; www++) {
		for(int i = 0 ; i < n; i++) {
			for(int j = i + 1; j < n; j++) {
				auto p = v[i], q = v[j];
				int x1 = p.first, y1 = p.second, x2 = q.first, y2 = q.second;
				if(x1 <= a && x2 <= a && y1 <= b && y2 <= b && (x1 + x2 <= a || y1 + y2 <= b))
					ans = max(ans, x1*y1 + x2*y2);
				swap(x2, y2);
				if(x1 <= a && x2 <= a && y1 <= b && y2 <= b && (x1 + x2 <= a || y1 + y2 <= b))
					ans = max(ans, x1*y1 + x2*y2);
			}
		}
		swap(a, b);
	}
	cout << ans << '\n';
}