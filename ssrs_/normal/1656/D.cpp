#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    int c = __builtin_ctzll(n);
    n >>= c;
    if (n == 1){
      cout << -1 << "\n";
    } else if (n >= ((long long) 1 << c) * 2 + 1){
      cout << ((long long) 1 << (c + 1)) << "\n";
    } else {
      cout << n << endl;
    }
  }
}