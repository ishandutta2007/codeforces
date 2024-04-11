#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], i);
  }
  sort(P.rbegin(), P.rend());
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    b[i] = P[i].first;
  }
  vector<vector<int>> ans(n + 1, vector<int>(n, 0));
  for (int i = 0; i < n; i++){
    ans[n - 1 - i][i] = 1;
    b[i]--;
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= n; j++){
      if (j != n - 1 - i && j != n - i){
        if (b[i] > 0){
          ans[j][i] = 1;
          b[i]--;
        }
      }
    }
  }
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    p[P[i].second] = i;
  }
  cout << n + 1 << endl;
  for (int i = 0; i <= n; i++){
    for (int j = 0; j < n; j++){
      cout << ans[i][p[j]];
    }
    cout << endl;
  }
}