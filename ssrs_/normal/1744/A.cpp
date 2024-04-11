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
    string s;
    cin >> s;
    bool ok = true;
    for (int j = 0; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (a[j] == a[k] && s[j] != s[k]){
          ok = false;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else { 
      cout << "NO" << endl;
    }
  }
}