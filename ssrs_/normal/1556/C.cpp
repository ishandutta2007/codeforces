#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<long long> s(n + 1);
  s[0] = 0;
  for (int i = 0; i < n; i++){
    if (i % 2 == 0){
      s[i + 1] = s[i] + c[i];
    } else {
      s[i + 1] = s[i] - c[i];
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i += 2){
    long long p = INF;
    for (int j = i + 1; j < n; j += 2){
      long long mn = max(s[i], s[j + 1]);
      long long mx = min({s[i + 1], s[j], p + 1});
      if (mn < mx){
        ans += mx - mn;
      }
      p = min(p, s[j + 1]);
    }
  }
  cout << ans << endl;

}