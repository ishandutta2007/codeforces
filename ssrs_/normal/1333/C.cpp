#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1, 0);
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  long long ans = 0;
  set<long long> s;
  int L = 0;
  int R = 0;
  n++;
  while (1){
    while (R < n){
      if (s.count(S[R])){
        break;
      }
      s.insert(S[R]);
      R++;
      if (R > n){
        R--;
        break;
      }
      if (s.count(S[R])){
        break;
      }
    }
    ans += (R - L - 1);
    s.erase(S[L]);
    L++;
    if (L >= n - 1){
      break;
    }
  }
  cout << ans << endl;
}