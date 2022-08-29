#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, p;
  cin >> n >> p;
  if (p > 0 && n <= p){
    cout << -1 << endl;
  } else {
    int ans = 1;
    while (1){
      long long tmp = n - (long long) p * ans;
      if (tmp >= 0){
        if (__builtin_popcountll(tmp) <= ans && tmp >= ans){
          cout << ans << endl;
          break;
        }
      }
      ans++;
      if (ans > 50){
        cout << -1 << endl;
        break;
      }
    }
  }
}