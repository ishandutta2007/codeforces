#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, A, B;
  cin >> N >> A >> B;
  int a_cnt = -1;
  int b_cnt = -1;
  for (int i = 0; i * A <= N; i++){
    if ((N - i * A) % B == 0){
      a_cnt = i;
      b_cnt = (N - i * A) / B;
    }
  }
  if (a_cnt == -1 && b_cnt == -1){
    cout << -1 << endl;
  } else {
    vector<int> P(N);
    for (int i = 0; i < a_cnt; i++){
      P[i * A] = A * (i + 1);
      for (int j = 1; j < A; j++){
        P[i * A + j] = i * A + j;
      }
    }
    int X = A * a_cnt;
    for (int i = 0; i < b_cnt; i++){
      P[X + i * B] = X + B * (i + 1);
      for (int j = 1; j < B; j++){
        P[X + i * B + j] = X + i * B + j;
      }
    }
    for (int i = 0; i < N; i++){
      cout << P[i];
      if (i < N - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}