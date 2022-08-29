#include <bits/stdc++.h>
using namespace std;
const double eps = 0.00000001;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> k(m);
    vector<vector<int>> b(m);
    for (int j = 0; j < m; j++){
      cin >> k[j];
      b[j] = vector<int>(k[j]);
      for (int l = 0; l < k[j]; l++){
        cin >> b[j][l];
      }
    }
    sort(a.begin(), a.end(), greater<int>());
    a.resize(m);
    reverse(a.begin(), a.end());
    vector<pair<double, int>> P(m);
    for (int j = 0; j < m; j++){
      P[j].first = 0;
      P[j].second = j;
      for (int l = 0; l < k[j]; l++){
        P[j].first += b[j][l];
      }
      P[j].first /= k[j];
    }
    sort(P.begin(), P.end());
    vector<bool> ok(m, true), ok_next(m, true), ok_prev(m, true);
    for (int j = 0; j < m; j++){
      if (a[j] < P[j].first - eps){
        ok[j] = false;
      }
      if (j < m - 1){
        if (a[j + 1] < P[j].first - eps){
          ok_next[j] = false;
        }
      }
      if (j > 0){
        if (a[j - 1] < P[j].first - eps){
          ok_prev[j] = false;
        }
      }
    }
    vector<int> S(m + 1), S_next(m + 1), S_prev(m + 1);
    S[0] = 0;
    S_next[0] = 0;
    S_prev[0] = 0;
    for (int j = 0; j < m; j++){
      S[j + 1] = S[j];
      S_next[j + 1] = S_next[j];
      S_prev[j + 1] = S_prev[j];
      if (!ok[j]){
        S[j + 1]++;
      }
      if (!ok_next[j]){
        S_next[j + 1]++;
      }
      if (!ok_prev[j]){
        S_prev[j + 1]++;
      }
    }
    vector<int> pos(m);
    for (int j = 0; j < m; j++){
      pos[P[j].second] = j;
    }
    string ans;
    for (int j = 0; j < m; j++){
      double sum = 0;
      for (int l = 0; l < k[j]; l++){
        sum += b[j][l];
      }
      for (int l = 0; l < k[j]; l++){
        double avg = (sum - b[j][l]) / (k[j] - 1);
        int pos2 = lower_bound(P.begin(), P.end(), make_pair(avg, -1)) - P.begin();
        bool res = true;
        if (pos2 <= pos[j]){
          if (S[pos2] > 0){
            res = false;
          }
          if (S_next[pos[j]] - S_next[pos2] > 0){
            res = false;
          }
          if (S[m] - S[pos[j] + 1] > 0){
            res = false;
          }
          if (a[pos2] < avg - eps){
            res = false;
          }
        } else {
          if (S[pos[j]] > 0){
            res = false;
          }
          if (S_prev[pos2] - S_prev[pos[j] + 1] > 0){
            res = false;
          }
          if (S[m] - S[pos2] > 0){
            res = false;
          }
          if (a[pos2 - 1] < avg - eps){
            res = false;
          }
        }
        if (res){
          cout << '1';
        } else {
          cout << '0';
        }
      }
    }
    cout << endl;
  }
}