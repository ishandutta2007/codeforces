#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<bool> d(n - 1);
  for (int i = 0; i < n - 1; i++){
    d[i] = p[i] < p[i + 1];
  }
  vector<pair<bool, int>> rle;
  rle.push_back(make_pair(d[0], 1));
  for (int i = 1; i < n - 1; i++){
    if (d[i] == d[i - 1]){
      rle.back().second++;
    } else {
      rle.push_back(make_pair(d[i], 1));
    }
  }
  int cnt = rle.size();
  int mx = 0;
  vector<int> max_p;
  for (int i = 0; i < cnt; i++){
    if (rle[i].second > mx){
      max_p.clear();
    }
    if (rle[i].second >= mx){
      mx = rle[i].second;
      max_p.push_back(i);
    }
  }
  bool ok = true;
  if (max_p.size() >= 3){
    ok = false;
  }
  if (max_p.size() == 2){
    if (max_p[1] - max_p[0] > 1){
      ok = false;
    }
  }
  if (!ok){
    cout << 0 << endl;
  } else {
    int ans = 0;
    for (int i = 1; i < cnt; i++){
      if (rle[i - 1].first && !rle[i].first){
        if (rle[i - 1].second == mx && rle[i].second == mx && mx % 2 == 0){
          ans++;
        }
      }
    }
    cout << ans << endl;
  }
}