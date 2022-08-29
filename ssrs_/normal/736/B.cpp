#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  bool prime = true;
  for (int i = 2; (long long) i * i <= n; i++){
    if (n % i == 0){
      prime = false;
    }
  }
  if (prime){
    cout << 1 << endl;
  } else if (n % 2 == 0){
    cout << 2 << endl;
  } else {
    n -= 2;
    bool prime2 = true;
    for (int i = 2; (long long) i * i <= n; i++){
      if (n % i == 0){
        prime2 = false;
      }
    }
    if (prime2){
      cout << 2 << endl;
    } else {
      cout << 3 << endl;
    }
  }
}