#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> r(26, -1);
    for (int j = 0; j < n; j++){
      int p = s[j] - 'a';
      if (r[p] == -1){
        int q = max(0, p - k);
        int m = p;
        int mx = p;
        for (int l = p; l >= q; l--){
          if (r[l] != -1){
            if (r[l] < m){
              m = r[l];
              mx = l;
            }
          }
          if (l < m){
            m = l;
            mx = l;
          }
        }
        for (int l = p; l >= mx; l--){
          r[l] = m;
        }
        k -= p - mx;
      }
    }
    for (int j = 0; j < 26; j++){
      if (r[j] == -1){
        r[j] = j;
      }
    }
    for (int j = 0; j < n; j++){
      char c = 'a' + r[s[j] - 'a'];
      cout << c;
    }
    cout << endl;
  }
}