#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<long long, int> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]]++;
  }
  vector<int> ans;
  for (int m = mp[1]; m >= 1; m--){
    map<long long, int> mp2 = mp;
    map<long long, int> mp3;
    map<long long, int> mp4;
    long long x = 1;
    int cnt = m;
    if (m < mp2[1]){
      mp3[1] = mp2[1] - m;
      mp2[1] = m;
      mp4[1] = m;
    } else {
      mp4[1] = mp2[1];
    }
    while (1){
      x *= 2;
      if (mp2[x] == 0){
        mp4[x] = 0;
        break;
      }
      if (mp2[x] > cnt){
        mp3[x] = mp2[x] - cnt;
        mp2[x] = cnt;
        mp4[x] = cnt;
      } else {
        cnt = mp2[x];
        mp4[x] = cnt;
      }
    }
    
    for (auto P : mp2){
      if (__builtin_popcountll(P.first) > 1){
        mp3[P.first] = P.second;
      }
    }
    vector<pair<long long, int>> rem;
    for (auto P : mp3){
      rem.push_back(P);
    }
    vector<pair<long long, int>> next;
    for (auto P : mp4){
      next.push_back(P);
    }
    int cnt1 = rem.size();
    int cnt2 = next.size();
    vector<pair<long long, int>> next2;
    for (int i = 0; i < cnt2 - 1; i++){
      if (next[i].second != next[i + 1].second){
        next2.push_back(make_pair(next[i].first, next[i].second - next[i + 1].second));
      }
    }
    int cnt3 = next2.size();
    bool ok = true;
    for (int i = cnt1 - 1; i >= 0; i--){
      if (next2.empty()){
        ok = false;
        break;
      } else if (next2.back().first * 2 < rem[i].first){
        ok = false;
        break;
      } else if (next2.back().second > rem[i].second){
        next2.back().second -= rem[i].second;
      } else if (next2.back().second == rem[i].second){
        next2.pop_back();
      } else {
        rem[i].second -= next2.back().second;
        next2.pop_back();
        i++;
      }
    }
    if (ok){
      ans.push_back(m);
    } else {
      break;
    }
  }
  int sz = ans.size();
  sort(ans.begin(), ans.end());
  if (sz == 0){
    cout << -1 << endl;
  } else {
    for (int i = 0; i < sz; i++){
      cout << ans[i];
      if (i < sz - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}