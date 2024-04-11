#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
  }
  vector<tuple<int, int, int>> E(m);
  for (int i = 0; i < m; i++){
    E[i] = make_tuple(a[i], - b[i], i);
  }
  sort(E.begin(), E.end());
  queue<pair<int, int>> next;
  bool ok = true;
  int v = 1;
  vector<pair<int, int>> ans(m);
  for (int i = 0; i < m; i++){
    int b = - get<1>(E[i]);
    int id = get<2>(E[i]);
    if (b == 1){
      v++;
      if (next.size() < 100000){
        for (int j = 2; j < v; j++){
          next.push(make_pair(j, v));
        }
      }
      ans[id] = make_pair(1, v);
    } else {
      if (next.empty()){
        ok = false;
        break;
      } else {
        int x = next.front().first;
        int y = next.front().second;
        next.pop();
        ans[id] = make_pair(x, y);
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    for (int i = 0; i < m; i++){
      cout << ans[i].first << ' ' << ans[i].second << endl;
    }
  }
}