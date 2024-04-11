#include <bits/stdc++.h>
using namespace std;
int main(){
  int k;
  cin >> k;
  for (int i = 0; i < k; i++){
    long long n, x, t;
    cin >> n >> x >> t;
    if ((n - 1) * x <= t){
      cout << n * (n - 1) / 2 << endl;
    } else {
      long long m = n - t / x;
      cout << n * (n - 1) / 2 - m * (m - 1) / 2 << endl;
    }
  }
}