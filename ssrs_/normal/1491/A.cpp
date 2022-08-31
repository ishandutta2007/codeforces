#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++){
    if (a[i] == 1){
      cnt++;
    }
  }
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x;
      cin >> x;
      x--;
      if (a[x] == 1){
        cnt--;
      }
      a[x] = 1 - a[x];
      if (a[x] == 1){
        cnt++;
      }
    }
    if (t == 2){
      int k;
      cin >> k;
      if (cnt < k){
        cout << 0 << "\n";
      } else {
        cout << 1 << "\n";
      }
    }
  }
}