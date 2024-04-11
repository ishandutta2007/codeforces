#include <bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin >> m;
  string s;
  cin >> s;
  int N = s.size();
  vector<vector<int>> id(26);
  for (int i = 0; i < N; i++){
    id[s[i] - 'a'].push_back(i);
  }
  int tv = 26, fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    vector<int> id2;
    for (int i = 0; i < mid; i++){
      int cnt = id[i].size();
      for (int j = 0; j < cnt; j++){
        id2.push_back(id[i][j]);
      }
    }
    sort(id2.begin(), id2.end());
    if (id2.empty()){
      fv = mid;
    } else if (id2.front() >= m){
      fv = mid;
    } else if (id2.back() < N - m){
      fv = mid;
    } else {
      int cnt = id2.size();
      bool ok = true;
      for (int i = 0; i < cnt - 1; i++){
        if (id2[i + 1] - id2[i] > m){
          ok = false;
        }
      }
      if (ok){
        tv = mid;
      } else {
        fv = mid;
      }
    }
  }
  vector<int> id2;
  for (int i = 0; i < fv; i++){
    int cnt = id[i].size();
    for (int j = 0; j < cnt; j++){
      id2.push_back(id[i][j]);
    }
  }
  id2.push_back(-1);
  id2.push_back(N);
  sort(id2.begin(), id2.end());
  int cnt = id2.size();
  int C = 0;
  for (int i = 0; i < cnt - 1; i++){
    int R = id2[i] + m + 1;
    while (true){
      if (R > id2[i + 1] && !(cnt == 2 && C == 0)){
        break;
      }
      auto itr = lower_bound(id[fv].begin(), id[fv].end(), R) - 1;
      C++;
      R = *itr + m + 1;
    }
  }
  string ans;
  for (int i = 0; i < fv; i++){
    ans += string(id[i].size(), (char) ('a' + i));
  }
  ans += string(C, (char) ('a' + fv));
  cout << ans << endl;
}