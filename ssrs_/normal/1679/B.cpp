#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> T(n, -1);
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  int upd = 0, time = -2;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int p, x;
      cin >> p >> x;
      p--;
      if (time >= T[p]){
        sum -= upd;
      } else {
        sum -= a[p];
      }
      a[p] = x;
      sum += x;
      T[p] = i;
    }
    if (t == 2){
      int x;
      cin >> x;
      upd = x;
      time = i;
      sum = (long long) n * x;
    }
    cout << sum << "\n";
  }
}