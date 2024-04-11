#include <bits/stdc++.h>
using namespace std;
long long INF = 3000000000000000000;
long long cost(long long x, long long y, long long z){
  return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    int N = nr + ng + nb;
    vector<long long> r(nr);
    for (int j = 0; j < nr; j++){
      cin >> r[j];
    }
    vector<long long> g(ng);
    for (int j = 0; j < ng; j++){
      cin >> g[j];
    }
    vector<long long> b(nb);
    for (int j = 0; j < nb; j++){
      cin >> b[j];
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    map<int, array<int, 3>> v;
    for (int j : r){
      v[j][0]++;
    }
    for (int j : g){
      v[j][1]++;
    }
    for (int j : b){
      v[j][2]++;
    }
    vector<array<int, 4>> V;
    for (auto P : v){
      V.push_back(array<int, 4>{P.first, P.second[0], P.second[1], P.second[2]});
    }
    int M = V.size();
    long long res = INF;
    vector<pair<long long, long long>> pos;
    array<int, 3> C;
    C[0] = 0;
    C[1] = 0;
    C[2] = 0;
    int R = 0;
    for (int L = 0; L < M; L++){
      while (R < M){
        if (C[0] > 0 && C[1] > 0 && C[2] > 0){
          break;
        }
        C[0] += V[R][1];
        C[1] += V[R][2];
        C[2] += V[R][3];
        R++;
      }
      if (C[0] == 0 || C[1] == 0 || C[2] == 0){
        break;
      }
      if (!pos.empty()){
        if (pos.back().second == V[R - 1][0]){
          pos.pop_back();
        }
      }
      pos.push_back(make_pair(V[L][0], V[R - 1][0]));
      if (L == R){
        R++;
      } else {
        C[0] -= V[L][1];
        C[1] -= V[L][2];
        C[2] -= V[L][3];
      }
    }
    int K = pos.size();
    long long ans = INF;
    for (int j = 0; j < K; j++){
      long long left = pos[j].first;
      long long right = pos[j].second;
      if ((v[left][0] > 0 && v[right][1] > 0) || (v[left][1] > 0 && v[right][0] > 0)){
        //RBG or GBR
        auto itr1 = lower_bound(b.begin(), b.end(), left);
        auto itr2 = upper_bound(b.begin(), b.end(), right);
        for (auto itr = itr1; itr < itr2; itr++){
          long long z = *itr;
          ans = min(ans, cost(left, z, right));
        }
      }
      if ((v[left][1] > 0 && v[right][2] > 0) || (v[left][2] > 0 && v[right][1] > 0)){
        //GRB or BRG
        auto itr1 = lower_bound(r.begin(), r.end(), left);
        auto itr2 = upper_bound(r.begin(), r.end(), right);
        for (auto itr = itr1; itr < itr2; itr++){
          long long x = *itr;
          ans = min(ans, cost(left, x, right));
        }
      }
      if ((v[left][2] > 0 && v[right][0] > 0) || (v[left][0] > 0 && v[right][2] > 0)){
        //BGR or RGB
        auto itr1 = lower_bound(g.begin(), g.end(), left);
        auto itr2 = upper_bound(g.begin(), g.end(), right);
        for (auto itr = itr1; itr < itr2; itr++){
          long long y = *itr;
          ans = min(ans, cost(left, y, right));
        }
      }
    }
    cout << ans << endl;
  }
}