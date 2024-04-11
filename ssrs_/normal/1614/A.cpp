#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b;
    for (int j = 0; j < n; j++){
      if (l <= a[j] && a[j] <= r){
        b.push_back(a[j]);
      }
    }
    int cnt = b.size();
    sort(b.begin(), b.end());
    int ans = 0;
    for (int j = 0; j < cnt; j++){
      if (k >= b[j]){
        k -= b[j];
        ans++;
      }
    }
    cout << ans << endl;
  }
}