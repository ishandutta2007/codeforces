#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      p[a[j]] = j;
    }
    int mx = p[0], mn = p[0];
    long long ans = 1;
    for (int j = 1; j < n; j++){
      if (p[j] < mn){
        mn = p[j];
      } else if (p[j] > mx){
        mx = p[j];
      } else {
        ans *= mx - mn - j + 1;
        ans %= MOD;
      }
    }
    cout << ans << endl;
  }
}