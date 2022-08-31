#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = "9" + string(n - 2, '0') + "1";
    vector<int> a(n + 1, 0);
    a[0] = 1;
    a[n] = 1;
    if (s > t){
      a = vector<int>(n + 1, 1);
      a[n - 1] = 1;
    }
    for (int j = 0; j < n; j++){
      a[j] -= s[n - 1 - j] - '0';
    }
    for (int j = 0; j < n; j++){
      if (a[j] < 0){
        a[j] += 10;
        a[j + 1]--;
      }
    }
    for (int j = n - 1; j >= 0; j--){
      cout << a[j];
    }
    cout << endl;
  }
}