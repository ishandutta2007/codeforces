#include <bits/stdc++.h>
using namespace std;
long long INF = 100000000;
long long ford_fulkerson(vector<unordered_map<int, long long>> &E, int s, int t){
	int V = E.size();
	long long F = 0;
	while (1){
		vector<int> d(V, INF);
		vector<long long> m(V, INF);
		vector<int> prev(V, -1);
		d[s] = 0;
		queue<int> Q;
		Q.push(s);
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			for (auto P : E[v]){
				int w = P.first;
				if (d[w] == INF){
					prev[w] = v;
					d[w] = d[v] + 1;
					m[w] = min(m[v], P.second);
					Q.push(w);
				}
			}
		}
		if (d[t] == INF){
			break;
		}
		int f = m[t];
		int c = t;
		while (c != s){
			if (E[prev[c]][c] == f){
				E[prev[c]].erase(c);
			} else {
				E[prev[c]][c] -= f;
			}
			E[c][prev[c]] += f;
			c = prev[c];
		}
		F += f;
	}
	return F;
}
int main(){
  cout << fixed << setprecision(10);
  int n, m, x;
  cin >> n >> m >> x;
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a].push_back(make_pair(c, b));
  }
  double tv = 0;
  double fv = INF;
  for (int i = 0; i < 80; i++){
    double mid = (tv + fv) / 2;
    vector<unordered_map<int, long long>> E2(n);
    for (int j = 0; j < n; j++){
      for (auto P : E[j]){
        int c = P.first;
        long long k = P.second;
        E2[j][k] = c / mid;
      }
    }
    if (ford_fulkerson(E2, 0, n - 1) >= x){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  cout << tv * x << endl;
}