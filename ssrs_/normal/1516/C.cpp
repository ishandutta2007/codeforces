#include <bits/stdc++.h>
using namespace std;
const int INF = 20;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  if (sum % 2 == 1){
    cout << 0 << endl;
  } else {
    bitset<200001> dp;
    dp.set(0);
    for (int i = 0; i < n; i++){
      dp |= dp << a[i];
    }
    if (!dp[sum / 2]){
      cout << 0 << endl;
    } else {
      int mn = INF;
      int p = 0;
      for (int i = 0; i < n; i++){
        if (__builtin_ctz(a[i]) < mn){
          mn = __builtin_ctz(a[i]);
          p = i;
        }
      }
      cout << 1 << endl;
      cout << p + 1 << endl;
    }
  }
}