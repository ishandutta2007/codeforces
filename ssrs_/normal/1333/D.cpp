#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string S;
  cin >> S;
  vector<vector<int>> T;
  while (1){
    vector<int> C;
    for (int i = 0; i < n - 1; i++){
      if (S[i] == 'R' && S[i + 1] == 'L'){
        C.push_back(i);
      }
    }
    if (C.empty()){
      break;
    }
    T.push_back(C);
    for (int i : C){
      S[i] = 'L';
      S[i + 1] = 'R';
    }
  }
  int m = T.size();
  int M = 0;
  for (int i = 0; i < m; i++){
    M += T[i].size();
  }
  if (k < m || M < k){
    cout << -1 << "\n";
  } else {
    int d = k - m;
    for (int i = 0; i < m; i++){
      if (d == 0){
        cout << T[i].size();
        for (int j : T[i]){
          cout << ' ' << j + 1;
        }
        cout << endl;
      } else if (d >= T[i].size()){
        for (int j : T[i]){
          cout << 1 << ' ' << j + 1 << "\n";
        }
        d -= T[i].size() - 1;
      } else {
        for (int j = 0; j < d; j++){
          cout << 1 << ' ' << T[i][j] + 1 << "\n";
        }
        cout << T[i].size() - d;
        for (int j = d; j < T[i].size(); j++){
          cout << ' ' << T[i][j] + 1;
        }
        cout << "\n";
        d = 0;
      }
    }
  }
}