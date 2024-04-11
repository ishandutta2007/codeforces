#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long LL;
const int N = 300000 + 10;
vector<int> g1[N], g2[N];
set<int> st;
int isleaf[N];
int ans = 0, res = 0, L[N], R[N], C, who[N];

void add(int u) {
	//printf("add %d\n", u);
	if (st.size()) {
		auto it = st.lower_bound(L[u]);
		if (it != st.begin()) {
			-- it;
			int p = who[(*it)];
			if (R[p] >= L[u]) { 
				if (isleaf[p]) {
					isleaf[p] = false; ans --;
				}
			}
		}
		it = st.lower_bound(L[u]);
		if (it != st.end()) {
			int p = who[(*it)];
			if (L[p] > R[u]) {
				isleaf[u] = true; ans ++;
			}
		} else {
			isleaf[u] = true; ans ++;
		}
	} else {
		isleaf[u] = 1; ans ++;
	}

	st.insert(L[u]);
	res = max(res, ans);
}
void del(int u) {
	//printf("del %d\n", u);
	if (isleaf[u]) {
		isleaf[u] = 0; ans --;
	}
	st.erase(L[u]);
	if (st.size()){
		auto it = st.lower_bound(L[u]);
		if (it != st.begin()) {
			--it;
			int p = who[(*it)];
			if (R[p] >= L[u]) {
				auto it2 = st.upper_bound(L[p]);
				if (it2 == st.end() || L[who[(*it2)]] > R[p]) {
					if (isleaf[p] == 0) ans ++;
					isleaf[p] = 1; 
				}
			}
		}
	}
	res = max(res, ans);
}

void dfs2(int u) {
	L[u] = ++C; who[C] = u;
	for (auto v: g2[u]) {
		dfs2(v);
	}
	R[u] = C;
}
void dfs1(int u) {
	add(u);
	for (auto v: g1[u]) dfs1(v);
	del(u);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t --) {
		int n; cin >> n; 
		st.clear(); 
		res = ans = C = 0;
		for (int i = 1; i <= n; i ++) isleaf[i] = 0;
		for (int i = 1; i <= n; i ++) {
			g1[i].clear(); g2[i].clear();
		}
		for (int i = 2; i <= n; i ++) {
			int x; cin >> x; g1[x].push_back(i);
		}
		for (int i = 2; i <= n; i ++) {
			int x; cin >> x; g2[x].push_back(i);
		}
		dfs2(1);
		dfs1(1);
		cout << res << endl;
	}	
}