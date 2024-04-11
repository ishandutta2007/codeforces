#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <functional>

using namespace std;

class AdjGraph {
	public:
		int n;
		std::vector< std::vector<int> > a;

		AdjGraph(int nodes) {
		    int i;
            n = nodes;
            for(i=0; i<n; i++) {
                std::vector<int> e;
                a.push_back(e);
            }
		}

		void add(int i, int j) {
			a[i].push_back(j);
			a[j].push_back(i);
		}
		
		vector<int> path(int u, int v) {
			int i;
			int pred[n] = {};
			int visited[n] = {};
			queue<int> to;
			to.push(u);
			visited[u] = 1;
			while(!to.empty()) {
				int node = to.front();
				to.pop();
				for(int con:a[node]) {
					if(!visited[con]) {
						pred[con] = node;
						if(con == v) {
							vector<int> rev;
							while(v != u) {
								rev.push_back(v);
								v = pred[v];
							}
							rev.push_back(u);
							vector<int> answer;
							for(i=rev.size()-1; i>=0; i--) {
								answer.push_back(rev[i]);
							}
							return answer;
						}
						visited[con] = 1;
						to.push(con);
					}
				}
			}
		}
		
		vector<vector<int> > components() {
			int i;
			int visited[n] = {};
			queue<int> to;
			vector<vector<int> > answer;
			for(i=0; i<n; i++) {
				if(!visited[i]) {
					vector<int> e;
					visited[i] = 1;
					to.push(i);
					e.push_back(i);
					while(!to.empty()) {
						int node = to.front();
						to.pop();
						for(int con:a[node]) {
							if(!visited[con]) {
								visited[con] = 1;
								to.push(con);
								e.push_back(con);
							}
						}
					}
					answer.push_back(e);
				}
			}
			return answer;
		}
		
		void print() {
			int i, j;
			for(i=0; i<a.size(); i++) {
				printf("%d: ", i);
				for(j=0; j<a[i].size(); j++) {
					printf("%d ", a[i][j]);
				}
				printf("\n");
			}
		}
};

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	int h, i, j;
	int t, n, m, q;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &q);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		int p[n];
		AdjGraph g(n);
		for(i=1; i<n; i++) {
			scanf("%d", &p[i]);
			p[i]--;
			g.add(i, p[i]);
		}
		int v[q], l[q], k[q];
		for(i=0; i<q; i++) {
			scanf("%d %d %d", &v[i], &l[i], &k[i]);
			v[i]--;
		}
		vector<int> query[n];
		for(i=0; i<q; i++) {
			query[v[i]].push_back(i);
		}
		int answer[q];
		int idx[n+1];
		for(i=0; i<=n; i++) {
			idx[i] = i;
		}
		pair<int, int> count[n+1];
		for(i=0; i<=n; i++) {
			count[i] = pair<int, int>{0, i};
		}
		int visited[n] = {};
		visited[0] = 1;
		function<void(int)> dfs = [&](int node) {
			int val = a[node];
			int swap_idx = lower_bound(count, count+n+1, pair<int, int>{count[idx[val]].first+1, -1}, cmp)-count-1;
			count[idx[val]].first++;
			swap(count[swap_idx], count[idx[val]]);
			swap(idx[count[swap_idx].second], idx[count[idx[val]].second]);
			for(int i:query[node]) {
				int skip_idx = lower_bound(count, count+n+1, pair<int, int>{l[i], -1}, cmp)-count-1;
				if(skip_idx+k[i] > n) {
					answer[i] = -1;
				} else {
					answer[i] = count[skip_idx+k[i]].second;
				}
			}
			/*for(i=0; i<n+1; i++) {
				printf("%d ", idx[i]);
			}
			printf("\n");
			for(i=0; i<n+1; i++) {
				printf("%d ", count[i].first);
			}
			printf("\n");
			for(i=0; i<n+1; i++) {
				printf("%d ", count[i].second);
			}
			printf("\n");*/
			for(int con:g.a[node]) {
				if(!visited[con]) {
					visited[con] = 1;
					dfs(con);
				}
			}
			swap_idx = upper_bound(count, count+n+1, pair<int, int>{count[idx[val]].first-1, -1}, cmp)-count;
			count[idx[val]].first--;
			swap(count[swap_idx], count[idx[val]]);
			swap(idx[count[swap_idx].second], idx[count[idx[val]].second]);
		};
		dfs(0);
		for(i=0; i<q; i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	}
}