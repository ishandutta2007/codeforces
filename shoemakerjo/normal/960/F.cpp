#include <bits/stdc++.h>

using namespace std;
#define maxn 100010
#define pii pair<int, int> 

int n, m;

set<pii> ch[maxn]; //cur stuff that it available

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	int a, b, w;
	vector<tuple<int, int, int, int>> edges;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edges.push_back(make_tuple(w, -i, a, b));
	}
	int ind;
	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());
	int ans = 0;
	for (int i = 0; i < edges.size(); i++) {
		w = get<0>(edges[i]);
		ind = 0-get<1>(edges[i]);
		a = get<2>(edges[i]);
		b = get<3>(edges[i]);
		int bes = 0;
		auto it = ch[b].lower_bound(pii(ind, -1));

		if (it != ch[b].end()) {
			
			// cout << "   here  " << it->second << endl;
			bes = it->second;
		}
		bes++;
		// cout << w << " " << ind << "  " << a << "->" << b << "  bes: " 
		// 	<< bes << endl;
		ans = max(ans, bes);
		it = ch[a].lower_bound(pii(ind, -1));
		bool shouldinsert = true;
		if (it != ch[a].end()) {
			
			if (it->second >= bes) shouldinsert = false;
		}
		// cout << "starting should insert" << endl;
		if (shouldinsert) {
			it = ch[a].lower_bound(pii(ind, 2*n+2*m));
			if (it != ch[a].begin()) {
				--it;
				while (it->second <= bes) {
					it = ch[a].erase(it);
					if (it == ch[a].begin()) break;
					--it;
				}
			}
			
			ch[a].insert(pii(ind, bes));
		}
		// cout << "ending should insert" << endl;
		
	}
	cout << ans << endl;
	cin >> n;


}