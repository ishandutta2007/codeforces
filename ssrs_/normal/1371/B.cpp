#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n, r;
    cin >> n >> r;
    if (r < n){
      cout << r * (r + 1) / 2 << endl;
    } else {
      cout << n * (n - 1) / 2 + 1 << endl;
    }
  }
}