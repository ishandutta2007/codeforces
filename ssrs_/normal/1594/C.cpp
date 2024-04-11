#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (s[j] != c){
        ok = false;
      }
    }
    if (ok){
      cout << 0 << endl;
    } else {
      vector<int> p;
      for (int j = n / 2; j < n; j++){
        if (s[j] == c){
          p.push_back(j);
        }
      }
      if (!p.empty()){
        cout << 1 << endl;
        cout << p[0] + 1 << endl;
      } else {
        cout << 2 << endl;
        cout << n - 1 << ' ' << n << endl;
      }
    }
  }
}