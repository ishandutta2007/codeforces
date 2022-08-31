#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> S(n + 1);
    S[0] = n;
    for (int j = 0; j < n; j++){
      int p;
      if (s[j] == '+'){
        p = 1;
      }
      if (s[j] ==  '-'){
        p = -1;
      }
      if (j % 2 == 1){
        p *= -1;
      }
      S[j + 1] = S[j] + p;
    }
    vector<vector<int>> pos(n * 2 + 1);
    for (int j = 0; j <= n; j++){
      pos[S[j]].push_back(j);
    }
    for (int j = 0; j < q; j++){
      int l, r;
      cin >> l >> r;
      l--;
      if ((r - l) % 2 == 1){
        cout << 1 << "\n";
        if (S[l] < S[r]){
          int m = (S[l] + S[r] + 1) / 2;
          cout << *lower_bound(pos[m].begin(), pos[m].end(), l) << "\n";
        } else {
          int m = (S[l] + S[r]) / 2;
          cout << *lower_bound(pos[m].begin(), pos[m].end(), l) << "\n";
        }
      } else {
        if (S[l] == S[r]){
          cout << 0 << "\n";
        } else {
          cout << 2 << "\n";
          l++;
          cout << l << ' ';
          if (S[l] < S[r]){
            int m = (S[l] + S[r] + 1) / 2;
            cout << *lower_bound(pos[m].begin(), pos[m].end(), l) << "\n";
          } else {
            int m = (S[l] + S[r]) / 2;
            cout << *lower_bound(pos[m].begin(), pos[m].end(), l) << "\n";
          }
        }
      }
    }
  }
}