#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    if (b > 0){
      cout << (a + b) * n << endl;
    } else {
      int cnt = 1;
      for (int j = 0; j < n - 1; j++){
        if (s[j] != s[j + 1]){
          cnt++;
        }
      }
      cout << a * n + b * (cnt / 2 + 1) << endl;
    }
  }
}