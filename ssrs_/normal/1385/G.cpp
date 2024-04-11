#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<set<pair<int, int>>> E1(n);
    vector<vector<pair<int, int>>> E2(n);
    for (int j = 0; j < n; j++){
      E1[a[j]].insert(make_pair(b[j], j));
      E2[a[j]].push_back(make_pair(b[j], j));
      E2[b[j]].push_back(make_pair(a[j], j));
    }
    for (int j = 0; j < n; j++){
      sort(E2[j].begin(), E2[j].end());
    }
    /*
    for (int j = 0; j < n; j++){
      for (auto P : E2[j]){
        cout << P.first << ' ';
      }
      cout << endl;
    }
    */
    vector<int> ans_pos;
    bool ok = true;
    vector<int> cc(n, -1);
    int cc_cnt = 0;
    for (int j = 0; j < n; j++){
      if (cc[j] == -1){
        cc[j] = cc_cnt;
        //list vertices
        vector<int> c;
        c.push_back(j);
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (auto P : E2[v]){
            int w = P.first;
            if (cc[w] == -1){
              cc[w] = cc_cnt;
              c.push_back(w);
              Q.push(w);
            }
          }
        }
        int sz = c.size();
        map<int, int> mp;
        for (int k = 0; k < sz; k++){
          mp[c[k]] = k;
        }
        vector<int> deg(sz);
        for (int v : c){
          deg[mp[v]] = E2[v].size();
        }
        //tree part
        queue<int> Q2;
        for (int v : c){
          if (deg[mp[v]] == 1){
            Q2.push(v);
          }
        }
        vector<bool> cycle(sz, true);
        while (!Q2.empty()){
          int v = Q2.front();
          Q2.pop();
          cycle[mp[v]] = false;
          for (auto P : E2[v]){
            int w = P.first;
            int id = P.second;
            if (cycle[mp[w]]){
              deg[mp[w]]--;
              auto itr = E1[w].lower_bound(make_pair(v, -1));
              if (itr == E1[w].end()){
                ans_pos.push_back(id);
              } else if ((*itr).first != v){
                ans_pos.push_back(id);
              }
              if (deg[mp[w]] == 1){
                Q2.push(w);
              }
            }
          }
        }
        /*
        for (int k = 0; k < sz; k++){
          if (cycle[k]){
            cout << c[k] << ": " << "cycle" << endl;
          } else {
            cout << c[k] << ": " << "tree" << endl;
          }
        }
        */
        int cycle_size = 0;
        for (int k = 0; k < sz; k++){
          if (cycle[k]){
            cycle_size++;
          }
        }
        if (cycle_size != sz){
          ok = false;
          break;
        } else {
          //list vertices in cycle
          int s = -1;
          for (int k = 0; k < sz; k++){
            if (cycle[k]){
              s = c[k];
            }
          }
          cycle[mp[s]] = false;
          vector<int> cycle_vert(1, s);
          vector<int> cycle_edge_id;
          vector<int> cycle_edge_dir;
          for (int k = 0; k < cycle_size; k++){
            int v = cycle_vert.back();
            for (auto P : E2[v]){
              int w = P.first;
              int id = P.second;
              if (cycle[mp[w]]){
                cycle_vert.push_back(w);
                cycle_edge_id.push_back(id);
                auto itr = E1[v].lower_bound(make_pair(w, -1));
                if (itr == E1[v].end()){
                  cycle_edge_dir.push_back(0);
                } else if ((*itr).first != w){
                  cycle_edge_dir.push_back(0);
                } else {
                  cycle_edge_dir.push_back(1);
                }
                cycle[mp[w]] = false;
                break;
              }
            }
          }
          /*
          for (int k : cycle_vert){
            cout << k << ' ';
          }
          cout << endl;
          */
          auto itr = lower_bound(E2[cycle_vert.back()].begin(), E2[cycle_vert.back()].end(), make_pair(s, -1));
          if (itr == E2[cycle_vert.back()].end()){
            ok = false;
            break;
          }
          cycle_edge_id.push_back((*itr).second);
          auto itr2 = E1[cycle_vert.back()].lower_bound(make_pair(s, -1));
          if (itr2 == E1[cycle_vert.back()].end()){
            cycle_edge_dir.push_back(0);
          } else if ((*itr2).first != s){
            cycle_edge_dir.push_back(0);
          } else {
            cycle_edge_dir.push_back(1);
          }
          /*
          for (int k : cycle_edge_id){
            cout << k << ' ';
          }
          cout << endl;
          for (int k : cycle_edge_dir){
            cout << k << ' ';
          }
          cout << endl;
          */
          int cnt0 = 0;
          int cnt1 = 0;
          for (int k = 0; k < sz; k++){
            if (cycle_edge_dir[k] == 0){
              cnt0++;
            } else {
              cnt1++;
            }
          }
          if (cnt0 >= cnt1){
            for (int k = 0; k < sz; k++){
              if (cycle_edge_dir[k] == 1){
                ans_pos.push_back(cycle_edge_id[k]);
              }
            }
          } else {
            for (int k = 0; k < sz; k++){
              if (cycle_edge_dir[k] == 0){
                ans_pos.push_back(cycle_edge_id[k]);
              }
            }
          }
        }
        cc_cnt++;
      }
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      int ans_sz = ans_pos.size();
      if (ans_sz <= n / 2){
        cout << ans_sz << endl;
        for (int j = 0; j < ans_sz; j++){
          cout << ans_pos[j] + 1;
          if (j < ans_sz - 1){
            cout << ' ';
          }
        }
        cout << endl;
      } else {
        vector<int> is_in_ans(n, false);
        for (int j = 0; j < ans_sz; j++){
          is_in_ans[ans_pos[j]] = true;
        }
        vector<int> ans2;
        for (int j = 0; j < n; j++){
          if (!is_in_ans[j]){
            ans2.push_back(j);
          }
        }
        int ans_sz2 = ans2.size();
        cout << ans_sz2 << endl;
        for (int j = 0; j < ans_sz2; j++){
          cout << ans2[j] + 1;
          if (ans2[j] - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}