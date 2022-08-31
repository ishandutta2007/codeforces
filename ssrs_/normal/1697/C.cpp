#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    cin >> t;
    vector<int> S(n + 1), T(n + 1);
    S[0] = 0;
    T[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j];
      if (s[j] == 'b'){
        S[j + 1]++;
      }
      T[j + 1] = T[j];
      if (t[j] == 'b'){
        T[j + 1]++;
      }
    }
    string s2, t2;
    for (int j = 0; j < n; j++){
      if (s[j] != 'b'){
        s2 += s[j];
      }
      if (t[j] != 'b'){
        t2 += t[j];
      }
    }
    vector<int> sa, sc, ta, tc;
    for (int j = 0; j < n; j++){
      if (s[j] == 'a'){
        sa.push_back(j);
      }
      if (s[j] == 'c'){
        sc.push_back(j);
      }
      if (t[j] == 'a'){
        ta.push_back(j);
      }
      if (t[j] == 'c'){
        tc.push_back(j);
      }
    }
    if (S[n] != T[n] || s2 != t2){
      cout << "NO" << endl;
    } else {
      int cntA = sa.size();
      int cntC = sc.size();
      bool ok = true;
      for (int j = 0; j < cntA; j++){
        if (S[sa[j]] > T[ta[j]]){
          ok = false;
        }
      }
      for (int j = 0; j < cntC; j++){
        if (S[sc[j]] < T[tc[j]]){
          ok = false;
        }
      }
      if (ok){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}