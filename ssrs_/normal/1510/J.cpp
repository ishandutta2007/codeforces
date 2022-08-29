#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  s = "_" + s + "_";
  int N = s.size();
  vector<pair<char, int>> rle;
  rle.push_back(make_pair(s[0], 1));
  for (int i = 1; i < N; i++){
    if (s[i] == s[i - 1]){
      rle.back().second++;
    } else {
      rle.push_back(make_pair(s[i], 1));
    }
  }
  int cnt = rle.size();
  if (cnt == 1){
    cout << 0 << endl;
  } else {
    set<int> st;
    for (int i = 0; i < cnt; i += 2){
      st.insert(rle[i].second);
    }
    int mn = *st.begin();
    int d = -1;
    if (st.size() == 1 && mn == 1){
      d = 0;
    }
    if (mn % 2 == 0){
      bool ok = true;
      for (int x : st){
        if (x % 2 == 1){
          ok = false;
        }
      }
      if (ok){
        d = 1;
      }
    }
    for (int i = 2; i < mn; i++){
      if (st.count(i + 2) == 0){
        d = i;
      }
    }
    if (d == -1){
      cout << -1 << endl;
    } else {
      vector<int> ans;
      for (int i = 0; i < cnt; i++){
        int L = rle[i].second;
        if (i % 2 == 0){
          int a = L - (d + 1);
          if (a % 2 == 0){
            for (int j = 0; j < a / 2; j++){
              ans.push_back(1);
            }
          } else {
            for (int j = 0; j < a / 2 - 1; j++){
              ans.push_back(1);
            }
            ans.push_back(2);
          }
        } else {
          ans.push_back(L + d);
        }
      }
      int k = ans.size();
      cout << k << endl;
      for (int i = 0; i < k; i++){
        cout << ans[i];
        if (i < k - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}