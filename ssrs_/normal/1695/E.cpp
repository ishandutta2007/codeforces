#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>> &E, vector<int> &d, vector<int> &p, vector<int> &in, int &t, int v){
  in[v] = t;
  t++;
  for (int w : E[v]){
    if (d[w] == -1){
      d[w] = d[v] + 1;
      p[w] = v;
      dfs(E, d, p, in, t, w);
    }
  }
}
void erase_edge(vector<vector<int>> &c, vector<multiset<pair<int, int>>> &st, int u, int v){
  int cnt = c[u].size();
  auto itr = st[u].lower_bound(make_pair(v, 0));
  int p = (*itr).second;
  st[u].erase(itr);
  if (p != cnt - 1){
    int w = c[u][cnt - 1];
    st[u].erase(st[u].find(make_pair(w, cnt - 1)));
    st[u].insert(make_pair(w, p));
    swap(c[u][p], c[u][cnt - 1]);
  }
  c[u].pop_back();
}
int main(){
  int n;
  cin >> n;
  vector<vector<int>> E(n * 2);
  for (int i = 0; i < n; i++){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    E[x].push_back(y);
    if (x != y){
      E[y].push_back(x);
    }
  }
  vector<int> d(n * 2, -1);
  vector<int> p(n * 2, -1);
  vector<int> in(n * 2, -1);
  int t = 0;
  for (int i = 0; i < n * 2; i++){
    if (d[i] == -1){
      d[i] = 0;
      dfs(E, d, p, in, t, i);
    }
  }
  vector<vector<int>> c(n * 2);
  for (int i = 0; i < n * 2; i++){
    for (int v : E[i]){
      if (in[v] >= in[i]){
        c[i].push_back(v);
      }
    }
  }
  vector<multiset<pair<int, int>>> st(n * 2);
  for (int i = 0; i < n * 2; i++){
    int cnt = c[i].size();
    for (int j = 0; j < cnt; j++){
      st[i].insert(make_pair(c[i][j], j));
    }
  }
  vector<pair<int, int>> P(n * 2);
  for (int i = 0; i < n * 2; i++){
    P[i] = make_pair(d[i], i);
  }
  sort(P.begin(), P.end(), greater<pair<int, int>>());
  vector<int> in2(n * 2);
  for (int i = 0; i < n * 2; i++){
    in2[i] = P[i].second;
  }
  bool ok = true;
  vector<pair<vector<int>, bool>> C;
  for (int i : in2){
    if (!c[i].empty()){
      if (p[i] == -1){
        if (c[i].size() == 1){
          ok = false;
          break;
        } else {
          vector<int> tmp;
          tmp.push_back(i);
          for (int w : c[i]){
            tmp.push_back(w);
          }
          C.push_back(make_pair(tmp, true));
        }
      } else {
        if (c[i].size() == 1){
          if (c[p[i]].size() == 1){
            if (p[p[i]] == -1){
              C.push_back(make_pair(vector<int>{p[i], i,  c[i][0]}, false));
              erase_edge(c, st, p[i], i);
            } else if (p[p[p[i]]] == -1 && c[p[p[i]]].size() == 1){
              C.push_back(make_pair(vector<int>{p[p[i]], p[i], i, c[i][0]}, false));
              erase_edge(c, st, p[i], i);
              erase_edge(c, st, p[p[i]], p[i]);
            } else {
              C.push_back(make_pair(vector<int>{p[i], i,  c[i][0]}, false));
              erase_edge(c, st, p[i], i);
            }
          } else if (c[p[i]].size() == 2){
            if (p[p[i]] == -1){
              if (c[p[i]][1] == i){
                swap(c[p[i]][0], c[p[i]][1]);
                st[p[i]].clear();
                st[p[i]].insert(make_pair(c[p[i]][0], 0));
                st[p[i]].insert(make_pair(c[p[i]][1], 1));
              }
              int v = c[p[i]][1];
              if (i == v){
                C.push_back(make_pair(vector<int>{i, p[i], i, c[i][0]}, false));
                erase_edge(c, st, p[i], i);
                erase_edge(c, st, p[i], i);
              } else {
                erase_edge(c, st, p[i], v);
                erase_edge(c, st, p[i], i);
                if (c[v].empty()){
                  C.push_back(make_pair(vector<int>{v, p[i], i, c[i][0]}, false));
                } else if (c[v].size() == 1){
                  C.push_back(make_pair(vector<int>{p[i], i, c[i][0]}, false));
                  C.push_back(make_pair(vector<int>{p[i], v, c[v][0]}, false));
                  erase_edge(c, st, v, c[v][0]);
                } else {
                  C.push_back(make_pair(vector<int>{v, p[i], i, c[i][0]}, false));
                  vector<int> tmp;
                  tmp.push_back(v);
                  for (int w : c[v]){
                    tmp.push_back(w);
                  }
                  C.push_back(make_pair(tmp, true));
                  c[v].clear();
                }
              }
            } else {
              C.push_back(make_pair(vector<int>{p[i], i, c[i][0]}, false));
              erase_edge(c, st, p[i], i);
            }
          } else {
            C.push_back(make_pair(vector<int>{p[i], i, c[i][0]}, false));
            erase_edge(c, st, p[i], i);
          }
        } else {
          vector<int> tmp;
          tmp.push_back(i);
          for (int v : c[i]){
            tmp.push_back(v);
          }
          if (p[p[i]] == -1 && c[p[i]].size() == 1){
            tmp.push_back(p[i]);
            erase_edge(c, st, p[i], i);
          }
          C.push_back(make_pair(tmp, true));
        }
        c[i].clear();
      }
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    int cnt = C.size();
    vector<int> a0, a1;
    string s0, s1, t0, t1;
    for (int i = 0; i < cnt; i++){
      vector<int> T = C[i].first;
      int sz = T.size();
      if (C[i].second){
        if ((sz - 1) % 2 == 0){
          int h = (sz - 1) / 2;
          for (int j = 1; j < 1 + h; j++){
            a0.push_back(T[0]);
            a0.push_back(T[j]);
          }
          for (int j = 1 + h; j < sz; j++){
            a1.push_back(T[j]);
            a1.push_back(T[0]);
          }
          for (int j = 0; j < h; j++){
            s0 += "LR";
            s1 += "LR";
          }
          for (int j = 0; j < h * 2; j++){
            t0 += "U";
            t1 += "D";
          }
        } else {
          int h = sz / 2;
          for (int j = 1; j < h; j++){
            a0.push_back(T[0]);
            a0.push_back(T[j]);
          }
          a0.push_back(T[0]);
          for (int j = h; j < sz - 1; j++){
            a1.push_back(T[j]);
            a1.push_back(T[0]);
          }
          a1.push_back(T[sz - 1]);
          s0 += "U";
          s1 += "D";
          for (int j = 0; j < h - 1; j++){
            s0 += "LR";
            s1 += "LR";            
          }
          for (int j = 0; j < h - 1; j++){
            t0 += "LR";
            t1 += "LR";
          }
          t0 += "U";
          t1 += "D";
        }
      } else {
        for (int j = 0; j < sz - 1; j++){
          a0.push_back(T[j]);
        }
        for (int j = 1; j < sz; j++){
          a1.push_back(T[j]);
        }
        if (sz == 3){
          s0 += "LR";
          s1 += "LR";
          t0 += "UU";
          t1 += "DD";
        }
        if (sz == 4){
          s0 += "LRU";
          s1 += "LRD";
          t0 += "ULR";
          t1 += "DLR";
        }
      }
    }
    int h = 2, w = a0.size();
    cout << h << ' ' << w << endl;
    cout << endl;
    for (int i = 0; i < w; i++){
      cout << a0[i] + 1;
      if (i < w - 1){
        cout << ' ';
      }
    }
    cout << endl;
    for (int i = 0; i < w; i++){
      cout << a1[i] + 1;
      if (i < w - 1){
        cout << ' ';
      }
    }
    cout << endl;
    cout << endl;
    cout << s0 << endl;
    cout << s1 << endl;
    cout << endl;
    cout << t0 << endl;
    cout << t1 << endl;
  }
}