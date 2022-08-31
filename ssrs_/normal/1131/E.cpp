#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<string> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  int ans = 1;
  vector<pair<char, int>> rle;
  rle.push_back(make_pair(p[n - 1][0], 1));
  int sz = p[n - 1].size();
  for (int i = 1; i < sz; i++){
    if (p[n - 1][i] == p[n - 1][i - 1]){
      rle.back().second++;
      ans = max(ans, rle.back().second);
    } else {
      rle.push_back(make_pair(p[n - 1][i], 1));
    }
  }
  vector<pair<char, int>> curr;
  if (rle.size() <= 2){
    curr = rle;
  } else {
    curr.push_back(rle.front());
    curr.push_back(make_pair('#', 1));
    curr.push_back(rle.back());
  }
  for (int i = n - 2; i >= 0; i--){
    vector<pair<char, int>> tmp = curr;
    int l = p[i].size();
    for (int j = 0; j < l; j++){
      tmp.push_back(make_pair(p[i][j], 1));
      for (auto P : curr){
        tmp.push_back(P);
      }
    }
    int cnt = tmp.size();
    vector<pair<char, int>> tmp2;
    tmp2.push_back(tmp[0]);
    for (int j = 1; j < cnt; j++){
      if (tmp[j].first == tmp[j - 1].first){
        tmp2.back().second += tmp[j].second;
        ans = max(ans, tmp2.back().second);
      } else {
        tmp2.push_back(tmp[j]);
      }
    }
    curr.clear();
    if (tmp2.size() <= 2){
      curr = tmp2;
    } else {
      curr.push_back(tmp2.front());
      curr.push_back(make_pair('#', 1));
      curr.push_back(tmp2.back());
    }
  }
  cout << ans << endl;
}