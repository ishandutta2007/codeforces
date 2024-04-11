#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, S;
  cin >> N >> S;
  if (S >= N * 2){
    cout << "YES" << endl;
    for (int i = 0; i < N; i++){
      if (i < S % N){
        cout << S / N + 1;
      } else {
        cout << S / N;
      }
      if (i < N - 1){
        cout << ' ';
      }
    }
    cout << endl;
    cout << 1 << endl;
  } else {
    cout << "NO" << endl;
  }
}