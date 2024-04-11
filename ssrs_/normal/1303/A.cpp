#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    bool B = true;
    for (int j = 0; j < s.size(); j++){
      if (s[j] == '1') B = false;
    }
    if (B){
      cout << 0 << endl;
      continue;
    }
    int L = 0;
    while (s[L] == '0') L++;
    int R = s.size() - 1;
    while (s[R] == '0') R--;
    int count = 0;
    for (int j = L; j <= R; j++){
      if (s[j] == '0') count++;
    }
    cout << count << endl;
  }
}