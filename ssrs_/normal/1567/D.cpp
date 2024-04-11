#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    int n;
    cin >> s >> n;
    int m = s.size();
    vector<int> a(m);
    for (int j = 0; j < m; j++){
      a[j] = s[j] - '0';
    }
    int sum = 0;
    for (int j = 0; j < m; j++){
      sum += a[j];
    }
    while (sum < n){
      for (int j = m - 2; j >= 0; j--){
        if (a[j] > 0){
          a[j]--;
          a[j + 1] += 10;
          sum += 9;
          break;
        }
      }
    }
    vector<int> b;
    int p = 1;
    for (int j = m - 1; j >= 0; j--){
      for (int k = 0; k < a[j]; k++){
        b.push_back(p);
      }
      p *= 10;
    }
    while (b.size() > n){
      int x = b.back();
      b.pop_back();
      b.back() += x;
    }
    for (int j = 0; j < n; j++){
      cout << b[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}