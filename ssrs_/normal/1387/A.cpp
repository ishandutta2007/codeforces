#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(20);
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < M; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a].push_back(make_pair(c, b));
    E[b].push_back(make_pair(c, a));
  }
  vector<double> ans(N);
  vector<pair<int, int>> f(N);
  vector<bool> used(N, false);
  bool ok = true;
  for (int i = 0; i < N; i++){
    if (!used[i]){
      used[i] = true;
      vector<int> v_id; //vertices in connected-component
      v_id.push_back(i);
      f[i] = make_pair(1, 0); //f_i(x)=x
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (auto P : E[v]){
          int s = P.first;
          int w = P.second;
          if (!used[w]){
            used[w] = true;
            f[w] = make_pair(- f[v].first, s - f[v].second);
            v_id.push_back(w);
            Q.push(w);
          }
        }
      }
      bool x_unique = false;
      int x_val2; //value of x*2
      for (int v : v_id){
        for (auto P : E[v]){
          int s = P.first;
          int w = P.second;
          int a = f[v].first + f[w].first;
          int b = f[v].second + f[w].second;
          if (a == 0){
            if (b != s){
              ok = false;
              break;
            }
          }
          if (a == 2){
            //2x+b=s
            if (!x_unique){
              x_val2 = s - b;
              x_unique = true;
            } else if (x_val2 != s - b){
              ok = false;
              break;
            }
          }
          if (a == -2){
            //-2x+b=s
            if (!x_unique){
              x_val2 = b - s;
              x_unique = true;
            } else if (x_val2 != b - s){
              ok = false;
              break;
            }
          }
        }
      }
      if (!ok){
        break;
      }
      if (x_unique){
        for (int v : v_id){
          ans[v] = f[v].first * (double) x_val2 / 2 + f[v].second;
        }
      } else {
        vector<int> b_vals;
        for (int v : v_id){
          if (f[v].first == 1){
            //|x+b|
            b_vals.push_back(- f[v].second);
          } else {
            //|-x+b|=|x-b|
            b_vals.push_back(f[v].second);
          }
        }
        //take median
        int sz = b_vals.size();
        sort(b_vals.begin(), b_vals.end());
        double x;
        if (sz % 2 == 1){
          x = b_vals[sz / 2];
        } else {
          x = (double) (b_vals[sz / 2 - 1] + b_vals[sz / 2]) / 2;
        }
        for (int v : v_id){
          ans[v] = f[v].first * x + f[v].second;
        }
      }
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < N; i++){
      cout << ans[i];
      if (i < N - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}