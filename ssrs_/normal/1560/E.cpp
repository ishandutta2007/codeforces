#include <bits/stdc++.h>
using namespace std;
int main(){
  int T;
  cin >> T;
  for (int i = 0; i < T; i++){
    string t;
    cin >> t;
    int N = t.size();
    vector<bool> used(26, 0);
    vector<int> C;
    for (int j = N - 1; j >= 0; j--){
      if (!used[t[j] - 'a']){
        used[t[j] - 'a'] = true;
        C.push_back(t[j] - 'a');
      }
    }
    vector<int> cnt(26, 0);
    for (int j = 0; j < N; j++){
      cnt[t[j] - 'a']++;
    }
    int M = C.size();
    bool ok = true;
    vector<int> cnt2(26, 0);
    for (int j = 0; j < M; j++){
      if (cnt[C[j]] % (M - j) != 0){
        ok = false;
      } else {
        cnt2[C[j]] = cnt[C[j]] / (M - j);
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      reverse(C.begin(), C.end());
      int sum = 0;
      for (int j = 0; j < 26; j++){
        sum += cnt2[j];
      }
      string s = t.substr(0, sum);
      vector<int> P(26, -1);
      for (int j = 0; j < M; j++){
        P[C[j]] = j;
      }
      string s2;
      for (int j = 0; j < M; j++){
        for (int k = 0; k < sum; k++){
          if (P[s[k] - 'a'] >= j){
            s2 += s[k];
          }
        }
      }
      if (s2 == t){
        cout << s << ' ';
        for (int j = 0; j < M; j++){
          cout << (char) ('a' + C[j]);
        }
        cout << endl;
      } else {
        cout << -1 << endl;
      }
    }
  }
}