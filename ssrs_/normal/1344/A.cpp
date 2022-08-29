#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j] += j;
      a[j] += INF;
      a[j] %= n;
    }
    bool flg = true;
    vector<bool> g(n, false);
    for (int j = 0; j < n; j++){
      if (g[a[j]]){
        flg = false;
      } else {
        g[a[j]] = true;
      }
    }
    if (flg){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}