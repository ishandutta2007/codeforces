#include <bits/stdc++.h>
using namespace std;
const int LOG = 19;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q, a0, c0;
  cin >> q >> a0 >> c0;
  vector<int> A(1), C(1);
  A[0] = a0;
  C[0] = c0;
  int N = 1;
  vector<int> d(1, 0);
  vector<int> P(1, -1);
  vector<vector<int>> pp(LOG, vector<int>(1, -1));
  vector<int> id(q + 1, -1);
  id[0] = 0;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      id[i + 1] = N;
      int p, a, c;
      cin >> p >> a >> c;
      p = id[p];
      P.push_back(p);
      A.push_back(a);
      C.push_back(c);
      int d2 = d[p] + 1;
      d.push_back(d2);
      pp[0].push_back(p);
      for (int j = 0; j < LOG - 1; j++){
        if (pp[j][N] == -1){
          pp[j + 1].push_back(-1);
        } else {
          pp[j + 1].push_back(pp[j][pp[j][N]]);
        }
      }
      N++;
    }
    if (t == 2){
      int v, w;
      cin >> v >> w;
      v = id[v];
      if (A[v] == 0){
        cout << 0 << ' ' << 0 << endl;
      } else {
        int p = v;
        for (int j = LOG - 1; j >= 0; j--){
          int p2 = pp[j][p];
          if (p2 != -1){
            if (A[p2] > 0){
              p = p2;
            }
          }
        }
        int D = d[v] - d[p];
        int ans1 = 0;
        long long ans2 = 0;
        for (int j = D; j >= 0; j--){
          int v2 = v;
          for (int k = 0; k < LOG; k++){
            if ((j >> k & 1) == 1){
              v2 = pp[k][v2];
            }
          }
          int a = min(A[v2], w);
          ans1 += a;
          ans2 += (long long) C[v2] * a;
          w -= a;
          A[v2] -= a;
          if (w == 0){
            break;
          }
        }
        cout << ans1 << ' ' << ans2 << endl;
      }
    }
  }
}