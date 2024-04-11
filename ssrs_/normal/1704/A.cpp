#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    string a;
    cin >> a;
    string b;
    cin >> b;
    if (n == m){
      if (a == b){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (a.substr(n - m + 1) != b.substr(1)){
        cout << "NO" << endl;
      } else {
        string c = a.substr(0, n - m + 1);
        if (c == string(n - m + 1, '0') && b[0] == '1' || c == string(n - m + 1, '1') && b[0] == '0'){
          cout << "NO" << endl;
        } else {
          cout << "YES" << endl;
        }
      }
    }
  }
}