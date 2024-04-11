#include <bits/stdc++.h>
using namespace std;
int main(){
  long long k, l, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  r -= l;
  k -= l;
  if (x > r){
    cout << "No" << endl;
  } else if (y < x){
    if (k + y <= r){
      k += y;
    }
    long long ans = 0;
    ans += (k - (r - y) + x - 1) / x;
    k -= ans * x;
    if (k < 0){
      ans--;
    } else {
      ans += k / (x - y);
    }
    if (ans < t){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  } else if (r < y){
    if (k / x >= t){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (x <= r - y){
    cout << "Yes" << endl;
  } else {
    if (k <= r - y){
      k += y;
    }
    long long curr = k % x;
    long long ans = k / x;
    bool ok = true;
    for (int i = 0; i < x; i++){
      if (r - y < curr && curr < x){
        ok = false;
        break;
      }
      curr += y;
      ans += curr / x;
      curr %= x;
    }
    if (ok){
      cout << "Yes" << endl;
    } else {
      if (ans < t){
        cout << "No" << endl;
      } else {
        cout << "Yes" << endl;
      }
    }
  }
}