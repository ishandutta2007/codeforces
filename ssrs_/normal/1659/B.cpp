#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k % 2 == 1){
      for (int j = 0; j < n; j++){
        s[j] = '0' + 1 - (s[j] - '0');
      }
    }
    vector<int> f(n, 0);
    for (int j = 0; j < n - 1; j++){
      if (s[j] == '0' && k > 0){
        s[j] = '1';
        f[j] = 1;
        k--;
      }
    }
    f[n - 1] = k;
    if (k % 2 == 1){
      s[n - 1] = '0' + 1 - (s[n - 1] - '0');
    }
    cout << s << endl;
    for (int j = 0; j < n; j++){
      cout << f[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}