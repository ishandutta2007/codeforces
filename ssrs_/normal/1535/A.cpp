#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    vector<int> s(4);
    for (int j = 0; j < 4; j++){
      cin >> s[j];
    }
    int m1 = max(s[0], s[1]);
    int m2 = max(s[2], s[3]);
    if (m1 > m2){
      swap(m1, m2);
    }
    sort(s.begin(), s.end());
    if (s[2] == m1 && s[3] == m2){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}