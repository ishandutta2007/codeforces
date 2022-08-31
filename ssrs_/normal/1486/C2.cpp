#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  if (n == 2){
    cout << "? 1 2" << endl;
    int p;
    cin >> p;
    cout << "! " << 3 - p << endl;
  } else {
    cout << "? 1 " << n << endl;
    int p;
    cin >> p;
    p--;
    int tv = n, fv = 0;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      int l = max(p - mid, 0);
      int r = min(p + mid, n - 1);
      cout << "? " << l + 1 << " " << r + 1 << endl;
      int p2;
      cin >> p2;
      p2--;
      if (p == p2){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    int l = max(p - tv, 0);
    int r = min(p + tv - 1, n - 1);
    cout << "? " << l + 1 << " " << r + 1 << endl;
    int p2;
    cin >> p2;
    p2--;
    if (p2 != p){
      cout << "! " << p + tv + 1 << endl;
    } else {
      cout << "! " << p - tv + 1 << endl;
    }
  }
}