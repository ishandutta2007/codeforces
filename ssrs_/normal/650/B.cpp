#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long a, b, T;
  cin >> n >> a >> b >> T;
  string S;
  cin >> S;
  T--;
  if (S[0] == 'w'){
    T -= b;
  }
  if (T < 0){
    cout << 0 << endl;
  } else {
    vector<long long> R(n);
    R[0] = 0;
    for (int i = 0; i < n - 1; i++){
      R[i + 1] = R[i] + a + 1;
      if (S[i + 1] == 'w'){
        R[i + 1] += b;
      }
    }
    vector<long long> L(n);
    L[0] = 0;
    for (int i = 0; i < n - 1; i++){
      L[i + 1] = L[i] + a + 1;
      if (S[n - 1 - i] == 'w'){
        L[i + 1] += b;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
      if (R[i] <= T){
        ans = max(ans, i + 1);
        if (R[i] + a * i <= T){
          int T2 = T - R[i] - a * i;
          int cnt = upper_bound(L.begin(), L.end(), T2) - L.begin();
          ans = max(ans, i + cnt);
        }
      }
    }
    for (int i = 0; i < n; i++){
      if (L[i] <= T){
        ans = max(ans, i + 1);
        if (L[i] + a * i <= T){
          int T2 = T - L[i] - a * i;
          int cnt = upper_bound(R.begin(), R.end(), T2) - R.begin();
          ans = max(ans, i + cnt);
        }
      }
    }
    ans = min(ans, n);
    cout << ans << endl;
  }
}