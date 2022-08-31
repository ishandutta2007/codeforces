#include <bits/stdc++.h>
using namespace std;
long long BASE1, BASE2;
const long long MOD = 998244353;
long long modpow(long long a, long long b){
  long long ans = 1;
  while (b > 0){
    if (b % 2 == 1){
      ans *= a;
      ans %= MOD;
    }
    a *= a;
    a %= MOD;
    b /= 2;
  }
  return ans;
}
long long modinv(long long a){
  return modpow(a, MOD - 2);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  random_device rnd;
  mt19937 mt(rnd());
  long long BASE1 = mt() % 1000000 + 1000000;
  long long BASE2 = mt() % 1000000 + 2000000;
  long long INV1 = modinv(BASE1);
  long long INV2 = modinv(BASE2);
  int MAX = 1000000;
  vector<long long> POW1(MAX);
  POW1[0] = 1;
  for (int i = 1; i < MAX; i++){
    POW1[i] = POW1[i - 1] * BASE1 % MOD;
  }
  vector<long long> POW2(MAX);
  POW2[0] = 1;
  for (int i = 1; i < MAX; i++){
    POW2[i] = POW2[i - 1] * BASE2 % MOD;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool c = false;
    if (k <= 20){
      if (n >= (1 << k) + k - 1){
        c = true;
      }
    }
    if (c){
      vector<bool> used(1 << k, false);
      int sum = 0;
      for (int j = 0; j < k; j++){
        if (s[j] == '1'){
          sum += 1 << (k - 1 - j);
        }
      }
      used[sum] = true;
      for (int j = k; j < n; j++){
        if (s[j - k] == '1'){
          sum -= 1 << (k - 1);
        }
        sum *= 2;
        if (s[j] == '1'){
          sum++;
        }
        used[sum] = true;
      }
      bool ok = false;
      for (int j = (1 << k) - 1; j >= 0; j--){
        if (!used[j]){
          ok = true;
          cout << "YES" << endl;
          for (int l = k - 1; l >= 0; l--){
            if (j >> l & 1){
              cout << '0';
            } else {
              cout << '1';
            }
          }
          cout << endl;
          break;
        }
      }
      if (!ok){
        cout << "NO" << endl;
      }
    } else {
      long long sum1 = 0, sum2 = 0;
      for (int j = k - 1; j >= 0; j--){
        sum1 *= BASE1;
        sum2 *= BASE2;
        if (s[j] == '1'){
          sum1++;
          sum2++;
        }
        sum1 %= MOD;
        sum2 %= MOD;
      }
      set<pair<long long, long long>> st;
      st.insert(make_pair(sum1, sum2));
      for (int j = k; j < n; j++){
        if (s[j - k] == '1'){
          sum1 += MOD - 1;
          sum2 += MOD - 1;
        }
        sum1 *= INV1;
        sum2 *= INV2;
        if (s[j] == '1'){
          sum1 += POW1[k - 1];
          sum2 += POW2[k - 1];
        }
        sum1 %= MOD;
        sum2 %= MOD;
        st.insert(make_pair(sum1, sum2));
      }
      int cnt = 0;
      string s(k, '0');
      long long sum3 = 0, sum4 = 0;
      for (int j = 0; j < k; j++){
        sum3 += POW1[j];
        sum4 += POW2[j];
      }
      sum3 %= MOD;
      sum4 %= MOD;
      while (1){
        if (!st.count(make_pair(sum3, sum4))){
          cout << "YES" << endl;
          cout << s << endl;
          break;
        }
        while (s.back() == '1'){
          s.pop_back();
        }
        s.back() = '1';
        sum3 += MOD - POW1[s.size() - 1];
        sum4 += MOD - POW2[s.size() - 1];
        while (s.size() < k){
          sum3 += POW1[s.size()];
          sum4 += POW2[s.size()];
          s.push_back('0');
        }
        sum3 %= MOD;
        sum4 %= MOD;
      }
    }
  }
}