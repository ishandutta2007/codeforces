#include <bits/stdc++.h>
using namespace std;
const int B = 2154;
const int INF = 1000000000;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> b = a;
  vector<tuple<int, int, int, int, int, int, int>> query;
  vector<tuple<int, int, int>> update;
  for (int i = 0; i < m; i++){
    int t;
    cin >> t;
    if (t == 1){
      int l, r, k;
      cin >> l >> r >> k;
      l--;
      int cnt = update.size();
      int id = query.size();
      query.push_back(make_tuple(cnt / B, l / B, r, l, cnt, k, id));
    }
    if (t == 2){
      int p, x;
      cin >> p >> x;
      p--;
      x--;
      update.push_back(make_tuple(p, b[p], x));
      b[p] = x;
    }
  }
  sort(query.begin(), query.end());
  int query_cnt = query.size();
  vector<int> cnt(100000, 0);
  vector<int> scnt(100000, 0);
  vector<int> sum(100001, 100000);
  sum[0] = 0;
  b = a;
  int ct = 0, cl = 0, cr = 0;
  vector<int> ans(query_cnt, INF);
  for (int i = 0; i < query_cnt; i++){
    int r, l, t, k, id;
    tie(ignore, ignore, r, l, t, k, id) = query[i];
    while (ct > t){
      ct--;
      int pos = get<0>(update[ct]);
      int prev = b[pos];
      int next = get<1>(update[ct]);
      if (cl <= pos && pos < cr){
        scnt[sum[cnt[prev]]]--;
        sum[cnt[prev]]++;
        cnt[prev]--;
        scnt[sum[cnt[next] + 1] - 1]++;
        sum[cnt[next] + 1]--;
        cnt[next]++;
      }
      b[pos] = next;
    }
    while (ct < t){
      int pos = get<0>(update[ct]);
      int prev = b[pos];
      int next = get<2>(update[ct]);
      if (cl <= pos && pos < cr){
        scnt[sum[cnt[prev]]]--;
        sum[cnt[prev]]++;
        cnt[prev]--;
        scnt[sum[cnt[next] + 1] - 1]++;
        sum[cnt[next] + 1]--;
        cnt[next]++;
      }
      b[pos] = next;
      ct++;
    }
    while (l < cl){
      cl--;
      scnt[sum[cnt[b[cl]] + 1] - 1]++;
      sum[cnt[b[cl]] + 1]--;
      cnt[b[cl]]++;
    }
    while (cr < r){
      scnt[sum[cnt[b[cr]] + 1] - 1]++;
      sum[cnt[b[cr]] + 1]--;
      cnt[b[cr]]++;
      cr++;
    }
    while (cl < l){
      scnt[sum[cnt[b[cl]]]]--;
      sum[cnt[b[cl]]]++;
      cnt[b[cl]]--;
      cl++;
    }
    while (r < cr){
      cr--;
      scnt[sum[cnt[b[cr]]]]--;
      sum[cnt[b[cr]]]++;
      cnt[b[cr]]--;
    }
    if (100000 - sum[1] < k){
      ans[id] = -1;
    } else {
      int pos = upper_bound(scnt.begin(), scnt.end(), 0) - scnt.begin();
      while (pos <= 100000 - k){
        ans[id] = min(ans[id], scnt[pos + k - 1] - scnt[pos]);
        pos = upper_bound(scnt.begin(), scnt.end(), scnt[pos]) - scnt.begin();
      }
    }
  }
  for (int i = 0; i < query_cnt; i++){
    cout << ans[i] << "\n";
  }
}