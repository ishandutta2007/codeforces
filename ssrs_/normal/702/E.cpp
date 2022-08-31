#include <bits/stdc++.h>
using namespace std;
int LOG = 40;
long long INF = 1000000000;
int main(){
  int n;
  long long k;
  cin >> n >> k;
  vector<int> f(n);
  for (int i = 0; i < n; i++){
    cin >> f[i];
  }
  vector<long long> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  
  vector<vector<int>> to(n, vector<int>(LOG));
  vector<vector<long long>> sum(n, vector<long long>(LOG));
  vector<vector<long long>> min_w(n, vector<long long>(LOG));
  for (int i = 0; i < n; i++){
    to[i][0] = f[i];
    sum[i][0] = w[i];
    min_w[i][0] = w[i];
  }
  for (int i = 1; i < LOG; i++){
    for (int j = 0; j < n; j++){
      to[j][i] = to[to[j][i - 1]][i - 1];
      sum[j][i] = sum[j][i - 1] + sum[to[j][i - 1]][i - 1];
      min_w[j][i] = min(min_w[j][i - 1], min_w[to[j][i - 1]][i - 1]);
    }
  }
  for (int i = 0; i < n; i++){
    int c;
    c = i;
    long long s = 0;
    for (int j = 0; j < LOG; j++){
      if ((k >> j) & 1){
        s += sum[c][j];
        c = to[c][j];
      }
    }
    c = i;
    long long m = INF;
    for (int j = 0; j < LOG; j++){
      if ((k >> j) & 1){
        m = min(m, min_w[c][j]);
        c = to[c][j];
      }
    }
    cout << s << ' ' << m << endl;
  }
}