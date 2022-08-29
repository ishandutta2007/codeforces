#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int N, K;
    cin >> N >> K;
    int f;
    if (K % N == 0){
      f = 0;
    } else {
      f = 2;
    }
    cout << f << endl;
    vector<vector<int>> A(N, vector<int>(N, 0));
    int cnt = 0;
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        if (cnt < K){
          A[k][(j + k) % N] = 1;
          cnt++;
        }
      }
    }
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        cout << A[j][k];
      }
      cout << endl;
    }
  }
}