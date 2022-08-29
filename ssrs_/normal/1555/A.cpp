#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    n = (n + 1) / 2;
    if (n <= 2){
      cout << 15 << endl;
    } else {
      cout << n * 5 << endl;
    }
  }
}