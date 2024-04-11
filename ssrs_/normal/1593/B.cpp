#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string n;
    cin >> n;
    int L = n.size();
    vector<string> S = {"00", "25", "50", "75"};
    int cnt = S.size();
    int ans = L;
    for (int j = 0; j < cnt; j++){
      int L2 = S[j].size();
      vector<int> pos(L2);
      pos[L2 - 1] = L;
      for (int k = L2 - 1; k >= 0; k--){
        pos[k]--;
        while (pos[k] >= 0){
          if (n[pos[k]] == S[j][k]){
            break;
          }
          pos[k]--;
        }
        if (k > 0){
          pos[k - 1] = pos[k];
        }
      }
      if (pos[0] >= 0){
        ans = min(ans, (L - L2) - pos[0]);
      }
    }
    cout << ans << endl;
  }
}