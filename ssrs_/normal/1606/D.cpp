#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < m; k++){
        cin >> a[j][k];
      }
    }
    vector<pair<int, int>> P(n);
    for (int j = 0; j < n; j++){
      P[j] = make_pair(a[j][0], j);
    }
    sort(P.begin(), P.end());
    vector<vector<int>> b(n, vector<int>(m));
    for (int j = 0; j < n; j++){
      b[j] = a[P[j].second];
    }
    vector<vector<int>> Umn(n + 1, vector<int>(m, INF));
    vector<vector<int>> Umx(n + 1, vector<int>(m, 0));
    for (int j = 0; j < m; j++){
      for (int k = 0; k < n; k++){
        Umn[k + 1][j] = min(Umn[k][j], b[k][j]);
        Umx[k + 1][j] = max(Umx[k][j], b[k][j]);
      }
    }
    vector<vector<int>> Dmn(n + 1, vector<int>(m, INF));
    vector<vector<int>> Dmx(n + 1, vector<int>(m, 0));
    for (int j = 0; j < m; j++){
      for (int k = n - 1; k >= 0; k--){
        Dmn[k][j] = min(Dmn[k + 1][j], b[k][j]);
        Dmx[k][j] = max(Dmx[k + 1][j], b[k][j]);
      }
    }
    bool ok = false;
    for (int j = 0; j < n - 1; j++){
      if (P[j].first != P[j + 1].first){
        vector<int> t(m, -1);
        t[0] = 0;
        for (int k = 1; k < m; k++){
          if (Umn[j + 1][k] > Dmx[j + 1][k]){
            t[k] = 1;
          } else if (Umx[j + 1][k] < Dmn[j + 1][k]){
            t[k] = 0;
          }
        }
        bool ok2 = true;
        for (int k = 0; k < m; k++){
          if (t[k] == -1){
            ok2 = false;
          }
        }
        for (int k = 0; k < m - 1; k++){
          if (t[k] == 1 && t[k + 1] == 0){
            ok2 = false;
          }
        }
        if (t[m - 1] == 0){
          ok2 = false;
        }
        if (ok2){
          int p = -1;
          for (int k = 0; k < m - 1; k++){
            if (t[k] == 0 && t[k + 1] == 1){
              p = k + 1;
            }
          }
          int Lmn = INF, Lmx = 0;
          for (int k = 0; k < p; k++){
            Lmn = min(Lmn, Dmn[j + 1][k]);
            Lmx = max(Lmx, Umx[j + 1][k]);
          }
          int Rmn = INF, Rmx = 0;
          for (int k = p; k < m; k++){
            Rmn = min(Rmn, Umn[j + 1][k]);
            Rmx = max(Rmx, Dmx[j + 1][k]);
          }
          if (Lmn > Lmx && Rmn > Rmx){
            string S(n, '.');
            for (int k = 0; k < n; k++){
              if (k <= j){
                S[P[k].second] = 'B';
              } else {
                S[P[k].second] = 'R';
              }
            }
            cout << "YES" << endl;
            cout << S << ' ' << p << endl;
            ok = true;
            break;
          }
        }
      }
      if (ok){
        break;
      }
    }
    if (!ok){
      cout << "NO" << endl;
    }
  }
}