#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    int r;
    for (int j = 0; j < n; j++){
      if (b[j] == j){
        r = j;
      }
    }
    vector<int> q(n);
    for (int j = 0; j < n; j++){
      q[p[j]] = j;
    }
    vector<int> w(n);
    w[r] = 0;
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (j != r){
        if (q[b[j]] > q[j]){
          ok = false;
        } else {
          w[j] = q[j] - q[b[j]];
        }
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      for (int j = 0; j < n; j++){
        cout << w[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}