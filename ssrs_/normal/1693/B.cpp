#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    p[0] = -1;
    for (int j = 1; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<int> l(n), r(n);
    for (int j = 0; j < n; j++){
      cin >> l[j] >> r[j];
    }
    vector<vector<int>> c(n);
    for (int j = 1; j < n; j++){
      c[p[j]].push_back(j);
    }
    int ans = 0;
    for (int j = n - 1; j >= 0; j--){
      long long sum = 0;
      for (int k : c[j]){
        sum += r[k];
      }
      if (sum < l[j]){
        ans++;
      } else {
        r[j] = min((long long) r[j], sum);
      }
    }
    cout << ans << endl;
  }
}