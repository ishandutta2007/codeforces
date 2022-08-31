#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int N = s.size();
  vector<int> A(N + 11);
  A[0] = -1;
  vector<int> B(N + 11);
  B[0] = -1;
  for (int i = 0; i < N; i++){
    int p = B[i];
    while (p >= 0 & s[i] != s[p]){
      p = A[p];
    }
    p++;
    if (s[i + 1] == s[p]){
      A[i + 1] = A[p];
    } else {
      A[i + 1] = p;
    }
    B[i + 1] = p;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string t;
    cin >> t;
    int M = t.size();
    s += t;
    for (int j = N; j < N + M; j++){
      int p = B[j];
      while (p >= 0 && s[j] != s[p]){
        p = A[p];
      }
      p++;
      if (s[j + 1] == s[p]){
        A[j + 1] = A[p];
      } else {
        A[j + 1] = p;
      }
      B[j + 1] = p;
    }
    for (int j = N; j < N + M; j++){
      cout << B[j + 1];
      if (j < N + M - 1){
        cout << ' ';
      }
    }
    cout << "\n";
    for (int j = 0; j < M; j++){
      s.pop_back();
    }
  }
}