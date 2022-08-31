#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    if (s[0] != t[0] || s[n - 1] != t[n - 1]){
      cout << -1 << endl;
    } else {
      vector<int> a;
      for (int j = 0; j < n - 1; j++){
        if (s[j] != s[j + 1]){
          a.push_back(j);
        }
      }
      vector<int> b;
      for (int j = 0; j < n - 1; j++){
        if (t[j] != t[j + 1]){
          b.push_back(j);
        }
      }
      if (a.size() != b.size()){
        cout << -1 << endl;
      } else {
        int m = a.size();
        long long ans = 0;
        for (int j = 0; j < m; j++){
          ans += abs(a[j] - b[j]);
        }
        cout << ans << endl;
      }
    }
  }
}