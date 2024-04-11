#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> c(n, vector<char>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      cin >> c[i][j];
    }
  }
  vector<int> p;
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < m - 1; j++){
      if (c[i + 1][j] == 'X' && c[i][j + 1] == 'X'){
        p.push_back(j);
      }
    }
  }
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int x1, x2;
    cin >> x1 >> x2;
    x1--;
    auto itr1 = lower_bound(p.begin(), p.end(), x1);
    auto itr2 = lower_bound(p.begin(), p.end(), x2 - 1);
    if (itr1 == itr2){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}