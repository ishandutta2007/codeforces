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
    int l = -1, r = -1;
    for (int j = 0; j < n - 1; j++){
      if (s[j] != s[j + 1]){
        l = j + 1;
        r = j + 2;
      }
    }
    cout << l << ' ' << r << endl;
  }
}