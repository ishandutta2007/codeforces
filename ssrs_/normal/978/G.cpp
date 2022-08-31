#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
int ford_fulkerson(vector<unordered_map<int, int>> &E, int s, int t){
	int V = E.size();
	int F = 0;
	while (1){
		vector<int> d(V, INF);
		vector<int> m(V, INF);
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
  int n, m;
  cin >> n >> m;
  vector<int> s(m), d(m), c(m);
  for (int i = 0; i < m; i++){
    cin >> s[i] >> d[i] >> c[i];
    s[i]--;
    d[i]--;
  }
  vector<bool> exam(n, false);
  for (int i = 0; i < m; i++){
    exam[d[i]] = true;
  }
  int sum = 0;
  for (int i = 0; i < m; i++){
    sum += c[i];
  }
  vector<unordered_map<int, int>> E(n + m + 2);
  for (int i = 0; i < n; i++){
    E[0][i] = 1;
  }
  for (int i = 0; i < m; i++){
    E[1 + n + i][1 + n + m] = c[i];
  }
  for (int i = 0; i < m; i++){
    for (int j = s[i]; j < d[i]; j++){
      if (!exam[j]){
        E[j + 1][1 + n + i] = 1;
      }
    }
  }
  int F = ford_fulkerson(E, 0, n + m + 1);
  if (F < sum){
    cout << -1 << endl;
  } else {
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++){
      if (exam[i]){
        ans[i] = m + 1;
      } else if (!E[0].count(i + 1)){
        for (int j = 0; j < m; j++){
          if (E[1 + n + j].count(i + 1)){
            ans[i] = j + 1;
          }
        }
      }
    }
    for (int i = 0; i < n; i++){
      cout << ans[i];
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}