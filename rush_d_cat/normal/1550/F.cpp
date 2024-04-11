#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, q, s, d;
	cin >> n >> q >> s >> d;

	vector<int> a(n+1);
	for (int i = 1; i <= n; i ++) cin >> a[i];

	vector<bool> vis(n + 1, false);

	set< pair<int,int> > st;
	set< vector<int> > dis;

	for (int i = 1; i <= n; i ++) 
		st.insert({a[i], i});

	auto get = [&](int from, int to) {
		auto it = st.lower_bound({to, -1});
		pair<int,int> ans = make_pair(1e9, -1);
		if (it != st.end()) {
			auto p = (*it);
			ans = { abs(abs(p.first - a[from]) - d), p.second };
		}
		if (it != st.begin()) {
			-- it;
			auto p = (*it);
			if (abs(abs(p.first - a[from]) - d) < ans.first) {
				ans = { abs(abs(p.first - a[from]) - d), p.second };
			}
		}
		return ans;
	};

	auto add = [&](int x) {
		auto bst = min(get(x, a[x] + d), get(x, a[x] - d));
		//printf("add %d, ins %d %d\n", x,bst.first,bst.second);
		if (bst.second == -1) return;
		dis.insert({bst.first, x, bst.second});
	};

	vector<int> res(n+1, -1);
	add(s); 
	vis[s] = true; st.erase({a[s], s}); res[s]=0;
	int mx = 0;
	while (dis.size()) {
		//printf("heap:");
		//for (auto p: dis) {
		//	printf("(%d,%d,%d)", p[0],p[1],p[2]);
		//}
		//printf("\n");
		auto p = (*dis.begin()); dis.erase(p);
		add(p[1]);
		if (vis[p[2]] == true) continue;
		mx = max(mx, p[0]);

		//printf("\n");
		//printf("res[%d]=%d\n", p[2],mx);	
		vis[p[2]] = true; st.erase({a[p[2]],p[2]}); res[p[2]] = mx;
		add(p[2]); add(p[1]);
	}
	while (q --) {
		int i, k;
		cin >> i >> k;
		cout << ((res[i] == -1 || res[i] > k) ? "No" : "Yes") << endl;
	}
}