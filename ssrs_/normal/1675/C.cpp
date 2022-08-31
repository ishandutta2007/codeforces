#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> L(N + 1, 0);
    for (int j = 0; j < N; j++){
      L[j + 1] = L[j];
      if (s[j] == '0'){
        L[j + 1]++;
      }
    }
    vector<int> R(N + 1, 0);
    for (int j = N - 1; j >= 0; j--){
      R[j] = R[j + 1];
      if (s[j] == '1'){
        R[j]++;
      }
    }
    int ans = 0;
    for (int j = 0; j < N; j++){
      if (L[j] == 0 && R[j + 1] == 0){
        ans++;
      }
    }
    cout << ans << endl;
  }
}