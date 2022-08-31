#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> S0(n + 1), S1(n + 1);
    S0[0] = 0;
    S1[0] = 0;
    for (int j = 0; j < n; j++){
      S0[j + 1] = S0[j];
      S1[j + 1] = S1[j];
      if (s[j] == '[' || s[j] == ']'){
        if (j % 2 == 0){
          S0[j + 1]++;
        }
        if (j % 2 == 1){
          S1[j + 1]++;
        }
      }
    }
    int q;
    cin >> q;
    for (int j = 0; j < q; j++){
      int l, r;
      cin >> l >> r;
      l--;
      cout << abs((S0[r] - S0[l]) - (S1[r] - S1[l])) << "\n";
    }
  }
}