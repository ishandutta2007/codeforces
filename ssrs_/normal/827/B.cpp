#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  int t = 10000000;
  int f = 0;
  while (t - f > 1){
    long long m = (t + f) / 2;
    long long cnt = 0;
    if (m % 2 == 0){
      cnt = (m / 2) * k + 1;
    } else {
      cnt = (m / 2) * (k - 1) + (m / 2 + 1) + 1;
    }
    if (cnt >= n){
      t = m;
    } else {
      f = m;
    }
  }
  cout << t << endl;
  int cnt = 0;
  for (int i = 0; i < k; i++){
    cout << 1 << ' ' << i + 2 << endl;
    cnt++;
  }
  while (cnt < n - 1){
    cout << cnt + 2 - k << ' ' << cnt + 2 << endl;
    cnt++;
  }
}