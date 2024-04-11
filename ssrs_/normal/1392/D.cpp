#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    string S;
    cin >> S;
    vector<pair<char, int>> E;
    E.push_back(make_pair(S[0], 1));
    for (int j = 1; j < n; j++){
      if (S[j - 1] == S[j]){
        E.back().second++;
      } else {
        E.push_back(make_pair(S[j], 1));
      }
    }
    if (E.size() == 1){
      cout << (n + 2) / 3 << endl;
    } else {
      if (E.back().first == E.front().first){
        E.front().second += E.back().second;
        E.pop_back();
      }
      int ans = 0;
      for (auto P : E){
        int x = P.second;
        ans += x / 3;
      }
      cout << ans << endl;
    }
  }
}