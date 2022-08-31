#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long s, n, k;
    cin >> s >> n >> k;
    if (k > s){
      cout << "NO" << endl;
    } else if (k == s){
      cout << "YES" << endl;
    } else {
      long long q = s / (k * 2);
      long long r = s % (k * 2);
      long long mn = q * k + min(r + 1, k);
      if (mn < n + 1){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}