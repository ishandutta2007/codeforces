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
    S[0] = 0;
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
    for (int i = 0; i < q; i++){
      int l, r;
      cin >> l >> r;
      l--;
      if ((r - l) % 2 == 1){
        cout << 1 << endl;
      } else {
        if (S[l] == S[r]){
          cout << 0 << endl;
        } else {
          cout << 2 << endl;
        }
      }
    }
  }
}