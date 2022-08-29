#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(20);
  int n;
  double l, v1, v2;
  int k;
  cin >> n >> l >> v1 >> v2 >> k;
  n = (n + k - 1) / k;
  double t = l / (2 * (n - 1) * v1 * v2 / (v1 + v2) + v2);
  cout << t + (l - t * v2) / v1 << endl;
}