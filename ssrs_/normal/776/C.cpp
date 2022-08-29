#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  map<long long, int> mp;
  long long ans = 0;
  for (int i = 0; i <= n; i++){
    long long p = 1;
    while (true){
      if (mp.count(S[i] - p)){
        ans += mp[S[i] - p];
      }
      p *= k;
      if (p == 1){
        break;
      }
      if (abs(p) > 1000000000000000){
        break;
      }
    }
    mp[S[i]]++;
  }
  cout << ans << endl;
}