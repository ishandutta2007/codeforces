#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long k;
  cin >> k;
  int a = 0, b = 0;
  long long x = 0;
  vector<vector<int>> I(1000001);
  for (int i = 1; i <= 2001; i++){
    int st = (k + 1) % i;
    if (st != 0){
      st = i - st;
    }
    for (int j = st + 1; j <= 1000000; j += i){
      I[j].push_back(i);
    }
  }
  for (int j = 1; j <= 1000000; j++){
    int s = k + j;
    for (int i : I[j]){
      if (s % i == 0){
        x = (k + (i + 1) * j) / i;
        if (x <= 1000000){
          a = i - 1;
          b = j;
          break;
        }
      }
    }
    if (b != 0){
      break;
    }
  }
  if (a == 0 && b == 0 && x == 0){
    cout << -1 << endl;
  } else {
    vector<int> ans(a + 2, 0);
    ans[a] = -b;
    ans[a + 1] = x;
    cout << a + 2 << endl;
    for (int i = 0; i < a + 2; i++){
      cout << ans[i];
      if (i < a + 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}