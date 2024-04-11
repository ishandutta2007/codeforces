#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
const int MAX = 200000;
int main(){
  vector<vector<int>> S(LOG, vector<int>(MAX + 2, 0));
  for (int i = 0; i < LOG; i++){
    for (int j = 0; j <= MAX; j++){
      S[i][j + 1] = S[i][j];
      if ((j >> i & 1) == 0){
        S[i][j + 1]++;
      }
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    r++;
    int ans = r - l;
    for (int j = 0; j < LOG; j++){
      ans = min(ans, S[j][r] - S[j][l]);
    }
    cout << ans << endl;
  }
}