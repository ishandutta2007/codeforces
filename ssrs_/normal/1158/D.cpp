#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  string s;
  cin >> s;
  s += 'R';
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    int c = 0;
    if (i == 0){
      c = 1;
    }
    for (int j = 0; j < n; j++){
      if (j != i && j != c){
        long long cross = (x[c] - x[i]) * (y[j] - y[i]) - (y[c] - y[i]) * (x[j] - x[i]);
        if (cross > 0){
          c = j;
        }
      }
    }
    bool ok = true;
    for (int j = 0; j < n; j++){
      if (j != i && j != c){
        long long cross = (x[c] - x[i]) * (y[j] - y[i]) - (y[c] - y[i]) * (x[j] - x[i]);
        if (cross > 0){
          ok = false;
        }
      }
    }
    if (ok){
      p[0] = i;
      break;
    }
  }
  vector<bool> used(n, false);
  used[p[0]] = true;
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n; j++){
      if (!used[j]){
        p[i + 1] = j;
      }
    }
    for (int j = 0; j < n; j++){
      if (!used[j] && j != p[i + 1]){
        long long cross = (x[p[i + 1]] - x[p[i]]) * (y[j] - y[p[i]]) - (y[p[i + 1]] - y[p[i]]) * (x[j] - x[p[i]]);
        if (s[i] == 'L' && cross < 0){
          p[i + 1] = j;
        }
        if (s[i] == 'R' && cross > 0){
          p[i + 1] = j;
        }
      }
    }
    used[p[i + 1]] = true;
  }
  for (int i = 0; i < n; i++){
    cout << p[i] + 1;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}