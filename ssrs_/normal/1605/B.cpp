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
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        cnt++;
      }
    }
    vector<int> a, b;
    for (int j = 0; j < cnt; j++){
      if (s[j] == '1'){
        a.push_back(j);
      }
    }
    for (int j = cnt; j < n; j++){
      if (s[j] == '0'){
        b.push_back(j);
      }
    }
    if (a.empty()){
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
      int x = a.size();
      cout << x * 2;
      for (int j = 0; j < x; j++){
        cout << ' ' << a[j] + 1;
      }
      for (int j = 0; j < x; j++){
        cout << ' ' << b[j] + 1;
      }
      cout << endl;
    }
  }
}