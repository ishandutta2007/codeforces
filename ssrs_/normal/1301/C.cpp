#include <bits/stdc++.h>
using namespace std;
long long range(long long n){
  return n * (n + 1) / 2;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long n,m;
    cin >> n >> m;
    if (m == 0){
      cout << 0 << endl;
      continue;
    }
    long long f = (n + 1) / (m + 1);
    long long x = n + 1 - f * (m + 1);
    long long y = (m + 1) - x;
    cout << range(n) - range(f) * x - range(f - 1) * y << endl;
  }
}