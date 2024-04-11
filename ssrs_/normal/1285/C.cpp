#include <bits/stdc++.h>
using namespace std;
int main(){
  long long X;
  cin >> X;
  long long a, b;
  for (long long i = 1; i * i <= X; i++){
    if (X % i == 0){
      if (gcd(i, X / i) == 1){
        a = i;
        b = X / i;
      }
    }
  }
  cout << a << ' ' << b << endl;
}