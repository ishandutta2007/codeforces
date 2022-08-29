#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> S(n + 1);
    S[0] = 0;
    for (int i = 0; i < n; i++){
      if (s[i] == '+'){
        S[i + 1] = S[i] + 1;
      }
      if (s[i] == '-'){
        S[i + 1] = S[i] - 1;
      }
    }
    vector<int> Lm(n + 1), LM(n + 1);
    Lm[0] = 0;
    LM[0] = 0;
    for (int i = 1; i <= n; i++){
      Lm[i] = min(Lm[i - 1], S[i]);
      LM[i] = max(LM[i - 1], S[i]);
    }
    vector<int> Rm(n + 1), RM(n + 1);
    Rm[n] = S[n];
    RM[n] = S[n];
    for (int i = n - 1; i >= 0; i--){
      Rm[i] = min(Rm[i + 1], S[i]);
      RM[i] = max(RM[i + 1], S[i]);
    }
    for (int j = 0; j < m; j++){
      int l, r;
      cin >> l >> r;
      l--;
      int L = min(Lm[l], Rm[r] - (S[r] - S[l]));
      int R = max(LM[l], RM[r] - (S[r] - S[l]));
      cout << R - L + 1 << endl;
    }
  }
}