#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    cout << k + (a[r - 1] - a[l]) - 2 * (r - l) + 1 << endl;
  }
}