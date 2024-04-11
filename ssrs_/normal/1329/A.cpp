#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> l(m);
  for (int i = 0; i < m; i++){
    cin >> l[i];
  }
  long long sum = 0;
  for (int i = 0; i < m; i++){
    sum += l[i];
  }
  if (sum < n){
    cout << -1 << endl;
  } else {
    bool flg = false;
    for (int i = 0; i < m; i++){
      if (l[i] >= n - i + 1){
        flg = true;
      }
    }
    if (flg){
      cout << -1 << endl;
    } else {
      vector<long long> rp(m);
      rp[m - 1] = n - l[m - 1];
      for (int i = m - 2; i >= 0; i--){
        rp[i] = rp[i + 1] - l[i];
      }
      for (int i = 0; i < m; i++){
        cout << max((long long)i, rp[i]) + 1;
        if (i < m - 1){
          cout << ' ';
        }
        cout << endl;
      }
    }
  }
}