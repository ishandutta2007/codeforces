#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  string s;
  cin >> s;
  s = '1' + s + '1';
  n += 2;
  vector<int> cnt(1, 0);
  for (int i = 1; i < n; i++){
    if (s[i] == '1'){
      cnt.push_back(0);
    } else {
      cnt.back()++;
    }
  }
  int m = cnt.size();
  int mx = 0;
  for (int i = 0; i < m; i++){
    mx += cnt[i] / b;
  }
  int ans_cnt = mx - a + 1;
  vector<int> ans;
  int curr = 0;
  for (int i = 0; i < n; i++){
    if (s[i] == '1'){
      curr = 0;
    } else {
      curr++;
      if (curr % b == 0){
        ans.push_back(i);
      }
    }
  }
  cout << ans_cnt << endl;
  for (int i = 0; i < ans_cnt; i++){
    cout << ans[i];
    if (i < ans_cnt - 1){
      cout << ' ';
    }
  }
  cout << endl;
}