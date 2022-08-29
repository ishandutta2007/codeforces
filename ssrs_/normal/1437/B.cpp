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
    for (int j = 0; j < n - 1; j++){
      if (s[j] == s[j + 1]){
        cnt++;
      }
    }
    cout << (cnt + 1) / 2 << endl;
  }
}