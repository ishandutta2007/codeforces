#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    if (n % 2 == 1){
      cout << "Bob" << "\n";
    } else if (__builtin_popcount(n) == 1 && __builtin_ctz(n) % 2 == 1){
      cout << "Bob" << "\n";
    } else {
      cout << "Alice" << "\n";
    }
  }
}