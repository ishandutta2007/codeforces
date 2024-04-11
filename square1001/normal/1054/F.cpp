#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
vector<int> maximum_bipartite_matching(vector<vector<int> > G) {
	int V = G.size();
	vector<int> match(V, -1);
	vector<bool> used;
	function<bool(int)> find_augment = [&](int pos) {
		used[pos] = true;
		for(int i : G[pos]) {
			int w = match[i];
			if(w == -1 || (!used[w] && find_augment(w))) {
				match[pos] = i;
				match[i] = pos;
				return true;
			}
		}
		return false;
	};
	for(int i = 0; i < V; ++i) {
		if(match[i] != -1) continue;
		used = vector<bool>(V, false);
		find_augment(i);
	}
	return match;
}
vector<vector<int> > integrate(vector<vector<int> > es) {
	sort(es.begin(), es.end());
	while(true) {
		bool found = false;
		for(int i = 1; i < es.size(); ++i) {
			if(es[i - 1][0] == es[i][0] && es[i - 1][2] == es[i][1]) {
				es[i - 1][2] = es[i][2];
				es.erase(es.begin() + i);
				found = true;
				break;
			}
		}
		if(!found) break;
	}
	return es;
}
int main() {
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for(int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	map<int, vector<int> > dx, dy;
	for(int i = 0; i < N; ++i) {
		dx[X[i]].push_back(i);
		dy[Y[i]].push_back(i);
	}
	vector<pair<int, int> > ex, ey;
	for(pair<int, vector<int> > i : dx) {
		vector<int> v = i.second;
		sort(v.begin(), v.end(), [&](int j, int k) { return Y[j] < Y[k]; });
		for(int j = 1; j < v.size(); ++j) {
			ex.push_back(make_pair(v[j - 1], v[j]));
		}
	}
	for(pair<int, vector<int> > i : dy) {
		vector<int> v = i.second;
		sort(v.begin(), v.end(), [&](int j, int k) { return X[j] < X[k]; });
		for(int j = 1; j < v.size(); ++j) {
			ey.push_back(make_pair(v[j - 1], v[j]));
		}
	}
	vector<vector<int> > g(ex.size() + ey.size());
	int xid = 0;
	for(pair<int, int> i : ex) {
		int yid = 0;
		for(pair<int, int> j : ey) {
			if(X[j.first] < X[i.first] && X[i.first] < X[j.second] && Y[i.first] < Y[j.first] && Y[j.first] < Y[i.second]) {
				g[xid].push_back(yid + ex.size());
				g[yid + ex.size()].push_back(xid);
			}
			++yid;
		}
		++xid;
	}
	vector<int> match = maximum_bipartite_matching(g);
	vector<bool> marked(ex.size() + ey.size(), false);
	function<void(int, int)> coloring = [&](int pos, int parity) {
		marked[pos] = true;
		if(parity == 1 && match[pos] != -1 && !marked[match[pos]]) {
			coloring(match[pos], 0);
		}
		if(parity == 0) {
			for(int i : g[pos]) {
				if(!marked[i] && match[pos] != i) {
					coloring(i, 1);
				}
			}
		}
	};
	for(int i = 0; i < ex.size(); ++i) {
		if(match[i] == -1 && !marked[i]) coloring(i, 0);
	}
	vector<int> sx, sy;
	for(int i = 0; i < ex.size(); ++i) {
		if(marked[i]) sx.push_back(i);
	}
	for(int i = 0; i < ey.size(); ++i) {
		if(!marked[i + ex.size()]) sy.push_back(i);
	}
	vector<vector<int> > ax, ay;
	for(int i = 0; i < N; ++i) {
		bool found = false;
		for(int j : sx) {
			if(i == ex[j].first || i == ex[j].second) {
				found = true;
			}
		}
		if(!found) ax.push_back({ X[i], Y[i], Y[i] });
	}
	for(int i : sx) {
		ax.push_back({ X[ex[i].first], Y[ex[i].first], Y[ex[i].second] });
	}
	ax = integrate(ax);
	for(int i = 0; i < N; ++i) {
		bool found = false;
		for(int j : sy) {
			if(i == ey[j].first || i == ey[j].second) {
				found = true;
			}
		}
		if(!found) ay.push_back({ Y[i], X[i], X[i] });
	}
	for(int i : sy) {
		ay.push_back({ Y[ey[i].first], X[ey[i].first], X[ey[i].second] });
	}
	ay = integrate(ay);
	cout << ay.size() << endl;
	for(vector<int> i : ay) {
		cout << i[1] << ' ' << i[0] << ' ' << i[2] << ' ' << i[0] << endl;
	}
	cout << ax.size() << endl;
	for(vector<int> i : ax) {
		cout << i[0] << ' ' << i[1] << ' ' << i[0] << ' ' << i[2] << endl;
	}
	return 0;
}