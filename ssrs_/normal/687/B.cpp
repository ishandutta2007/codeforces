#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<long long> f;
  for (int i = 2; i * i <= k; i++){
    if (k % i == 0){
      f.push_back(1);
      while (k % i == 0){
        f.back() *= i;
        k /= i;
      }
    }
  }
  if (k != 1){
    f.push_back(k);
  }
  bool ok = true;
  for (long long x : f){
    bool ok2 = false;
    for (int i = 0; i < n; i++){
      if (c[i] % x == 0){
        ok2 = true;
      }
    }
    if (!ok2){
      ok = false;
    }
  }
  if (ok){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}