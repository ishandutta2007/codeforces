#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int l, r;
    cin >> l >> r;
    long long m;
    cin >> m;
    int d = r - l;
    vector<int> ok(d * 2 + 1, -1);
    //[m-d, m+d]
    for (int j = l; j <= r; j++){
      long long start = (j - (m - d) % j) % j;
      for (int k = start; k <= d * 2; k += j){
        ok[k] = j;
      }
    }
    long long value = -1;
    int a = -1;
    for (int j = 0; j <= d * 2; j++){
      long long tmp = m - d + j;
      if (tmp > 0 && ok[j] != -1){
        value = tmp;
        a = ok[j];
      }
    }
    if (value < m){
      cout << a << ' ' << m - value + l << ' ' << l << endl;
    } else {
      cout << a << ' ' << l << ' ' << l + value - m << endl;
    }
  }
}