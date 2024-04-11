#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int l = s.size();
    int U = 0, D = n, L = 0, R = m;
    int cntU = 0, cntL = 0;
    bool ok = false;
    for (int j = 0; j < l; j++){
      bool u = false, l = false;
      if (s[j] == 'U'){
        U--;
        D--;
        if (U < 0){
          u = true;
        }
        U = max(U, 0);
      }
      if (s[j] == 'D'){
        U++;
        D++;
        D = min(D, n);
      }
      if (s[j] == 'L'){
        L--;
        R--;
        if (L < 0){
          l = true;
        }
        L = max(L, 0);
      }
      if (s[j] == 'R'){
        L++;
        R++;
        R = min(R, m);
      }
      if (U == D || L == R){
        cout << cntU + 1 << ' ' << cntL + 1 << "\n";
        ok = true;
        break;
      }
      if (u){
        cntU++;
      }
      if (l){
        cntL++;
      }
    }
    if (!ok){
      cout << cntU + 1 << ' ' << cntL + 1 << "\n";
    }
  }
}