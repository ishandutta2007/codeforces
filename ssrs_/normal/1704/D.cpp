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
    vector<vector<long long>> c(n, vector<long long>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> c[j][k];
      }
    }
    vector<long long> S(n, 0);
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        S[j] += c[j][k] * k;
      }
    }
    long long X;
    if (S[0] == S[1]){
      X = S[0];
    } else if (S[0] == S[2]){
      X = S[0];
    } else {
      X = S[1];
    }
    for (int j = 0; j < n; j++){
      if (S[j] != X){
        cout << j + 1 << ' ' << S[j] - X << endl;
      }
    }
  }
}