#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> c(26, 0);
    for (int j = 0; j < n; j++){
      c[s[j] - 'a']++;
    }
    int cnt = 0;
    for (int j = 0; j < 26; j++){
      cnt += min(c[j], 2);
    }
    cout << cnt / 2 << endl;
  }
}