#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    vector<int> S(N + 1);
    S[0] = 0;
    for (int j = 0; j < N; j++){
      S[j + 1] = S[j];
      if (s[j] == '0'){
        S[j + 1]++;
      }
    }
    vector<int> one;
    for (int j = 0; j < N; j++){
      if (s[j] == '1'){
        one.push_back(j);
      }
    }
    int cnt = one.size();
    int tv = cnt, fv = -1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      bool ok = false;
      for (int j = 0; j <= mid; j++){
        int L = one[j];
        int R = one[cnt - 1 - mid + j] + 1;
        if (S[R] - S[L] <= mid){
          ok = true;
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}