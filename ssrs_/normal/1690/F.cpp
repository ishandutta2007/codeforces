#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    long long ans = 1;
    vector<bool> used(n, false);
    for (int j = 0; j < n; j++){
      if (!used[j]){
        int v = j;
        string t;
        while (true){
          t += s[v];
          v = p[v];
          if (v == j){
            break;
          }
        }
        int L = t.size();
        int c = L;
        for (int k = 1; k < L; k++){
          if (L % k == 0){
            bool ok = true;
            for (int l = 0; l < L - k; l++){
              if (t[l] != t[l + k]){
                ok = false;
                break;
              }
            }
            if (ok){
              c = k;
              break;
            }
          }
        }
        ans = lcm(ans, c);
      }
    }
    cout << ans << endl;
  }
}