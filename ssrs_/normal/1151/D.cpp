#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<tuple<long long, long long, long long>> P(n);
  for (int i = 0; i < n; i++){
    long long a, b;
    cin >> a >> b;
    P[i] = make_tuple(a - b, a, b);
  }
  sort(P.begin(), P.end());
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += (n - i - 1) * get<1>(P[i]) + i * get<2>(P[i]);
  }
  cout << ans << endl;
}