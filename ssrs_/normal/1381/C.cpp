#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<vector<int>> pos(n + 1);
    for (int j = 0; j < n; j++){
      pos[b[j]].push_back(j);
    }
    int none_color = -1;
    for (int j = 0; j <= n; j++){
      if (pos[j].empty()){
        none_color = j;
      }
    }
    vector<int> a(n, -1);
    priority_queue<pair<int, int>> pq;
    for (int j = 0; j <= n; j++){
      pq.push(make_pair(pos[j].size(), j));
    }
    for (int j = 0; j < x; j++){
      int cnt = pq.top().first;
      int color = pq.top().second;
      pq.pop();
      int id = pos[color].back();
      a[id] = color;
      pos[color].pop_back();
      pq.push(make_pair(cnt - 1, color));
    }
    y -= x;
    int max_cnt = 0;
    for (int j = 0; j <= n; j++){
      max_cnt = max(max_cnt, (int) pos[j].size());
    }
    if (y > (n - x - max_cnt) * 2){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      vector<int> value;
      for (int j = 0; j < n; j++){
        if (a[j] == -1){
          value.push_back(b[j]);
        }
      }
      sort(value.begin(), value.end());
      int sz = value.size();
      map<int, vector<int>> mp;
      for (int j = 0; j < sz; j++){
        mp[value[j]].push_back(value[(j + sz / 2) % sz]);
      }
      vector<int> pos;
      for (int j = 0; j < n; j++){
        if (a[j] == -1){
          a[j] = mp[b[j]].back();
          mp[b[j]].pop_back();
          pos.push_back(j);
        }
      }
      int cnt = 0;
      for (int j : pos){
        if (a[j] == b[j] && cnt < n - y - x){
          a[j] = none_color;
          cnt++;
        }
      }
      for (int j : pos){
        if (a[j] != none_color && cnt < n - y - x){
          a[j] = none_color;
          cnt++;
        }
      }
      for (int j = 0; j < n; j++){
        cout << a[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}