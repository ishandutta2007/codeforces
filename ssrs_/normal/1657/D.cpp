#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, C;
  cin >> n >> C;
  vector<int> c(n), d(n), h(n);
  for (int i = 0; i < n; i++){
    cin >> c[i] >> d[i] >> h[i];
  }
  int m;
  cin >> m;
  vector<int> D(m);
  vector<long long> H(m);
  for (int i = 0; i < m; i++){
    cin >> D[i] >> H[i];
  }
  vector<long long> mx1(C + 1, 0);
  for (int i = 0; i < n; i++){
    mx1[c[i]] = max(mx1[c[i]], (long long) d[i] * h[i]);
  }
  vector<long long> mx2(C + 1, 0);
  for (int i = 1; i <= C; i++){
    for (int j = i; j <= C; j += i){
      mx2[j] = max(mx2[j], (long long) mx1[i] * (j / i));
    }
  }
  for (int i = 0; i < C; i++){
    mx2[i + 1] = max(mx2[i + 1], mx2[i]);
  }
  for (int i = 0; i < m; i++){
    int p = upper_bound(mx2.begin(), mx2.end(), D[i] * H[i]) - mx2.begin();
    if (p == C + 1){
      cout << -1;
    } else {
      cout << p;
    }
    if (i < m - 1){
      cout << ' ';
    }
  }
  cout << endl;
}