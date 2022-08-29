#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    if (m < n / k){
      cout << m << endl;
    } else if (n - m >= k - 1){
      cout << n / k - (m - n / k + k - 1 - 1) / (k - 1) << endl;
    } else {
      cout << 0 << endl;
    }
  }
}