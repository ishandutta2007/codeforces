#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    for (int j = 0; j < n; j += 2){
      a[j] *= -1;
    }
    int S = 0;
    for (int j = 0; j < n; j++){
      S += a[j];
    }
    if (S < 0){
      for (int j = 0; j < n; j++){
        a[j] *= -1;
      }
      S *= -1;
    }
    if (S % 2 == 1){
      cout << -1 << endl;
    } else if (S == 0){
      cout << 1 << endl;
      cout << 1 << ' ' << n << endl;
    } else {
      vector<int> p;
      int s = 0;
      for (int j = n - 1; j >= 0; j--){
        s += a[j];
        if (s * 2 == S){
          p.push_back(j);
        }
      }
      if (p[0] % 2 == 1){
        cout << 2 << endl;
        cout << 1 << ' ' << p[0] << endl;
        cout << p[0] + 1 << ' ' << n << endl;
      } else if (p.back() % 2 == 1){
        cout << 2 << endl;
        cout << 1 << ' ' << p.back() << endl;
        cout << p.back() + 1 << ' ' << n << endl;
      } else if (p[0] + 1 == n){
        cout << 3 << endl;
        cout << 1 << ' ' << p.back() - 1 << endl;
        cout << p.back() << ' ' << p[0] << endl;
        cout << p[0] + 1 << ' ' << n << endl;
      } else {
        cout << 4 << endl;
        cout << 1 << ' ' << p.back() - 1 << endl;
        cout << p.back() << ' ' << p[0] << endl;
        cout << p[0] + 1 << ' ' << p[0] + 1 << endl;
        cout << p[0] + 2 << ' ' << n << endl;
      }
    }
  }
}