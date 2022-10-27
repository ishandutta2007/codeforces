#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; 
	cin >> t;
	while (t --) {
		int n, m; 
		cin >> n >> m;
		set<int> g[n + 1];
		for (int i = 1; i <= n; i ++) g[i].clear();
		for (int i = 1; i <= m; i ++) {
			int u, v; cin >> u >> v;
			g[u].insert(v); g[v].insert(u);
		}

		int cur = 1;
		set< pair<int,int> > st;
		vector<int> p(n+1, 0), q(n+1, 0);

		for (int i = 1; i <= n; i ++) st.insert(make_pair(g[i].size(), i));
		vector<int> deg(n+1, 0); 
		for (int i = 1; i <= n; i ++) deg[i] = g[i].size();

		int total = n; set<int> done, undone;

		while (st.size()) {
			pair<int,int> pii = (*st.rbegin());
			int u = pii.second;
			if (deg[u] < total - 1) break;
			p[u] = q[u] = cur ++; total --;
			done.insert(u);
			st.erase(pii);

			for (auto v: g[u]) {
				if (st.find(make_pair(deg[v], v)) != st.end()) {
					st.erase(make_pair(deg[v],v));
					-- deg[v];
					st.insert(make_pair(deg[v],v));
				}
			}
		}
		
		set<int> todo;
		for (int i = 1; i <= n; i ++) if (done.find(i) == done.end()) todo.insert(i);
		undone = todo;

		vector<int> centre(n+1, -1), cnt(n+1, 0);

		while (todo.size()) {
			int u = (*todo.begin()); todo.erase(u); 
			// cout << u << endl;
			vector<int> link2u;
			for (auto x: todo) {
				if (g[u].find(x) == g[u].end()) {
					link2u.push_back(x);
				}
			}
			if (link2u.size() > 0) {
				centre[u] = u;
				for (auto x: link2u) centre[x] = u;
				cnt[u] = link2u.size() + 1;
				for (auto x: link2u) todo.erase(x);
				// cout << cnt[u] << endl;
				// cout << u << "|"; for (auto x: link2u) cout << x << " "; cout << endl;
			} else {
				int v = -1;
				for(auto i: undone) if(i!=u && g[u].find(i)==g[u].end()){
					v=i; break;
				}
				assert(v != -1 && centre[v] != v);
				// cout << v << endl;
				if (cnt[centre[v]] >= 3) {
					cnt[centre[v]] --;
					centre[v] = u;  
					centre[u] = u; 
					cnt[u] = 2; 
				} else if (cnt[centre[v]] == 2){
					centre[centre[v]] = v;
					centre[u] = v;
					centre[v] = v;
					vector<int> link2v;
					for (auto x: todo) {
						if (g[v].find(x) == g[v].end()) {
							link2v.push_back(x);
						}
					}
					for (auto x: link2v) {
						centre[x] = v; todo.erase(x);
					}
					cnt[v] = 3 + link2v.size();
				} else {
					assert(false);
				}
			}
		}
		// cout << "!" << endl;

		vector<int> vec[n + 2];
		for (int i = 1; i <= n; i ++) vec[i].clear();

		for (int i = 1; i <= n ; i ++)
			if (done.find(i) == done.end()) {
				assert(centre[i] >= 1 && centre[i] <= n);
				vec[centre[i]].push_back(i);
			}


		int tot = 0; for (int i = 1; i <= n; i ++) tot += vec[i].size();
		assert(tot + done.size() == n);
		set<int> cset;
		for (int i = 1; i <= n; i ++) if(done.find(i) == done.end()) cset.insert(centre[i]);
		// for (auto x: cset) assert(centre[x] == x);
		for (int i = 1; i <= n; i ++) {
			if (centre[i] == i) {
				// cout << "!"; for (auto x: vec[i]) cout << x << ","; cout<<endl;
				int tmp;
				{
					tmp = cur;
					for (auto x: vec[i]) if (x != i)
						p[x] = tmp ++;
					p[i] = tmp ++;
				}
				
				{
					tmp = cur;
					q[i] = tmp ++;
					for (auto x: vec[i]) if (x != i) 
						q[x] = tmp ++;
				}	
				cur = tmp;
			}
  		} 

  		for (int i = 1; i <= n; i ++) cout<<p[i]<<" \n"[i==n];
  		for (int i = 1; i <= n; i ++) cout<<q[i]<<" \n"[i==n];
	}
}