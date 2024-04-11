#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> cnt(n + m, 0);
  vector<vector<vector<pair<int, int>>>> S(n, vector<vector<pair<int, int>>>(m));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      int x = i - j + m - 1;
      S[i][j].push_back(make_pair(x, cnt[x]));
      cnt[x]++;
      S[i][j].push_back(make_pair(x + 1, cnt[x + 1]));
      cnt[x + 1]++;
    }
  }
  vector<set<int>> st(n + m);
  for (int i = 0; i < n + m; i++){
    st[i].insert(-1);
    st[i].insert(cnt[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n + m; i++){
    ans += cnt[i] * (cnt[i] - 1) / 2;
  }
  int free = n * m;
  vector<vector<bool>> A(n, vector<bool>(m, false));
  for (int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    if (!A[x][y]){
      for (auto P : S[x][y]){
        int id = P.first, p = P.second;
        assert(st[id].count(p) == 0);
        int L = *prev(st[id].lower_bound(p));
        int R = *st[id].upper_bound(p);
        ans -= (R - L - 1) * (R - L - 2) / 2;
        ans += (p - L - 1) * (p - L - 2) / 2;
        ans += (R - p - 1) * (R - p - 2) / 2;
        st[id].insert(p);
      }
      A[x][y] = true;
      free--;
    } else {
      for (auto P : S[x][y]){
        int id = P.first, p = P.second;
        assert(st[id].count(p) == 1);
        int L = *prev(st[id].lower_bound(p));
        int R = *st[id].upper_bound(p);
        ans += (R - L - 1) * (R - L - 2) / 2;
        ans -= (p - L - 1) * (p - L - 2) / 2;
        ans -= (R - p - 1) * (R - p - 2) / 2;
        st[id].erase(p);
      }
      A[x][y] = false;
      free++;
    }
    cout << ans + free << endl;
  }
}