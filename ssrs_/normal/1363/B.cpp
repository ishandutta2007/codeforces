#include <bits/stdc++.h>
using namespace std;
int INF = 100000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> L0(N + 1, 0);
    for (int j = 0; j < N; j++){
      if (s[j] == '0'){
        L0[j + 1] = L0[j] + 1;
      } else {
        L0[j + 1] = L0[j];
      }
    }
    vector<int> R0(N + 1, 0);
    for (int j = N - 1; j >= 0; j--){
      if (s[j] == '0'){
        R0[j] = R0[j + 1] + 1;
      } else {
        R0[j] = R0[j + 1];
      }
    }
    vector<int> L1(N + 1, 0);
    for (int j = 0; j < N; j++){
      if (s[j] == '1'){
        L1[j + 1] = L1[j] + 1;
      } else {
        L1[j + 1] = L1[j];
      }
    }
    vector<int> R1(N + 1, 0);
    for (int j = N - 1; j >= 0; j--){
      if (s[j] == '1'){
        R1[j] = R1[j + 1] + 1;
      } else {
        R1[j] = R1[j + 1];
      }
    }
    int ans = INF;
    for (int i = 0; i < N; i++){
      ans = min(ans, L0[i] + R1[i]);
      ans = min(ans, L1[i] + R0[i]);
    }
    cout << ans << endl;
  }
}