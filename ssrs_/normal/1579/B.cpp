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
      cin >> a[j];
    }
    vector<tuple<int, int, int>> ans;
    for (int j = 0; j < n; j++){
      int mn = a[j];
      for (int k = j + 1; k < n; k++){
        mn = min(mn, a[k]);
      }
      int p = -1;
      for (int k = j; k < n; k++){
        if (a[k] == mn){
          p = k;
        }
      }
      if (p > j){
        ans.push_back(make_tuple(j, n, p - j));
        rotate(a.begin() + j, a.begin() + p, a.end());
      }
    }
    int k = ans.size();
    cout << k << endl;
    for (int j = 0; j < k; j++){
      int l = get<0>(ans[j]);
      int r = get<1>(ans[j]);
      int d = get<2>(ans[j]);
      cout << l + 1 << ' ' << r << ' ' << d << endl;
    }
  }
}