#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int n;
    cin >> n;
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      cin >> p[j];
      p[j]--;
    }
    vector<int> c(n);
    for (int j = 0; j < n; j++){
      cin >> c[j];
    }
    vector<bool> used(n, false); //used flag
    vector<vector<int>> cycle;
    for (int j = 0; j < n; j++){
      if (used[j]) continue;
      used[j] = true;
      vector<int> C;
      C.push_back(j);
      while (C[0] != p[C.back()]){
        C.push_back(p[C.back()]);
        used[C.back()] = true;
      }
      C.push_back(j);
      cycle.push_back(C);
    }
    /*
    for (int j = 0; j < cycle.size(); j++){
      for (int k = 0; k < cycle[j].size(); k++){
        cout << cycle[j][k] << ' ';
      }
      cout << endl;
    }
    */
    int M = INF;
    for (int j = 0; j < cycle.size(); j++){
      vector<int> fl; //factor list
      int length = cycle[j].size() - 1;
      for (int k = 1; k * k <= length; k++){
        if (length % k == 0){
          fl.push_back(k);
          if (k * k < length){
            fl.push_back(length / k);
          }
        }
      }
      for (int k = 0; k < fl.size(); k++){
        int cc = fl[k]; //trying cycle
        for (int s = 0; s < cc; s++){
          //cout << "cc=" << cc << ", s=" << s << endl;
          bool flg = true; //success flag
          int color = c[cycle[j][s]];
          for (int pos = s; pos < length; pos += cc){
            if (c[cycle[j][pos]] != color){
              flg = false;
              break;
            }
          }
          if (flg){
            M = min(M, cc);
          }
        }
      }
    }
    cout << M << endl;
  }
}