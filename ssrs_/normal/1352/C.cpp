#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n, k;
    cin >> n >> k;
    long long ans = n * (k / (n - 1)) + k % (n - 1);
    if (ans % n == 0){
      ans--;
    }
    cout << ans << endl;
  }
}