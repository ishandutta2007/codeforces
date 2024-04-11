#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];    
  }
  sort(p.begin(), p.end());
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + p[i];
  }
  for (int i = 0; i < q; i++){
    int x, y;
    cin >> x >> y;
    cout << S[n - (x - y)] - S[n - x] << "\n";
  }
}