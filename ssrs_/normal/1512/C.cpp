#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    bool ok = true;
    vector<int> p;
    for (int j = 0; j < n; j++){
      if (s[j] != '?' && s[n - 1 - j] != '?'){
        if (s[j] != s[n - 1 - j]){
          ok = false;
        }
      }
      if (s[j] == '?' && s[n - 1 - j] != '?'){
        s[j] = s[n - 1 - j];
      }
      if (s[n - 1 - j] == '?' && s[j] != '?'){
        s[n - 1 - j] = s[j];
      }
      if (s[j] == '?' && s[n - 1 - j] == '?' && j != n - 1 - j){
        p.push_back(j);
      }
    }
    vector<int> cnt(2, 0);
    for (int j = 0; j < n; j++){
      if (s[j] != '?'){
        cnt[s[j] - '0']++;
      }
    }
    if (cnt[0] > a || cnt[1] > b){
      ok = false;
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      int c = p.size();
      int c1 = (a - cnt[0]) / 2;
      int c2 = (b - cnt[1]) / 2;
      for (int j = 0; j < c1; j++){
        s[p[j]] = '0';
        s[n - 1 - p[j]] = '0';
      }
      for (int j = c1; j < c1 + c2; j++){
        s[p[j]] = '1';
        s[n - 1 - p[j]] = '1';
      }
      cnt[0] += c1 * 2;
      cnt[1] += c2 * 2;
      if (n % 2 == 1 && s[n / 2] == '?'){
        if (cnt[0] != a){
          s[n / 2] = '0';
        } else {
          s[n / 2] = '1';
        }
      }
      vector<int> cnt2(2, 0);
      for (int j = 0; j < n; j++){
        cnt2[s[j] - '0']++;
      }
      if (cnt2[0] == a && cnt2[1] == b){
        cout << s << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
}