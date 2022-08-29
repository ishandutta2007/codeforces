#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (s[j] == 'N'){
        cnt++;
      }
    }
    if (cnt == 1){
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}