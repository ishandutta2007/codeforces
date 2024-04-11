#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(5));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 5; k++){
        cin >> A[j][k];
      }
    }
    bool ok = false;
    for (int j = 0; j < 5; j++){
      for (int k = j + 1; k < 5; k++){
        vector<vector<int>> cnt(2, vector<int>(2, 0));
        for (int l = 0; l < n; l++){
          cnt[A[l][j]][A[l][k]]++;
        }
        if (cnt[0][0] == 0){
          if (cnt[0][1] <= n / 2 && cnt[1][0] <= n / 2){
            ok = true;
          }
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}