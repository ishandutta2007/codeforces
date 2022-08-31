#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin >> n;
  vector<int> mf(n + 1, -1);
  vector<int> mobius(n + 1, 1);
  mobius[0] = 0;
  mobius[1] = 0;
  for (int i = 2; i <= n; i++){
    if (mf[i] == -1){
      mf[i] = i;
      mobius[i] = -1;
      for (int j = i * 2; j <= n; j += i){
        if (mf[j] == -1){
          mf[j] = i;
        }
        mobius[j] *= -1;
      }
    }
  }
  for (int i = 2; i * i <= n; i++){
    for (int j = i * i; j <= n; j += i * i){
      mobius[j] = 0;
    }
  }
  long long ans1 = 0;
  for (int i = 2; i <= n; i++){
    ans1 -= (long long) (n / i) * (n / i) * mobius[i];
    ans1--;
  }
  vector<long long> mfcnt(n + 1, 0);
  for (int i = 2; i <= n; i++){
    mfcnt[mf[i]]++;
  }
  vector<long long> mfsum(n + 2, 0);
  for (int i = 0; i <= n; i++){
    mfsum[i + 1] = mfsum[i] + mfcnt[i];
  }
  long long ans2 = 0;
  for (int i = 2; i <= n; i++){
    ans2 += mfcnt[i] * max(mfsum[n / i + 1] - mfsum[i + 1], (long long) 0);
  }
  ans2 *= 2;
  for (int i = 2; i <= n; i++){
    ans2 += mfcnt[i] * mfcnt[i];
  }
  ans2 -= ans1;
  ans2 -= n - 1;
  long long tmp = n - 1;
  for (int i = n / 2 + 1; i <= n; i++){
    if (mf[i] == i){
      tmp--;
    }
  }
  long long ansinf = n * n - tmp * tmp - (n - tmp);
  long long ans3 = n * (n - 1) - ans1 - ans2 - ansinf;
  long long ans = (ans1 + ans2 * 2 + ans3 * 3) / 2;
  cout << ans << endl;  
}