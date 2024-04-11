#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  int odd = 0;
  for (int i = 0; i < n; i++){
    if (a[i] % 2 == 1){
      odd++;
    }
  }
  if (odd >= 2){
    cout << 0 << endl;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < a[i]; j++){
        cout << (char) ('a' + i);
      }
    }
    cout << endl;
  } else if (odd == 1){
    if (n == 1){
      cout << a[0] << endl;
      for (int i = 0; i < a[0]; i++){
        cout << 'a';
      }
      cout << endl;
    } else {
      int ans = 0;
      for (int i = 0; i < n; i++){
        ans = gcd(ans, a[i]);
      }
      cout << ans << endl;
      int odd_id;
      for (int i = 0; i < n; i++){
        if (a[i] % 2 == 1){
          odd_id = i;
        }
      }
      a[odd_id] -= ans;
      string S;
      for (int i = 0; i < n; i++){
        for (int j = 0; j < a[i] / (ans * 2); j++){
          S += 'a' + i;
        }
      }
      for (int i = 0; i < ans * 2; i++){
        cout << S;
        reverse(S.begin(), S.end());
        if (i % 2 == 1){
          cout << (char) ('a' + odd_id);
        }
      }
      cout << endl;
    }
  } else {
    int ans = 0;
    for (int i = 0; i < n; i++){
      ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
    string S;
    for (int i = 0; i < n; i++){
      for (int j = 0; j < a[i] / ans; j++){
        S += 'a' + i;
      }
    }
    for (int i = 0; i < ans; i++){
      cout << S;
      reverse(S.begin(), S.end());
    }
    cout << endl;
  }
}