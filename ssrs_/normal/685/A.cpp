#include <bits/stdc++.h>
using namespace std;
int base_7_digit(int n){
  if (n < 7){
    return 1;
  } else {
    return base_7_digit(n / 7) + 1;
  }
}
int pow7(int n){
  if (n == 0){
    return 1;
  } else {
    return pow7(n - 1) * 7;
  }
}
int to_dec(string S){
  int N = S.size();
  int ans = 0;
  for (int i = 0; i < N; i++){
    ans *= 7;
    ans += S[i] - '0';
  }
  return ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  int d1 = base_7_digit(n - 1);
  int d2 = base_7_digit(m - 1);
  if (d1 + d2 > 7){
    cout << 0 << endl;
  } else {
    int d = d1 + d2;
    int t = pow7(d);
    int ans = 0;
    for (int i = 0; i < t; i++){
      int tmp = i;
      string S;
      for (int j = 0; j < d; j++){
        S += tmp % 7 + '0';
        tmp /= 7;
      }
      vector<bool> used(7);
      bool ok = true;
      for (int j = 0; j < d; j++){
        if (used[S[j] - '0']){
          ok = false;
        }
        used[S[j] - '0'] = true;
      }
      if (ok){
        string S1 = S.substr(0, d1);
        string S2 = S.substr(d1);
        int a = to_dec(S1);
        int b = to_dec(S2);
        if (a < n && b < m){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}