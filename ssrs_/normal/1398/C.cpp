#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      char c;
      cin >> c;
      a[j] = c - '0';
    }
    for (int j = 0; j < n; j++){
      a[j]--;
    }
    vector<int> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    map<int, int> mp;
    long long ans = 0;
    for (int j = 0; j <= n; j++){
      ans += mp[S[j]];
      mp[S[j]]++;
    }
    cout << ans << endl;
  }
}