#include <bits/stdc++.h>
using namespace std;
struct strongly_connected_components{
	vector<vector<int>> ans;
	vector<int> scc;
	void dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v){
		for (int w : E[v]){
			if (!used[w]){
				used[w] = true;
				dfs1(E, t, used, w);
			}
		}
		t.push_back(v);
	}
	void dfs2(vector<vector<int>> &E2, vector<bool> &used2, int v){
		ans.back().push_back(v);
		for (int w : E2[v]){
			if (!used2[w]){
				used2[w] = true;
				dfs2(E2, used2, w);
			}
		}
	}
	strongly_connected_components(vector<vector<int>> &E){
		int N = E.size();
		vector<vector<int>> E2(N);
		for (int i = 0; i < N; i++){
			for (int j : E[i]){
				E2[j].push_back(i);
			}
		}
		vector<int> t;
		vector<bool> used(N, false);
		for (int i = 0; i < N; i++){
			if (!used[i]){
				used[i] = true;
				dfs1(E, t, used, i);
			}
		}
		reverse(t.begin(), t.end());
		vector<bool> used2(N, false);
		scc = vector<int>(N);
		int cnt = 0;
		for (int i = 0; i < N; i++){
			if (!used2[t[i]]){
				used2[t[i]] = true;
				ans.push_back(vector<int>());
				dfs2(E2, used2, t[i]);
				for (int j : ans.back()){
					scc[j] = cnt;
				}
				cnt++;
			}
		}
	}
	int operator [](int k){
		return scc[k];
	}
	int size(){
		return ans.size();
	}
};
void dfs(vector<vector<pair<int, int>>> &E, vector<int> &id, vector<long long> &d, vector<long long> &g, int v){
  for (auto P : E[v]){
    int w = P.second;
    if (id[v] == id[w]){
      if (d[w] == -1){
        d[w] = d[v] + P.first;
        dfs(E, id, d, g, w);
      } else {
        long long D = abs(d[w] - (d[v] + P.first));
        g[id[v]] = gcd(g[id[v]], D);
      }
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> E1(n);
  vector<vector<int>> E2(n);
  for (int i = 0; i < m; i++){
    int a, b, l;
    cin >> a >> b >> l;
    a--;
    b--;
    E1[a].push_back(make_pair(l, b));
    E2[a].push_back(b);
  }
  strongly_connected_components S(E2);
  int cnt = S.size();
  vector<int> id(n);
  vector<int> r(cnt, -1);
  for (int i = 0; i < n; i++){
    id[i] = S[i];
    if (r[id[i]] == -1){
      r[id[i]] = i;
    }
  }
  vector<long long> g(cnt, 0);
  vector<long long> d(n, -1);
  for (int i = 0; i < cnt; i++){
    d[r[i]] = 0;
    dfs(E1, id, d, g, r[i]);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int v, s, t;
    cin >> v >> s >> t;
    v--;
    long long g2 = gcd(g[id[v]], t);
    if (s % g2 == 0){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}