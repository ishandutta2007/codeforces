#include <bits/stdc++.h>
using namespace std;
const int LOG = 21;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string S;
  cin >> S;
  int n = S.size();
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    int k, d;
    cin >> k >> d;
    string T = S;
    for (int j = 0; j <= n - k; j++){
      T += '.';
    }
    int L = n * 2 - k + 1;
    vector<int> p(L);
    for (int j = 0; j < L; j++){
      p[j] = j;
    }
    vector<vector<int>> b(d);
    for (int j = 0; j < k; j++){
      b[j % d].push_back(p[j]);
    }
    vector<int> c;
    for (int j = 0; j < d; j++){
      int cnt = b[j].size();
      for (int l = 0; l < cnt; l++){
        c.push_back(b[j][l]);
      }
    }
    for (int j = 0; j < k; j++){
      p[j] = c[j];
    }
    int f = p[0];
    p.push_back(p[0]);
    p.erase(p.begin());
    vector<vector<int>> pp(LOG, vector<int>(L));
    for (int j = 0; j < L; j++){
      pp[0][j] = p[j];
    }
    for (int j = 1; j < LOG; j++){
      for (int l = 0; l < L; l++){
        pp[j][l] = pp[j - 1][pp[j - 1][l]];
      }
    }
    vector<int> q(L);
    for (int j = 0; j < L; j++){
      q[j] = j;
    }
    for (int j = 0; j < LOG; j++){
      if ((n - k + 1) >> j & 1){
        for (int l = 0; l < L; l++){
          q[l] = pp[j][q[l]];
        }
      }
    }
    vector<int> next(L);
    for (int j = 0; j < L; j++){
      next[q[j]] = j;
    }
    S = "";
    for (int j = L - (n - k + 1); j < L; j++){
      S += T[q[j]];
    }
    for (int j = 0; j < k - 1; j++){
      S += T[q[j]];
    }
    cout << S << "\n";
  }
}