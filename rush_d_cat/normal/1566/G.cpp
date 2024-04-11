#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 10;
typedef long long ll;

struct Bit {
	vector<int> a;
	void init(int n) {
		a.resize(n, 0);
	}
	void add(int pos, int x) {
		while (pos < a.size()) {
			a[pos] += x; pos += pos & (-pos);
		}
	}
	int sum(int pos) {
		int ans = 0;
		while (pos > 0) {
			ans += a[pos]; pos -= pos & (-pos);
		}
		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector< tuple<int,int,int> > e, query, vec;
	vector< tuple<int,int,int> > g[n+1];

	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u > v) swap(u, v);
		e.emplace_back(w, u, v);
		g[u].emplace_back(w, u, v);
		g[v].emplace_back(w, u, v);
		vec.emplace_back(w, u, v);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i ++) {
		int tp, u, v, w; cin >> tp;
		if (tp == 0) {
			cin >> u >> v;
			if (u > v) swap(u, v);
			query.emplace_back(tp, u, v);
		} else {
			cin >> u >> v >> w;
			if (u > v) swap(u, v);
			query.emplace_back(w, u, v);
			g[u].emplace_back(w, u, v);
			g[v].emplace_back(w, u, v);
			vec.emplace_back(w, u, v);
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= n; i ++) {
		sort(g[i].begin(), g[i].end());
		g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
	}

	Bit B[n + 1], allB;
	for (int i = 1; i <= n; i ++) {
		B[i].init((int)g[i].size() + 1);
	}
	allB.init(vec.size() + 1);

	set<tuple<int,int,int> > all;
	set<pair<ll, int> > triple;
	set<tuple<int,int,int> > edges[n+1];

	auto getAns = [&]() {
		ll ans = 1e18;
		if (triple.size() > 0) {
			ans = min(ans, triple.begin()->first);
		}
		/*
		for (auto [w,u]: triple) {
			cout << w << " " << u << "\n";
		}
		*/
		assert(all.size() > 0);
		auto [w,a,b] = (*all.begin());
		vector< tuple<int,int,int> > fa, fb;
		//cout << "min " << w << " " << a << " " << b << "\n";
		if (! edges[a].empty()) {
			auto it = edges[a].begin();
			for (int i = 1; i <= 3; i ++) {
				it = next(it);
				if (it == edges[a].end()) break;
				auto [x,y,z] = (*it);
				fa.emplace_back((*it));
			}
		}	

		if (! edges[b].empty()) {
			auto it = edges[b].begin();
			for (int i = 1; i <= 3; i ++) {
				it = next(it);
				if (it == edges[b].end()) break;
				fb.emplace_back((*it));
			}
		}

		for (auto [wa, ua, va]: fa) for (auto [wb, ub, vb]: fb) {
			if ((ua ^ va ^ a) != (ub ^ vb ^ b))
				ans = min(ans, 1ll * wa + wb);
		}
		//cout << "2 current ans is " << ans << "\n";
		int lef = lower_bound(vec.begin(), vec.end(), (*all.begin())) - vec.begin(), rig = (int)vec.size();

		while (rig > lef) {
			int mid = (lef + rig) >> 1;
			//printf("edge = [%d,%d,%d]\n", get<0>(vec[mid]), get<1>(vec[mid]), get<2>(vec[mid]));
			int id1 = upper_bound(g[a].begin(), g[a].end(), vec[mid]) - g[a].begin();
			int id2 = upper_bound(g[b].begin(), g[b].end(), vec[mid]) - g[b].begin();
			//printf("id1=%d,id2=%d, (%d,%d,%d)\n",id1,id2,B[a].sum(id1),B[b].sum(id2),allB.sum(mid + 1));
			if (B[a].sum(id1) + B[b].sum(id2) - 1 == allB.sum(mid + 1))
				lef = mid + 1;
			else
				rig = mid; 
		}
		if (lef < vec.size())
			ans = min(ans, 1ll * w + get<0>(vec[rig]));
	
		return ans;
	};
	
	auto Update = [&](int i, int sgn) {
		if (edges[i].size() >= 3) {
			auto it = edges[i].begin();
			int v1 = get<0>(*it);
			it = next(it);
			int v2 = get<0>(*it);
			it = next(it);
			int v3 = get<0>(*it);
			ll s = (ll)v1 + v2 + v3;

			if (sgn == +1) 
				triple.insert(make_pair(s, i));
			if (sgn == -1)
				triple.erase(make_pair(s, i));
		}
		return;
	};
	map< pair<int,int>, int > mpw;
	auto AddEdge = [&](tuple<int,int,int> e) {
		all.insert(e);

		auto [w,u,v] = e;
		mpw[make_pair(u, v)] = mpw[make_pair(v, u)] = w;
		//printf("add %d %d %d\n", w, u, v);
		Update(u,-1); Update(v,-1);
		edges[u].insert(e);
		edges[v].insert(e);
		Update(u,+1); Update(v,+1);
		
		{
			int id = lower_bound(vec.begin(), vec.end(), e) - vec.begin() + 1;
			//printf("add id = %d\n", id);
			allB.add(id, 1);
		}
		{
			int id = lower_bound(g[u].begin(), g[u].end(), e) - g[u].begin() + 1;
			B[u].add(id, 1);
		}

		{
			int id = lower_bound(g[v].begin(), g[v].end(), e) - g[v].begin() + 1;
			B[v].add(id, 1);
		}
	};


	
	auto RemoveEdge = [&](tuple<int,int,int> e) {
		all.erase(e);

		auto [w,u,v] = e;
		//printf("remove %d %d %d\n", w, u, v);
		Update(u,-1); Update(v,-1);
		edges[u].erase(e);
		edges[v].erase(e);
		Update(u,+1); Update(v,+1);
		
		{
			int id = lower_bound(vec.begin(), vec.end(), e) - vec.begin() + 1;
			allB.add(id, - 1);
		}
		{
			int id = lower_bound(g[u].begin(), g[u].end(), e) - g[u].begin() + 1;
			B[u].add(id, - 1);
		}
		{
			int id = lower_bound(g[v].begin(), g[v].end(), e) - g[v].begin() + 1;
			B[v].add(id, - 1);
		}
	};

	for (auto edge: e) AddEdge(edge);
	cout << getAns() << "\n";

	
	for (auto que: query) {
		if (get<0>(que) == 0) {
			//printf("w is %d\n", mpw[ make_pair(get<1>(que), get<2>(que)) ]);
			RemoveEdge(make_tuple(mpw[ make_pair(get<1>(que), get<2>(que)) ], get<1>(que), get<2>(que)));
		} else {
			AddEdge(que);
		}
		cout << getAns() << "\n";
	}
}