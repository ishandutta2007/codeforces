#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n, k;
    cin >> n >> k;
    long long S = 1;
    long long cnt = 0;
    while (S < n){
      if (S < k){
        S *= 2;
        cnt++;
      } else {
        long long q = (n - S + k - 1) / k;
        cnt += q;
        break;
      }
    }
    cout << cnt << endl;
  }
}