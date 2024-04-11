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
    for (int i = 0; i < n; i++){
      cout << s[i * 2];
    }
    cout << endl;
  }
}