#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    vector<vector<int>> cnt(26, vector<int>(26, 0));
    for (int j = 0; j < n; j++){
      int x = s1[j] - 'a';
      int y = s2[n - 1 - j] - 'a';
      if (x > y){
        swap(x, y);
      }
      cnt[x][y]++;
    }
    bool ok = true;
    int c = 0;
    for (int j = 0; j < 26; j++){
      for (int k = j; k < 26; k++){
        if (cnt[j][k] % 2 == 1){
          if (j != k){
            ok = false;
          } else {
            c++;
          }
        }
      }
    }
    if (n % 2 == 0 && c > 0){
      ok = false;
    }
    if (n % 2 == 1 && c > 1){
      ok = false;
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}