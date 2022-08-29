#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<bool> used(n, false);
    vector<int> b;
    for (int j = 0; j < n; j++){
      if (a[j] >= n){
        b.push_back(a[j]);
      } else if (!used[a[j]]){
        used[a[j]] = true;
      } else {
        b.push_back(a[j]);
      }
    }
    int m = b.size();
    sort(b.begin(), b.end());
    int cnt = 0;
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (!used[j]){
        if (j >= b[cnt] / 2){
          ok = false;
        }
        cnt++;
      }
    }
    if (ok){
      cout << m << endl;
    } else {
      cout << -1 << endl;
    }
  }
}