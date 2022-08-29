#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, l, r;
  cin >> n >> l >> r;
  int mn = (1 << l) - 1 + (n - l);
  int mx = (1 << r) - 1 + (n - r) * (1 << (r - 1));
  cout << mn << ' ' << mx << endl;
}