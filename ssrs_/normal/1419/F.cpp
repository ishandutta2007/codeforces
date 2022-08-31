#include <bits/stdc++.h>
using namespace std;
const long long INF = 2100000000;
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  map<int, vector<pair<int, int>>> H;
  for (int i = 0; i < n; i++){
    H[y[i]].push_back(make_pair(x[i], i));
  }
  vector<int> L(n, -1), R(n, -1);
  for (auto &P : H){
    int cnt = P.second.size();
    sort(P.second.begin(), P.second.end());
    for (int i = 0; i < cnt - 1; i++){
      int a = P.second[i].second;
      int b = P.second[i + 1].second;
      L[b] = a;
      R[a] = b;
    }
  }
  map<int, vector<pair<int, int>>> V;
  for (int i = 0; i < n; i++){
    V[x[i]].push_back(make_pair(y[i], i));
  }
  vector<int> U(n, -1), D(n, -1);
  for (auto &P : V){
    int cnt = P.second.size();
    sort(P.second.begin(), P.second.end());
    for (int i = 0; i < cnt - 1; i++){
      int a = P.second[i].second;
      int b = P.second[i + 1].second;
      D[b] = a;
      U[a] = b;
    }
  }
  long long tv = INF;
  long long fv = 0;
  vector<int> id;
  while (tv - fv > 1){
    long long mid = (tv + fv) / 2;
    vector<vector<int>> E(n);
    for (int i = 0; i < n; i++){
      if (L[i] != -1){
        if (x[i] - x[L[i]] <= mid){
          E[i].push_back(L[i]);
        }
      }
      if (R[i] != -1){
        if (x[R[i]] - x[i] <= mid){
          E[i].push_back(R[i]);
        }
      }
      if (D[i] != -1){
        if (y[i] - y[D[i]] <= mid){
          E[i].push_back(D[i]);
        }
      }
      if (U[i] != -1){
        if (y[U[i]] - y[i] <= mid){
          E[i].push_back(U[i]);
        }
      }
    }
    int cnt = 0;
    vector<int> cc(n, -1);
    for (int i = 0; i < n; i++){
      if (cc[i] == -1){
        cc[i] = cnt;
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          for (int w : E[v]){
            if (cc[w] == -1){
              cc[w] = cnt;
              Q.push(w);
            }
          }
        }
        cnt++;
      }
    }
    bool ok = false;
    if (cnt == 1){
      ok = true;
    } else if (cnt <= 4){
      for (int i = 0; i < n; i++){
        if (ok){
          break;
        }
        for (int j = 0; j < n; j++){
          if (ok){
            break;
          }
          if (x[i] == x[j]){
            if (abs(y[j] - y[i]) <= mid * 2 && cnt == 2 && cc[i] != cc[j]){
              ok = true;
            }
          } else if (y[i] == y[j]){
            if (abs(x[j] - x[i]) <= mid * 2 && cnt == 2 && cc[i] != cc[j]){
              ok = true;
            }
          } else if (abs(x[j] - x[i]) <= mid && abs(y[j] - y[i]) <= mid){
            int x1 = x[i], y1 = y[j];
            int a;
            if (y1 < y[i]){
              a = D[i];
            } else {
              a = U[i];
            }
            int b;
            if (x1 < x[j]){
              b = L[j];
            } else {
              b = R[j];
            }
            id.clear();
            id.reserve(4);
            id.emplace_back(cc[i]);
            id.emplace_back(cc[j]);
            if (a != -1){
              if (abs(y1 - y[a]) <= mid){
                id.emplace_back(cc[a]);
              }
            }
            if (b != -1){
              if (abs(x1 - x[b]) <= mid){
                id.emplace_back(cc[b]);
              }
            }
            sort(id.begin(), id.end());
            int tmp = 1;
            for (int k = 0; k < id.size() - 1; k++){
              if (id[k] != id[k + 1]){
                tmp++;
              }
            }
            if (tmp == cnt){
              ok = true;
            }
          }
        }
      }
    }
    if (ok){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  if (tv == INF){
    cout << -1 << endl;
  } else {
    cout << tv << endl;
  }
}