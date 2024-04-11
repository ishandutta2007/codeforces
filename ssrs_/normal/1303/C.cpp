#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    string s;
    cin >> s;
    if (s.size() == 1){
      cout << "YES" << endl;
      cout << "abcdefghijklmnopqrstuvwxyz" << endl;
      continue;
    }
    vector<set<char>> A(26); 
    for (int j = 0; j < s.size(); j++){
      if (j == 0){
        A[s[0] - 'a'].insert(s[1]);
      } else if (j == s.size() - 1){
        A[s[s.size() - 1] - 'a'].insert(s[s.size() - 2]);
      } else {
        A[s[j] - 'a'].insert(s[j - 1]);
        A[s[j] - 'a'].insert(s[j + 1]);
      }
    }
    bool flg = false;
    for (int j = 0; j < 26; j++){
      if (A[j].size() > 2){
        flg = true;
      }
    }
    if (flg){
      cout << "NO" << endl;
      continue;
    }
    string K;
    vector<bool> C(26,false);
    flg = false;
    for (int j = 0; j < 26; j++){
      if (A[j].size() == 1){
        K += (char)('a' + j);
        C[j] = true;
        flg = true;
        break;
      }
    }
    if (!flg){
      cout << "NO" << endl;
      continue;
    }
    char x = *A[K[K.size() - 1] - 'a'].begin();
    while (A[x - 'a'].size() == 2){
      K += x;
      C[x - 'a'] = true;
      char y = x;
      auto itr = A[y - 'a'].begin();
      if (C[*itr - 'a']) itr++;
      x = *itr;
    }
    K += x;
    C[x - 'a'] = true;
    for (int j = 0; j < 26; j++){
      if (!C[j]){
        K += (char)('a' + j);
      }
    }
    cout << "YES" << endl;
    cout << K << endl;
  }
}