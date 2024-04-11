#include <bits/stdc++.h>
using namespace std;
struct unionfind{
  vector<int> p;
  unionfind(int N): p(N, -1){
  }
  int root(int x){
    if (p[x] == -1){
      return x;
    } else {
      p[x] = root(p[x]);
      return p[x];
    }
  }
  bool same(int x, int y){
    return root(x) == root(y);
  }
  void unite(int x, int y){
    x = root(x);
    y = root(y);
    p[x] = y;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  vector<vector<int>> pos(500000);
  int cnt = 0;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x;
      cin >> x;
      x--;
      pos[x].push_back(cnt);
      cnt++;
    }
    if (t == 2){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      if (x != y){
        if (pos[x].size() > pos[y].size()){
          swap(pos[x], pos[y]);
        }
        for (int a : pos[x]){
          pos[y].push_back(a);
        }
        pos[x].clear();
      }
    }
  }
  vector<int> ans(cnt);
  for (int i = 0; i < 500000; i++){
    for (int x : pos[i]){
      ans[x] = i;
    }
  }
  for (int i = 0; i < cnt; i++){
    cout << ans[i] + 1;
    if (i < cnt - 1){
      cout << ' ';
    }
  }
  cout << endl;
}