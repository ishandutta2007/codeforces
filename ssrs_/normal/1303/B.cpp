#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    long long n,g,b;
    cin >> n >> g >> b;
    long long N = (n + 1) / 2;
    long long A;
    if (N % g == 0){
      A = (N / g - 1) * (g + b) + g;
    } else {
      A = (N / g) * (g + b) + N % g;
    }
    cout << max(A,n) << endl;
  }
}