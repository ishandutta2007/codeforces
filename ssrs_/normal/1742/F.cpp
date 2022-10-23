#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int q;
    cin >> q;
    vector<vector<long long>> cnt(2, vector<long long>(26, 0));
    cnt[0][0] = 1;
    cnt[1][0] = 1;
    for (int j = 0; j < q; j++){
      int d, k;
      string x;
      cin >> d >> k >> x;
      d--;
      int L = x.size();
      for (int l = 0; l < L; l++){
        cnt[d][x[l] - 'a'] += k;
      }
      bool ok = false;
      for (int l = 1; l < 26; l++){
        if (cnt[1][l] > 0){
          ok = true;
        }
      }
      if (ok){
        cout << "YES" << "\n";
      } else {
        ok = true;
        for (int l = 1; l < 26; l++){
          if (cnt[0][l] > 0){
            ok = false;
          }
        }
        if (cnt[0][0] >= cnt[1][0]){
          ok = false;
        }
        if (ok){
          cout << "YES" << "\n";
        } else {
          cout << "NO" << "\n";
        }
      }
    }
  }
}