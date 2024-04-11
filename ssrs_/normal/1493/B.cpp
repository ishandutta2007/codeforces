#include <bits/stdc++.h>
using namespace std;
vector<int> f = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    int h, m;
    cin >> h >> m;
    string s;
    cin >> s;
    int H = stoi(s.substr(0, 2));
    int M = stoi(s.substr(3, 2));
    for (int j = 0; j < h * m; j++){
      string S = to_string(H);
      string T = to_string(M);
      if (S.size() < 2){
        S = "0" + S;
      }
      if (T.size() < 2){
        T = "0" + T;
      }
      int H2 = 0, M2 = 0;
      bool ok = true;
      if (f[S[0] - '0'] == -1){
        ok = false;
      } else {
        M2 += f[S[0] - '0'];
      }
      if (f[S[1] - '0'] == -1){
        ok = false;
      } else {
        M2 += f[S[1] - '0'] * 10;
      }
      if (f[T[0] - '0'] == -1){
        ok = false;
      } else {
        H2 += f[T[0] - '0'];
      }
      if (f[T[1] - '0'] == -1){
        ok = false;
      } else {
        H2 += f[T[1] - '0'] *10;
      }
      if (H2 >= h || M2 >= m){
        ok = false;
      }
      if (ok){
        cout << S << ":" << T << endl;
        break;
      }
      M++;
      if (M == m){
        M = 0;
        H++;
      }
      if (H == h){
        H = 0;
      }
    }
  }
}