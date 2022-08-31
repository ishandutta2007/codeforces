#include <bits/stdc++.h>
using namespace std;
string shift(string &s){
  string t;
  for (int i = 1; i < s.size(); i++){
    t += s[i];
  }
  t += s[0];
  return t;
}
int main(){
  cout << fixed << setprecision(10);
  string s;
  cin >> s;
  int L = s.size();
  vector<vector<string>> S(26);
  for (int i = 0; i < L; i++){
    S[s[0] - 'a'].push_back(s);
    s = shift(s);
  }
  long long A = 0;
  for (int i = 0; i < 26; i++){
    int M = 0;
    for (int j = 1; j < L; j++){
      vector<int> c(26, 0);
      for (int k = 0; k < S[i].size(); k++){
        c[S[i][k][j] - 'a']++;
      }
      int count = 0;
      for (int k : c){
        if (k == 1){
          count++;
        }
      }
      M = max(M, count);
    }
    A += M;
  }
  double ans = A;
  cout << ans / L << endl;
}