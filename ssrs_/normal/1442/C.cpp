#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long INF = 1000000000000;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  vector<vector<int>> E2(n * 20);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      for (int k = 0; k < 20; k++){
        if (k % 2 == 0){
          E2[k * n + i].push_back(k * n + j);
        } else {
          E2[k * n + j].push_back(k * n + i);
        }
      }
    }
    for (int j = 0; j < 19; j++){
      E2[j * n + i].push_back((j + 1) * n + i);
    }
  }
  vector<int> dist(n * 20, -1);
  dist[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E2[v]){
      if (dist[w] == -1){
        dist[w] = dist[v] + 1;
        Q.push(w);
      }
    }
  }
  long long ans = INF;
  for (int i = 0; i < 20; i++){
    if (dist[n * i + (n - 1)] != -1){
      ans = min(ans, (long long) dist[n * i + (n - 1)] - i + (1 << i) - 1);
    }
  }
  if (ans != INF){
    cout << ans << endl;
  } else {
    vector<vector<int>> E3(n);
    for (int i = 0; i < n; i++){
      for (int j : E[i]){
        E3[j].push_back(i);
      }
    }
    vector<pair<int, int>> d1(n, make_pair(-1, -1));
    vector<pair<int, int>> d2(n, make_pair(-1, -1));
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pq.push(make_pair(make_pair(0, 0), 0));
    while (!pq.empty()){
      int tr = pq.top().first.first;
      int mv = pq.top().first.second;
      int v = pq.top().second;
      pq.pop();
      if (tr % 2 == 0 && d1[v].first == -1){
        d1[v] = make_pair(tr, mv);
        if (d2[v].first == -1){
          pq.push(make_pair(make_pair(tr + 1, mv), v));
        }
        for (int w : E[v]){
          if (d1[w].first == -1){
            pq.push(make_pair(make_pair(tr, mv + 1), w));
          }
        }
      }
      if (tr % 2 == 1 && d2[v].first == -1){
        d2[v] = make_pair(tr, mv);
        if (d1[v].first == -1){
          pq.push(make_pair(make_pair(tr + 1, mv), v));
        }
        for (int w : E3[v]){
          if (d2[w].first == -1){
            pq.push(make_pair(make_pair(tr, mv + 1), w));
          }
        }
      }
    }
    long long tr1 = d1[n - 1].first;
    int mv1 = d1[n - 1].second;
    long long tr2 = d2[n - 1].first;
    int mv2 = d2[n - 1].second;
    if (tr1 < tr2){
      cout << (modpow(2, tr1) + mv1 + MOD - 1) % MOD << endl;
    } else {
      cout << (modpow(2, tr2) + mv2 + MOD - 1) % MOD << endl;
    }
  }
}