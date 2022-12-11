#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 34;
typedef long long ll;

const int N = 123;
vector<int> es[N];

pair<vector<ll>, vector<ll>> cntMinNum(int st, int n) {
  vector<ll> dist(n, -1);
  dist[st] = 0;
  queue<int> q;
  q.push(st);

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int w : es[v]) {
      if (dist[w] == -1) {
        dist[w] = dist[v] + 1;
        q.push(w);
      }
    }
  }  

  vector<ll> minNum(n, -1);
  minNum[st] = 0;

  q.push(st);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v == st) minNum[v] = 1;
    for (int w : es[v]) {
      if (dist[w] + 1 == dist[v]) 
        minNum[v] += minNum[w];
      if (minNum[w] == -1) {
        minNum[w] = 0;
        q.push(w);
      }
    }
  }  

  // for (int i = 0; i < n; i++) cout << minNum[i] << " ";
  //   cout << "\n";

  minNum[st] = 1;
  return {dist, minNum};
}

void solve() {
  int n, m;
  cin >> n >> m;

  if (n == 2) {
    cout << "1\n";
    return;
  }

  for (int i = 0; i < m; i++) {
    int v1, v2;
    cin >> v1 >> v2;
    v1--;
    v2--;
    es[v1].push_back(v2);
    es[v2].push_back(v1);
  }

  auto q0 = cntMinNum(0, n);
  auto qN = cntMinNum(n - 1, n);

  vector<ll> d0 = q0.second;
  vector<ll> dN = qN.second;

  ll tot = d0[n - 1];  
  ll score = -1;
  int dst = q0.first[n - 1];

  for (int i = 1; i < n - 1; i++) {
    if (d0[i] * dN[i] > score && q0.first[i] + qN.first[i] == dst) {
      score = d0[i] * dN[i];      
    }
  }
  score *= 2;

  double ans = (double)score / tot;
  ans = max(ans, 1.0);

  printf("%.9f\n", ans);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}