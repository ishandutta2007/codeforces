#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] ^ a[i];
  }
  long long ans = 0;
  for (int i = 0; i < 2; i++){
    map<int, int> mp;
    for (int j = i; j <= n; j += 2){
      ans += mp[S[j]];
      mp[S[j]]++;
    }
  }
  cout << ans << endl;
}