#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<queue<int>> Q1(300000);
  queue<pair<int, int>> Q2;
  int cnt = 0;
  int ans = 0;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x;
      cin >> x;
      x--;
      Q1[x].push(cnt);
      Q2.push(make_pair(x, cnt));
      cnt++;
      ans++;
    }
    if (t == 2){
      int x;
      cin >> x;
      x--;
      ans -= Q1[x].size();
      while (!Q1[x].empty()){
        Q1[x].pop();
      }
    }
    if (t == 3){
      int t;
      cin >> t;
      t--;
      while (!Q2.empty()){
        if (Q2.front().second <= t){
          int x = Q2.front().first;
          int y = Q2.front().second;
          Q2.pop();
          if (!Q1[x].empty()){
            if (Q1[x].front() == y){
              Q1[x].pop();
              ans--;
            }
          }
        } else {
          break;
        }
      }
    }
    cout << ans << "\n";
  }
}