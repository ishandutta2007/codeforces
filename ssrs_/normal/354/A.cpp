#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
int main(){
  int n, l, r, Ql, Qr;
  cin >> n >> l >> r >> Ql >> Qr;
  vector<int> w(n);
  for (int i = 0; i < n; i++){
    cin >> w[i];
  }
  vector<int> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + w[i];
  }
  int ans = INF;
  for (int i = 0; i <= n; i++){
    int sum = 0;
    sum += S[i] * l + (S[n] - S[i]) * r;
    int lcnt = i, rcnt = n - i;
    if (rcnt - lcnt > 1){
      sum += Qr * (rcnt - lcnt - 1);
    }
    if (lcnt - rcnt > 1){
      sum += Ql * (lcnt - rcnt - 1);
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;
}