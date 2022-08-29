#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long x;
  cin >> n >> x;
  vector<long long> d(n * 2);
  for (int i = 0; i < n; i++){
    cin >> d[i];
    d[n + i] = d[i];
  }
  vector<long long> S(n * 2 + 1, 0);
  for (int i = 0; i < n * 2; i++){
    S[i + 1] = S[i] + d[i];
  }
  vector<long long> HS(n * 2 + 1, 0);
  for (int i = 0; i < n * 2; i++){
    HS[i + 1] = HS[i] + d[i] * (d[i] + 1) / 2;
  }
  long long ans = 0;
  for (int i = 0; i <= n; i++){
    long long s = S[n + i] - x;
    //cout << "s = " << s << endl;
    auto itr = lower_bound(S.begin(), S.end(), s);
    //cout << "start = " << (*itr) << endl;
    //cout << "month = " << itr - S.begin() << endl;
    //cout << "total 1 = " << HS[n + i] - HS[itr - S.begin()] << endl;
    long long tot1 = HS[n + i] - HS[itr - S.begin()];
    //cout << "remaing = " << S[itr - S.begin()] - s << endl;
    //cout << "last = " << d[itr - S.begin() - 1] << endl;
    long long rem = S[itr - S.begin()] - s;
    long long last = d[itr - S.begin() - 1];
    //cout << "tot2 = " << (2 * last - rem + 1) * rem / 2 << endl;
    long long tot2 = (2 * last - rem + 1) * rem / 2;
    //cout << "tot = " << tot1 + tot2 << endl;
    ans = max(ans, tot1 + tot2);
  }
  cout << ans << endl;
}