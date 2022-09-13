#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    string s;
    cin >> s;
    int n = s.size();
    int w, m;
    cin >> w >> m;
    vector<int> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + (s[j] - '0');
    }
    vector<int> p1(9, INF), p2(9, INF);
    for (int j = 0; j <= n - w; j++){
      int p = (S[j + w] - S[j]) % 9;
      if (p1[p] == INF){
        p1[p] = j;
      } else if (p2[p] == INF){
        p2[p] = j;
      }
    }
    for (int j = 0; j < m; j++){
      int l, r, k;
      cin >> l >> r >> k;
      l--;
     int x = (S[r] - S[l]) % 9;
      pair<int, int> P = make_pair(INF, INF);
      for (int a = 0; a < 9; a++){
        int b = (k - a * x % 9 + 9) % 9;
        if (a == b){
          if (p1[a] != INF && p2[a] != INF){
            P = min(P, make_pair(p1[a], p2[a]));
          }
        } else {
          if (p1[a] != INF && p1[b] != INF){
            P = min(P, make_pair(p1[a], p1[b]));
          }
        }
      }
      if (P == make_pair(INF, INF)){
        cout << -1 << ' ' << -1 << "\n";
      } else {
        cout << P.first + 1 << ' ' << P.second + 1 << "\n";
      }
    }
  }
}