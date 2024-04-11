#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    k--;
    if (n % 2 == 0){
      cout << k % n + 1 << endl;
    } else {
      int a = n - 1 - k % n;
      int d = k % (n / 2) * 2 + 1;
      cout << (a + d) % n + 1 << endl;
    }
  }
}