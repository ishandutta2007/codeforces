#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<pair<char, int>> rle;
  rle.push_back(make_pair(s[0], 1));
  for (int i = 1; i < n; i++){
    if (s[i - 1] == s[i]){
      rle.back().second++;
    } else {
      rle.push_back(make_pair(s[i], 1));
    }
  }
  int cnt = rle.size();
  vector<int> c(26, 0);
  for (int i = 0; i < cnt; i++){
    c[rle[i].first - 'a'] += rle[i].second / k;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++){
    ans = max(ans, c[i]);
  }
  cout << ans << endl;
}