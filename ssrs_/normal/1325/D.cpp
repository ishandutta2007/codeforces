#include <bits/stdc++.h>
using namespace std;
const int INF = 100000;
vector<int> bit(long long x, int n){
  vector<int> res;
  for (int i = 0; i < n; i++){
    res.push_back(x % 2);
    x /= 2;
    if (n == INF && x == 0) break;
  }
  if (n == INF) res.push_back(0);
  reverse(res.begin(), res.end());
  return res;
}
int main(){
  long long u, v;
  cin >> u >> v;
  if (u > v || (v - u) % 2 == 1){
    cout << -1;
  } else if (u == 0 && v == 0){
    cout << 0 << endl;
  } else if (u == v){
    cout << 1 << endl;
    cout << u << endl;
  } else {
    long long d = v - u;
    vector<int> V = bit(v, INF);
    int L = V.size();
    vector<int> U = bit(u, L);
    vector<int> D = bit(d, L);
    bool flg = true;
    for (int i = L - 1; i > 0; i--){
      if (U[i] == 1 && D[i - 1] == 1){
        flg = false;
      }
    }
    if (flg){
      cout << 2 << endl;
      cout << d / 2 << ' ' << d / 2 + u << endl;
    } else {
      cout << 3 << endl;
      cout << d / 2 << ' ' << d / 2 << ' ' << u << endl;
    }
  }
}