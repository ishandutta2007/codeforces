#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    map<int, int> mp;
    for (int j = 0; j < n; j++){
      mp[a[j]]++;
    }
    vector<pair<int, int>> F;
    for (auto P : mp){
      F.push_back(make_pair(P.second, P.first));
    }
    sort(F.begin(), F.end());
    int cnt = F.size();
    map<int, int> pos;
    for (int j = 0; j < cnt; j++){
      pos[F[j].second] = j;
    }
    binary_indexed_tree<int> BIT1(cnt), BIT2(cnt);
    for (int j = 0; j < cnt; j++){
      BIT1.add(j, F[j].first);
      BIT2.add(j, 1);
    }
    int h = 0;
    int ans = INF;
    for (int j = 0; j <= n; j++){
      if (pos.count(j) == 1){
        int p = pos[j];
        BIT1.add(p, -F[p].first);
        BIT2.add(p, -1);
      }
      if (max(h, mp[j]) <= k){
        int c = k - mp[j];
        int tv = cnt + 1, fv = 0;
        while (tv - fv > 1){
          int mid = (tv + fv) / 2;
          if (BIT1.sum(mid) > c){
            tv = mid;
          } else {
            fv = mid;
          }
        }
        int cost = BIT2.sum(tv - 1, cnt);
        if (j == 0 && cost == 0){
          cost = 1;
        }
        ans = min(ans, cost);
      }
      if (mp[j] == 0){
        h++;
      }
    }
    cout << ans << endl;
  }
}