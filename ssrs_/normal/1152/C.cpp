#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000000;
int main(){
  long long a, b;
  cin >> a >> b;
  if (a == b){
    cout << 0 << endl;
  } else {
    int d = abs(a - b);
    vector<int> f;
    for (int i = 1; i * i <= d; i++){
      if (d % i == 0){
        f.push_back(i);
        if (i * i < d){
          f.push_back(d / i);
        }
      }
    }
    int cnt = f.size();
    long long ml = INF;
    long long ans = INF;
    for (int i = 0; i < cnt; i++){
      int r = a % f[i];
      long long k = (f[i] - r) % f[i];
      long long L = (a + k) * (b + k) / f[i];
      if (L == ml){
        ans = min(ans, k);
      } else if (L < ml){
        ml = L;
        ans = k;
      }
    }
    cout << ans << endl;
  }
}