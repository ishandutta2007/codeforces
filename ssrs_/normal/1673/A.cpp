#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    if (n % 2 == 0){
      int sum = 0;
      for (int j = 0; j < n; j++){
        sum += s[j] - 'a' + 1;
      }
      cout << "Alice " << sum << endl;
    }
    if (n % 2 == 1){
      int a1 = 0;
      for (int j = 0; j < n - 1; j++){
        a1 += s[j] - 'a' + 1;
      }
      int b1 = s[n - 1] - 'a' + 1;
      int a2 = 0;
      for (int j = 1; j < n; j++){
        a2 += s[j] - 'a' + 1;
      }
      int b2 = s[0] - 'a' + 1;
      int a = max(a1, a2);
      int b = min(b1, b2);
      if (a > b){
        cout << "Alice " << a - b << endl;
      } else {
        cout << "Bob " << b - a << endl;
      }
    }
  }
}