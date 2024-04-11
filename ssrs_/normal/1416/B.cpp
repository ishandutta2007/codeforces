#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += a[j];
    }
    if (sum % n != 0){
      cout << -1 << endl;
    } else {
      vector<tuple<int, int, int>> op;
      int r = sum / n;
      for (int j = 1; j < n; j++){
        int m = j + 1;
        int add = (m - a[j] % m) % m;
        op.push_back(make_tuple(1, j + 1, add));
        a[0] -= add;
        a[j] += add;
        op.push_back(make_tuple(j + 1, 1, a[j] / m));
        a[0] += a[j];
        a[j] = 0;
      }
      for (int j = 1; j < n; j++){
        op.push_back(make_tuple(1, j + 1, r));
      }
      int k = op.size();
      cout << k << endl;
      for (int j = 0; j < k; j++){
        cout << get<0>(op[j]) << ' ' << get<1>(op[j]) << ' ' << get<2>(op[j]) << endl;
      }
    }
  }
}