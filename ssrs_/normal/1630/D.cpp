#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int gcd(int x, int y){
  if (y == 0){
    return x;
  } else {
    return gcd(y, x % y);
  }
}
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
    vector<int> b(m);
    for (int j = 0; j < m; j++){
      cin >> b[j];
    }
    int g = 0;
    for (int j = 0; j < m; j++){
      g = gcd(g, b[j]);
    }
    long long sum = 0;
    for (int j = 0; j < n; j++){
      sum += abs(a[j]);
    }
    vector<int> cnt(g, 0);
    for (int j = 0; j < n; j++){
      if (a[j] < 0){
        cnt[j % g]++;
      }
    }
    vector<int> mn(g, INF);
    for (int j = 0; j < n; j++){
      mn[j % g] = min(mn[j % g], abs(a[j]));
    }
    long long m1 = 0, m2 = 0;
    for (int j = 0; j < g; j++){
      if (cnt[j] % 2 == 0){
        m1 += mn[j];
      } else {
        m2 += mn[j];
      }
    }
    cout << sum - min(m1, m2) * 2 << "\n";
  }
}