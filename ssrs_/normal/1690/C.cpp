#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    vector<int> f(n);
    for (int j = 0; j < n; j++){
      cin >> f[j];
    }
    vector<int> s2(n);
    vector<int> d(n);
    s2[0] = s[0];
    for (int j = 0; j < n; j++){
      d[j] = f[j] - s2[j];
      if (j < n - 1){
        s2[j + 1] = max(f[j], s[j + 1]);
      }
    }
    for (int j = 0; j < n; j++){
      cout << d[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}