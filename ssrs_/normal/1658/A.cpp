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
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (s[j] == '0'){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    int ans = 0;
    for (int j = 0; j < cnt - 1; j++){
      int d = p[j + 1] - p[j];
      ans += max(3 - d, 0);
    }
    cout << ans << endl;
  }
}