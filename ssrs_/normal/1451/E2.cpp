#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> X(n, 0);
  for (int i = 1; i < n; i++){
    cout << "XOR " << 1 << " " << i + 1 << endl;
    cin >> X[i];
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    if (mp.count(X[i])){
      int A;
      cout << "AND " << mp[X[i]] + 1 << " " << i + 1 << endl;
      cin >> A;
      vector<int> ans(n);
      ans[i] = A;
      for (int j = 0; j < n; j++){
        if (j != i){
          ans[j] = A ^ X[i] ^ X[j];
        }
      }
      cout << "!";
      for (int j = 0; j < n; j++){
        cout << ' ' << ans[j];
      }
      cout << endl;
      return 0;
    }
    mp[X[i]] = i;
  }
  int f;
  for (int i = 1; i < n - 1; i++){
    if (mp.count(i) && mp.count(n - 1 - i)){
      int A;
      cout << "AND " << 1 << ' ' << mp[i] + 1 << endl;
      cin >> A;
      int B;
      cout << "AND " << 1 << ' ' << mp[n - 1 - i] + 1 << endl;
      cin >> B;
      f = 0;
      for (int j = 0; (1 << j) < n; j++){
        if (i >> j & 1){
          if (B >> j & 1){
            f += 1 << j;
          }
        } else {
          if (A >> j & 1){
            f += 1 << j;
          }
        }
      }
      break;
    }
  }
  vector<int> ans(n);
  ans[0] = f;
  for (int i = 1; i < n; i++){
    ans[i] = f ^ X[i];
  }
  cout << "!";
  for (int i = 0; i < n; i++){
    cout << ' ' << ans[i];
  }
  cout << endl;
}