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
    vector<int> p;
    for (int j = n - 1; j >= 0; j--){
      if (a[j] % 2 == a[0] % 2){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    cout << n - 1 << endl;
    for (int j = 0; j < cnt - 1; j++){
      cout << p[j + 1] + 1 << ' ' << p[j] + 1 << endl;
    }
    for (int j = 0; j < n; j++){
      if (a[j] % 2 != a[0] % 2){
        cout << 1 << ' ' << j + 1 << endl;
      }
    }
  }
}