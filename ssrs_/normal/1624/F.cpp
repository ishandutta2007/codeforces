#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int tv = 1, fv = n;
  int p = 0;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    int c = n - mid % n;
    cout << "+ " << c << endl;
    int q;
    cin >> q;
    if (q > p){
      tv = mid;
    } else {
      fv = mid;
    }
    tv += c;
    fv += c;
    p = q;
  }
  cout << "! " << tv << endl;
}