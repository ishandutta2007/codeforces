#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	cin >> n;
	vector<vector<int>> p;
	vector<vector<int>> sr;
	set<vector<int>> s;
	int x, y;
	for(i=0; i<n; i++) {
		cin >> x >> y;
		p.push_back({x, y});
		sr.push_back({x, y, i});
		s.insert({x, y});
	}
	sort(sr.begin(), sr.end());
	vector<int> d(n, INT_MAX);
	vector<int> visited(n, 0);
	vector<vector<int>> answer(n, vector<int>{0, 0});
	queue<int> to;
	vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
	for(i=0; i<n; i++) {
		int check = 0;
		for(j=0; j<dir.size(); j++) {
			vector<int> con{p[i][0]+dir[j][0], p[i][1]+dir[j][1]};
			if(!s.count(con)) {
				check = 1;
				answer[i] = con;
			}
		}
		if(check) {
			d[i] = 1;
			to.push(i);
			visited[i] = 1;
		}
	}
	while(!to.empty()) {
		int node = to.front();
		to.pop();
		for(j=0; j<dir.size(); j++) {
			vector<int> con{p[node][0]+dir[j][0], p[node][1]+dir[j][1]};
			if(s.count(con)) {
				int idx = (*lower_bound(sr.begin(), sr.end(), vector<int>{con[0], con[1], -1}))[2];
				if(d[idx] > d[node]+1) {
					answer[idx] = answer[node];
					d[idx] = d[node]+1;
					visited[idx] = 1;
					to.push(idx);
				}
			}
		}
	}
	for(i=0; i<n; i++) {
		cout << answer[i][0] << " " << answer[i][1] << endl;
	}
}