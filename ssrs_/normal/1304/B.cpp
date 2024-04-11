#include <bits/stdc++.h>
using namespace std;
string rev(string S){
  string res;
  for (int i = S.size() - 1; i >= 0; i--){
    res += S[i];
  }
  return res;
}
int main(){
  int n,m;
  cin >> n >> m;
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  vector<bool> C(n,false);
  vector<int> p(n,-1);
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      if (C[j]){
        continue;
      }
      if (S[i] == rev(S[j])){
        C[i] = true;
        C[j] = true;
        p[i] = j;
        break;
      }
    }
  }
  string s;
  for (int i = 0; i < n; i++){
    if (S[i] == rev(S[i])){
      s = S[i];
      break;
    }
  }
  for (int i = 0; i < n; i++){
    if (p[i] != -1){
      s = S[i] + s + S[p[i]];
    }
  }
  cout << s.size() << endl;
  cout << s;
}