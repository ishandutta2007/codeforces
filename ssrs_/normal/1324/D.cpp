#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    c[i] = a[i] - b[i];
  }
  sort(c.begin(), c.end());
  long long ans = 0;
  for (int i = 0; i < n - 1; i++){
    if (c[i] > 0){
      ans += n - i - 1;
      continue;
    }
    if (c[i] + c[n - 1] < 0){
      continue;
    }
    int t = 1 - c[i];
    //c[j] >= t, j > i
    int tv = n;
    int fv = i;
    while (tv - fv > 1){
      int m = (tv + fv) / 2;
      if (c[m] >= t){
        tv = m;
      } else {
        fv = m;
      }
    }
    ans += n - tv;
  }
  cout << ans;
}