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
    if (s == "0" || s == "1" || s == "01" || s == "10"){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}