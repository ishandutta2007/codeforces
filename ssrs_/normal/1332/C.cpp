#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> c1(n), c2(n), c3(n);
    for (int j = 0; j < n; j++){
      c1[j] = j % k;
    }
    c2 = c1;
    reverse(c2.begin(), c2.end());
    for (int j = 0; j < n; j++){
      c3[j] = min(c1[j], c2[j]);
    }
    vector<vector<char>> S(k);
    for (int j = 0; j < n; j++){
      S[c3[j]].push_back(s[j]);
    }
    vector<map<char, int>> M(k);
    for (int j = 0; j < n; j++){
      M[c3[j]][s[j]]++;
    }
    int ans = 0;
    for (int j = 0; j < k; j++){
      int m = 0;
      for (char c = 'a'; c <= 'z'; c++){
        m = max(m, M[j][c]);
      }
      ans += (S[j].size() - m);
    }
    cout << ans << endl;
  }
}