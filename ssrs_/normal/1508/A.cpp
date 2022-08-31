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
    vector<string> s(3);
    for (int j = 0; j < 3; j++){
      cin >> s[j];
    }
    vector<vector<int>> cnt(3, vector<int>(2, 0));
    for (int j = 0; j < 3; j++){
      for (int k = 0; k < n * 2; k++){
        cnt[j][s[j][k] - '0']++;
      }
    }
    int a, b, c;
    for (int j = 0; j < 3; j++){
      for (int k = j + 1; k < 3; k++){
        for (int l = 0; l < 2; l++){
          if (cnt[j][l] >= cnt[j][1 - l] && cnt[k][l] >= cnt[k][1 - l]){
            a = j;
            b = k;
            c = l;
          }
        }
      }
    }
    vector<int> cnt1 = {0};
    for (int j = 0; j < n * 2; j++){
      if (s[a][j] - '0' == c){
        cnt1.push_back(0);
      } else {
        cnt1.back()++;
      }
    }
    vector<int> cnt2 = {0};
    for (int j = 0; j < n * 2; j++){
      if (s[b][j] - '0' == c){
        cnt2.push_back(0);
      } else {
        cnt2.back()++;
      }
    }
    int sz1 = cnt1.size();
    int sz2 = cnt2.size();
    int sz = max(sz1, sz2);
    vector<int> mx(sz, 0);
    for (int j = 0; j < sz1; j++){
      mx[j] = max(mx[j], cnt1[j]);
    }
    for (int j = 0; j < sz2; j++){
      mx[j] = max(mx[j], cnt2[j]);
    }
    string ans;
    for (int j = 0; j < sz; j++){
      if (j > 0){
        ans += (char) ('0' + c);
      }
      for (int k = 0; k < mx[j]; k++){
        ans += (char) ('0' + (1 - c));
      }
    }
    cout << ans << endl;
  }
}