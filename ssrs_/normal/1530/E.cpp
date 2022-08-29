#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int N = s.size();
    sort(s.begin(), s.end());
    if (s == string(N, s[0])){
      cout << s << "\n";
    } else {
      vector<int> cnt(26, 0);
      for (int j = 0; j < N; j++){
        cnt[s[j] - 'a']++;
      }
      int p = -1;
      for (int j = 0; j < 26; j++){
        if (cnt[j] == 1){
          p = j;
          break;
        }
      }
      if (p != -1){
        string ans;
        ans += (char) ('a' + p);
        cnt[p] = 0;
        for (int j = 0; j < 26; j++){
          ans += string(cnt[j], 'a' + j);
        }
        cout << ans << "\n";
      } else {
        vector<int> id;
        for (int j = 0; j < 26; j++){
          if (cnt[j] > 0){
            id.push_back(j);
          }
        }
        if (cnt[id[0]] <= N / 2 + 1){
          string ans;
          ans += (char) ('a' + id[0]);
          ans += (char) ('a' + id[0]);
          cnt[id[0]] -= 2;
          for(int j = id[1]; j < 26; j++){
            for (int k = 0; k < cnt[j]; k++){
              ans += (char) ('a' + j);
              if (cnt[id[0]] > 0){
                ans += (char) ('a' + id[0]);
                cnt[id[0]]--;
              }
            }
          }
          cout << ans << "\n";
        } else if (id.size() == 2){
          string ans;
          ans += (char) ('a' + id[0]);
          ans += string(cnt[id[1]], 'a' + id[1]);
          ans += string(cnt[id[0]] - 1, 'a' + id[0]);
          for (int j = id[1] + 1; j < 26; j++){
            ans += string(cnt[j], 'a' + j);
          }
          cout << ans << "\n";
        } else {
          string ans;
          ans += (char) ('a' + id[0]);
          ans += (char) ('a' + id[1]);
          ans += string(cnt[id[0]] - 1, 'a' + id[0]);
          ans += (char) ('a' + id[2]);
          ans += string(cnt[id[1]] - 1, 'a' + id[1]);
          ans += string(cnt[id[2]] - 1, 'a' + id[2]);
          for (int j = id[2] + 1; j < 26; j++){
            ans += string(cnt[j], 'a' + j);
          }
          cout << ans << "\n";
        }
      }
    }
  }
}