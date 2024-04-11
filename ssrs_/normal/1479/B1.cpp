#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> rle;
  rle.push_back(make_pair(a[0], 1));
  for (int i = 1; i < n; i++){
    if (a[i] == a[i - 1]){
      rle.back().second++;
    } else {
      rle.push_back(make_pair(a[i], 1));
    }
  }
  int cnt = rle.size();
  int ans = 0;
  for (int i = 0; i < cnt; i++){
    ans += min(rle[i].second, 2);
  }
  for (int i = 0; i < cnt; i++){
    if (rle[i].second >= 2){
      int c = i + 1;
      while (c < cnt){
        if (c % 2 != i % 2){
          if (rle[c].second != 1){
            break;
          }
        } else {
          if (rle[c].first != rle[i].first){
            break;
          }
          if (rle[c].second >= 2){
            ans--;
            break;
          }
        }
        c++;
      }
    }
  }
  cout << ans << endl;
}