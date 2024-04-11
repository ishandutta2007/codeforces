#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long x;
  cin >> n >> x;
  long long T = 1;
  for (int i = 0; i < n - 1; i++){
    T *= 10;
  }
  int ans = 0;
  vector<long long> X = {x};
  while (true){
    vector<long long> X2;
    int cnt = X.size();
    for (int i = 0; i < cnt; i++){
      long long a = X[i];
      int s = 0;
      int mx = 0;
      while (a > 0){
        s |= 1 << (a % 10);
        a /= 10;
      }
      for (int j = 2; j <= 9; j++){
        if ((s >> j & 1) == 1){
          X2.push_back(X[i] * j);
        }
      }
    }
    if (X2.empty()){
      ans = -1;
      break;
    }
    sort(X2.begin(), X2.end(), greater<long long>());
    X2.erase(unique(X2.begin(), X2.end()), X2.end());
    ans++;
    if (X2[0] >= T){
      break;
    }
    swap(X, X2);
  }
  cout << ans << endl;
}