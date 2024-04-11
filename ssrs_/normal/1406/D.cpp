#include <bits/stdc++.h>
using namespace std;
long long f(long long x){
  if (x >= 0){
    return x / 2;
  } else {
    return (1 - x) / 2 * (-1);
  }
}
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> d(n - 1);
  for (int i = 0; i < n - 1; i++){
    d[i] = a[i + 1] - a[i];
  }
  long long sum = 0;
  for (int i = 0; i < n - 1; i++){
    if (d[i] > 0){
      sum += d[i];
    }
  }
  cout << f(a[0] + sum + 1) << endl;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    if (l == 0){
      a[0] += x;
    }
    if (l > 0){
      if (d[l - 1] > 0){
        sum -= d[l - 1];
      }
      d[l - 1] += x;
      if (d[l - 1] > 0){
        sum += d[l - 1];
      }
    }
    if (r < n){
      if (d[r - 1] > 0){
        sum -= d[r - 1];
      }
      d[r - 1] -= x;
      if (d[r - 1] > 0){
        sum += d[r - 1];
      }
    }
    cout << f(a[0] + sum + 1) << endl;
  }
}