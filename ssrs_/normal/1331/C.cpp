#include <bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin >> a;
  int ans = 0;
  if ((a >> 5) & 1) ans += 32;
  if ((a >> 4) & 1) ans += 1;
  if ((a >> 3) & 1) ans += 4;
  if ((a >> 2) & 1) ans += 8;
  if ((a >> 1) & 1) ans += 2;
  if ((a >> 0) & 1) ans += 16;
  cout << ans << endl;
}