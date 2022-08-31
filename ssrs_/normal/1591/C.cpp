#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    vector<int> a, b;
    for (int j = 0; j < n; j++){
      if (x[j] < 0){
        a.push_back(-x[j]);
      }
      if (x[j] > 0){
        b.push_back(x[j]);
      }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int cnta = a.size();
    int cntb = b.size();
    long long ans = 0;
    for (int j = cnta - 1; j >= 0; j -= k){
      ans += a[j] * 2;
    }
    for (int j = cntb - 1; j >= 0; j -= k){
      ans += b[j] * 2;
    }
    int mx = 0;
    if (cnta > 0){
      mx = max(mx, a[cnta - 1]);
    }
    if (cntb > 0){
      mx = max(mx, b[cntb - 1]);
    }
    ans -= mx;
    cout << ans << endl;
  }
}