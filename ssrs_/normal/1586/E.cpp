#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    E[y].push_back(x);
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v] && p[w] == -1){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  vector<int> A(n, 0);
  int q;
  cin >> q;
  vector<vector<int>> path(q);
  vector<int> cnt(n);
  for (int i = 0; i < q; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    cnt[a]++;
    cnt[b]++;
    vector<int> pa = {a};
    while (pa.back() != 0){
      A[pa.back()]++;
      int v = p[pa.back()];
      pa.push_back(v);
    }
    vector<int> pb = {b};
    while (pb.back() != 0){
      A[pb.back()]++;
      int v = p[pb.back()];
      pb.push_back(v);
    }
    while (pa.size() >= 2 && pb.size() >= 2){
      if (pa[pa.size() - 2] == pb[pb.size() - 2]){
        pa.pop_back();
        pb.pop_back();
      } else {
        break;
      }
    }
    for (int x : pa){
      path[i].push_back(x);
    }
    pb.pop_back();
    reverse(pb.begin(), pb.end());
    for (int x : pb){
      path[i].push_back(x);
    }
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    if (A[i] % 2 == 1){
      ok = false;
    }
  }
  if (ok){
    cout << "YES" << endl;
    for (int i = 0; i < q; i++){
      int x = path[i].size();
      cout << x << "\n";
      for (int j = 0; j < x; j++){
        cout << path[i][j] + 1;
        if (j < x - 1){
          cout << ' ';
        }
      }
      cout << "\n";
    }
  } else {
    cout << "NO" << endl;
    int ans = 0;
    for (int i = 0; i < n; i++){
      if (cnt[i] % 2 == 1){
        ans++;
      }
    }
    cout << ans / 2 << endl;
  }
}