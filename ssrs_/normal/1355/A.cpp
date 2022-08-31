#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long a, K;
    cin >> a >> K;
    for (int j = 0; j < K - 1; j++){
      string S = to_string(a);
      int m = 10;
      int M = -1;
      for (char c : S){
        m = min(m, c - '0');
        M = max(M, c - '0');
      }
      if (m == 0){
        break;
      }
      a += M * m;
    }
    cout << a << endl;
  }
}