#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    if (s == s2){
      cout << 1 << endl;
    } else if (k == 0){
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}