#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> a[i][j];
    }
  }
  vector<int> c(k);
  for (int i = 0; i < k; i++){
    cin >> c[i];
    c[i]--;
  }
  vector<set<int>> st(m);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (a[i][j] != 2){
        st[j].insert(i);
      }
    }
  }
  for (int i = 0; i < k; i++){
    int x = 0, y = c[i];
    if (!st[y].empty()){
      x = *st[y].begin();
      while (true){
        st[y].erase(x);
        int t = a[x][y];
        a[x][y] = 2;
        if (t == 1){
          y++;
        }
        if (t == 3){
          y--;
        }
        auto itr = st[y].lower_bound(x);
        if (itr == st[y].end()){
          break;
        }
        x = *itr;
      }
    }
    cout << y + 1;
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}