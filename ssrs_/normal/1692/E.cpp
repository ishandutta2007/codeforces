#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> p;
    p.push_back(-1);
    for (int j = 0; j < n; j++){
      if (a[j] == 1){
        p.push_back(j);
      }
    }
    p.push_back(n);
    int cnt = p.size() - 2;
    if (cnt < s){
      cout << -1 << endl;
    } else {
      int cnt = p.size();
      int ans = n;
      for (int j = 0; j < cnt - s - 1; j++){
        ans = min(ans, n - (p[j + s + 1] - p[j]) + 1);
      }
      cout << ans << endl;
    }
  }
}