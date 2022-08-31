#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n;
    cin >> n;
    if (n % 2 == 1 || n == 2){
      cout << -1 << endl;
    } else {
      cout << (n + 4) / 6 << ' ' << n / 4 << endl;
    }
  }
}