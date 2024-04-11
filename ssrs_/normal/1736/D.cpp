#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (s[j * 2] != s[j * 2 + 1]){
        p.push_back(j);
      }
    }
    int cnt = p.size();
    if (cnt % 2 == 1){
      cout << -1 << "\n";
    } else {
      vector<int> b;
      if (cnt >= 2){
        b.push_back(p[cnt - 1] * 2);
        for (int j = cnt - 2; j >= 0; j--){
          int c = s[b.back() ^ 1] - '0';
          for (int k = 0; k < 2; k++){
            int x = p[j] * 2 + k;
            if (s[x] == c + '0'){
              b.push_back(x);
            }
          }
        }
      }
      reverse(b.begin(), b.end());
      int m = b.size();
      cout << m << endl;
      for (int j = 0; j < m; j++){
        cout << b[j] + 1;
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
      for (int j = 0; j < n; j++){
        cout << j * 2 + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}