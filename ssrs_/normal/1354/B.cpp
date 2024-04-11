#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<vector<int>> nxt(N + 1, vector<int>(3, N));
    for (int j = N - 1; j >= 0; j--){
      nxt[j] = nxt[j + 1];
      nxt[j][s[j] - '1'] = j;
    }
    int ans = INF;
    for (int j = 0; j < N; j++){
      int tmp = max({nxt[j][0], nxt[j][1], nxt[j][2]});
      if (tmp != N){
        ans = min(ans, tmp - j + 1);
      }
    }
    if (ans == INF){
      cout << 0 << endl;
    } else {
      cout << ans << endl;
    }
  }
}