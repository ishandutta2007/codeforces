#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> x(k), y(k);
  for (int i = 0; i < k; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<int> cntx(n, 0), cnty(n, 0);
  for (int i = 0; i < k; i++){
    cntx[x[i]]++;
    cnty[y[i]]++;
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    if (cntx[i] > 1){
      ok = false;
    }
    if (cnty[i] > 1){
      ok = false;
    }
  }
  if (!ok){
    cout << 0 << endl;
  } else {
    vector<int> yy(n, -1);
    for (int i = 0; i < k; i++){
      yy[x[i]] = y[i];
    }
    vector<vector<int>> E1(n);
    for (int i = 0; i < k; i++){
      E1[x[i]].push_back(y[i]);
      E1[y[i]].push_back(x[i]);
    }
    vector<int> id(n, -1);
    vector<vector<int>> pe;
    int cnt = 0;
    for (int i = 0; i < n; i++){
      if (id[i] == -1){
        id[i] = cnt;
        vector<int> cc;
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          cc.push_back(v);
          for (int w : E1[v]){
            if (id[w] == -1){
              id[w] = cnt;
              Q.push(w);
            }
          }
        }
        int s = cc.size();
        int b = -1;
        for (int j = 0; j < s; j++){
          if (cnty[cc[j]] == 0){
            b = cc[j];
          }
        }
        if (b == -1){
          ok = false;
          break;
        }
        vector<int> ne;
        ne.push_back(b);
        while (yy[ne.back()] != -1){
          int t = yy[ne.back()];
          ne.push_back(t);
        }
        int sz = ne.size();
        set<int> st;
        for (int j = sz - 1; j >= 0; j--){
          if (st.count(p[ne[j]])){
            ok = false;
            break;
          }
          st.insert(ne[j]);
        }
        if (!ok){
          break;
        }
        pe.push_back(ne);
        cnt++;
      }
    }
    if (!ok){
      cout << 0 << endl;
    } else {
      vector<vector<int>> E2(cnt);
      for (int i = 0; i < n; i++){
        if (p[i] != -1){
          if (id[i] != id[p[i]]){
            E2[id[p[i]]].push_back(id[i]);
          }
        }
      }
      vector<int> d(cnt, 0);
      for (int i = 0; i < cnt; i++){
        for (int j : E2[i]){
          d[j]++;
        }
      }
      queue<int> Q;
      for (int i = 0; i < cnt; i++){
        if (d[i] == 0){
          Q.push(i);
        }
      }
      vector<int> ans;
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : pe[v]){
          ans.push_back(w);
        }
        for (int w : E2[v]){
          d[w]--;
          if (d[w] == 0){
            Q.push(w);
          }
        }
      }
      for (int i = 0; i < cnt; i++){
        if (d[i] > 0){
          ok = false;
        }
      }
      if (!ok){
        cout << 0 << endl;
      } else {
        for (int i = 0; i < n; i++){
          cout << ans[i] + 1;
          if (i < n - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}