#include <bits/stdc++.h>
using namespace std;
long long INF = 2000000000;
int main(){
  int w, l;
  cin >> w >> l;
  vector<int> a(w - 1);
  for (int i = 0; i < w - 1; i++){
    cin >> a[i];
  }
  vector<long long> S(w, 0);
  for (int i = 0; i < w - 1; i++){
    S[i + 1] = S[i] + a[i];
  }
  long long ans = INF;
  for (int i = 0; i < w - l; i++){
    ans = min(ans, S[i + l] - S[i]);
  }
  cout << ans << endl;
}