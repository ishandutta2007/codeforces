#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    while (true){
      long long n2 = n;
      int sum = 0;
      while (n2 > 0){
        sum += n2 % 10;
        n2 /= 10;
      }
      if (gcd(n, sum) > 1){
        cout << n << endl;
        break;
      }
      n++;
    }
  }
}