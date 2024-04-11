#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long A, B;
    cin >> A >> B;
    if (B == 1){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << A << ' ' << A * (B * 2 - 1) << ' ' << A * B * 2 << endl;
    }
  }
}