#include <bits/stdc++.h>
using namespace std;
const int SQRT = 316;
int main(){
  int n;
  cin >> n;
  vector<int> a(n), t(n), x(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> t[i] >> x[i];
  }
  //compress x
  vector<int> x2 = x;
  sort(x2.begin(), x2.end());
  x2.erase(unique(x2.begin(), x2.end()), x2.end());
  int xcnt = x2.size();
  map<int, int> mp;
  for (int i = 0; i < xcnt; i++){
    mp[x2[i]] = i;
  }
  for (int i = 0; i < n; i++){
    x[i] = mp[x[i]];
  }
  //compress t;
  vector<int> t2 = t;
  sort(t2.begin(), t2.end());
  t2.erase(unique(t2.begin(), t2.end()), t2.end());
  int tcnt = t2.size();
  map<int, int> mp2;
  for (int i = 0; i < tcnt; i++){
    mp2[t2[i]] = i;
  }
  for (int i = 0; i < n; i++){
    t[i] = mp2[t[i]];
  }
  vector<int> query_id_t(tcnt);
  for (int i = 0; i < n; i++){
    query_id_t[t[i]] = i;
  }
  //sort queries
  int update_cnt = 0;
  //query: updates, time, id
  vector<int> update_id(n, -1);
  vector<int> query_id;
  vector<tuple<int, int, int, int>> query;
  vector<int> upd_query_id;
  int query_cnt = 0;
  for (int i = 0; i < n; i++){
    if (a[i] == 1 || a[i] == 2){
      update_id[i] = update_cnt;
      query_id.push_back(i);
      update_cnt++;
    } else {
      query.push_back(make_tuple(update_cnt / SQRT, t[i], update_cnt, query_cnt));
      upd_query_id.push_back(i);
      query_cnt++;
    }
  }
  sort(query.begin(), query.end());
  vector<int> ans(query_cnt, -1);
  vector<int> st(xcnt, 0);
  int upd = 0, time = -1;
  for (int i = 0; i < query_cnt; i++){
    int ct = get<1>(query[i]);
    int u = get<2>(query[i]);
    int id = get<3>(query[i]);
    while (time < ct){
      time++;
      if (update_id[query_id_t[time]] < upd){
        if (a[query_id_t[time]] == 1){
          st[x[query_id_t[time]]]++;
        }
        if (a[query_id_t[time]] == 2){
          st[x[query_id_t[time]]]--;
        }
      }
    }
    while (time > ct){
      if (update_id[query_id_t[time]] < upd){
        if (a[query_id_t[time]] == 1){
          st[x[query_id_t[time]]]--;
        }
        if (a[query_id_t[time]] == 2){
          st[x[query_id_t[time]]]++;
        }
      }
      time--;
    }
    while (upd < u){
      if (t[query_id[upd]] <= time){
        if (a[query_id[upd]] == 1){
          st[x[query_id[upd]]]++;
        }
        if (a[query_id[upd]] == 2){
          st[x[query_id[upd]]]--;
        }
      }
      upd++;
    }
    while (upd > u){
      upd--;
      if (t[query_id[upd]] <= time){
        if (a[query_id[upd]] == 1){
          st[x[query_id[upd]]]--;
        }
        if (a[query_id[upd]] == 2){
          st[x[query_id[upd]]]++;
        }
      }
    }
    ans[id] = st[x[upd_query_id[id]]];
  }
  for (int i = 0; i < query_cnt; i++){
    cout << ans[i] << endl;
  }
}