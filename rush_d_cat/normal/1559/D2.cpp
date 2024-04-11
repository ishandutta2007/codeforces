#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

struct dsu {
	vector<int> par;
	void init(int n) {
		par.resize(n);
		for (int i = 0; i < n; i ++) par[i] = i;
	}
	int find(int x) {
		return par[x] == x ? x: par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		par[find(x)] = find(y);
	}
	int comp() {
		int ans = 0;
		for (int i = 0; i < par.size(); i ++) 
			if (find(i) == i) ans ++;
		return ans;
	}
} A, B;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	A.init(n); B.init(n);
	for (int i = 0; i < m1; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		A.unite(u, v);
	}
	
	for (int i = 0; i < m2; i ++) {
		int u, v;
		cin >> u >> v;
		u --, v --;
		B.unite(u, v);
	}
	if (A.comp() > B.comp()) swap(A, B);

	//printf("ok\n");
	set<int> st[n], st2[n];
	map<int,int> mp[n];

	priority_queue< pair<int,int> > rows;
	for (int i = 0; i < n; i ++) {
		st[A.find(i)].insert(B.find(i));
		st2[B.find(i)].insert(A.find(i));
		mp[A.find(i)][B.find(i)] = i;
	}

	for (int i = 0; i < n; i ++) if (st[i].size() > 0)
		rows.push({st[i].size(), i});

	vector<pair<int,int> > ans;
	auto mergeRow = [&](int r1, int r2) {
		int id = A.find(*st[r2].begin());
		for (auto x: st[r1]) {
			st[r2].insert(x);
			A.unite(x, id);
			mp[r2][x] = mp[r1][x];
		}
		for (auto x: st[r1]) {
			st2[x].erase(r1);
			st2[x].insert(r2);
		}
		st[r1].clear();
	};
	auto mergeCol = [&](int c1, int c2) {
		int id = B.find(*st2[c2].begin());
		for (auto x: st2[c1]) {
			mp[x][c2] = mp[x][c1];
			st2[c2].insert(x);
			B.unite(x, id);
		}
		for (auto x: st2[c1]) {
			st[x].erase(c1);
			st[x].insert(c2);
		}
		st2[c1].clear();
	};
	while (rows.size() > 1) {
		auto r1 = rows.top();  rows.pop();
		auto r2 = rows.top();  rows.pop();


		//if (st[r1.second].size() <= 1) break;
		auto it = st[r1.second].begin();		
		int col1 = *it; 
		int col2 = -1;
		it ++;
		if (it != st[r1.second].end()) {
			col2 = *it;
		}
		int col3 = *st[r2.second].begin();
		
		//printf("%d %d %d\n", col1, col2, col3);
		int c1, c2;	
		if (col1 != col3) 
			c1 = col1, c2 = col3;
		else 
			c1 = col2, c2 = col3;
		
		ans.push_back({mp[r1.second][c1], mp[r2.second][c2]});
		if (st[r1.second].size() > st[r2.second].size()) 
			swap(r1, r2);	

		mergeRow(r1.second, r2.second);
		if (st2[c1].size() > st2[c2].size()) swap(c1, c2);
		mergeCol(c1, c2);
		if (st[r2.second].size() > 0)
			rows.push({st[r2.second].size(), r2.second});
	}
	cout << ans.size() << endl;
	for (auto p: ans) 
		cout << p.first+1 << " " << p.second+1 << "\n";
}