#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> v[i][j];
      v[i][j]--;
    }
  }
  vector<int> x(n * n), y(n * n);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      x[v[i][j]] = i;
      y[v[i][j]] = j;
    }
  }
  vector<int> s(n * n), d(n * n);
  for (int i = 0; i < n * n; i++){
    s[i] = x[i] + y[i];
    d[i] = x[i] - y[i];
  }
  vector<vector<char>> c(n, vector<char>(n));
  int smx = s[n * n - 1];
  int smn = s[n * n - 1];
  int dmx = d[n * n - 1];
  int dmn = d[n * n - 1];
  c[x[n * n - 1]][y[n * n - 1]] = 'M';
  for (int i = n * n - 2; i >= 0; i--){
    int dist = 0;
    dist = max(dist, abs(smx - s[i]));
    dist = max(dist, abs(smn - s[i]));
    dist = max(dist, abs(dmx - d[i]));
    dist = max(dist, abs(dmn - d[i]));
    if (dist > k){
      c[x[i]][y[i]] = 'G';
    } else {
      c[x[i]][y[i]] = 'M';
      smx = max(smx, s[i]);
      smn = min(smn, s[i]);
      dmx = max(dmx, d[i]);
      dmn = min(dmn, d[i]);
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cout << c[i][j];
    }
    cout << endl;
  }
}