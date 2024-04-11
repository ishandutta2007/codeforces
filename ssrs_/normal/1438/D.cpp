#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long X = 0;
  for (int i = 0; i < n; i++){
    X ^= a[i];
  }
  bool ok;
  vector<tuple<int, int, int>> op;
  if (n % 2 == 0){
    if (X != 0){
      ok = false;
    } else {
      ok = true;
      op.push_back(make_tuple(0, 1, 2));
      for (int i = 2; i < n - 2; i += 2){
        op.push_back(make_tuple(i + 1, i + 2, i + 3));
        op.push_back(make_tuple(i, i + 1, i + 2));
      }
    }
  } else {
    ok = true;
    for (int i = 0; i <= n - 3; i += 2){
      op.push_back(make_tuple(i, i + 1, i + 2));
    }
    for (int i = n - 5; i >= 0; i -= 2){
      op.push_back(make_tuple(i, i + 1, i + 2));
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    int m = op.size();
    cout << m << endl;
    for (int i = 0; i < m; i++){
      cout << get<0>(op[i]) + 1 << ' ' << get<1>(op[i]) + 1 << ' ' << get<2>(op[i]) + 1 << endl;
    }
  }
}