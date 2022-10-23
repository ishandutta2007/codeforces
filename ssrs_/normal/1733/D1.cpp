#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, x, y;
    cin >> n >> x >> y;
    string a;
    cin >> a;
    string b;
    cin >> b;
    vector<int> c(n);
    for (int j = 0;  j < n; j++){
      if (a[j] == b[j]){
        c[j] = 0;
      } else {
        c[j] = 1;
      }
    }
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (c[j] == 1){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    if (cnt % 2 == 1){
      cout << -1 << endl;
    } else {
      if (cnt == 0){
        cout << 0 << endl;
      } else if (cnt == 2){
        if (p[1] - p[0] >= 2){
          cout << y << endl;
        } else {
          cout << min(x, y * 2) << endl;
        }
      } else {
        cout << (long long) y * (cnt / 2) << endl;
      }
    }
  }
}