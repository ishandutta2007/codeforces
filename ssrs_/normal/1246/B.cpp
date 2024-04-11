#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> pre(100001, 1);
  for (int i = 2; i <= 100000; i++){
    int tmp = i;
    for (int j = 2; j * j <= i; j++){
      if (tmp % j == 0){
        int cnt = 0;
        while (tmp % j == 0){
          cnt++;
          tmp /= j;
        }
        cnt = cnt / k * k;
        for (int l = 0; l < cnt; l++){
          pre[i] *= j;
        }
      }
    }
  }
  for (int i = 2; i * i <= 100000; i++){
    int p = 1;
    for (int j = 0; j < k; j++){
      p *= i;
      if (p > 100000){
        break;
      }
    }
    if (p > 100000){
      break;
    }
    if (pre[p] == 1){
      for (int j = p; j <= 100000; j += p){
        pre[j] *= p;
      }
    }
  }
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i] /= pre[a[i]];
  }
  map<int, int> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]]++;
  }
  long long ans = (long long) mp[1] * (mp[1] - 1) / 2;
  for (int i = 0; i < n; i++){
    if (a[i] != 1){
      int tmp = a[i];
      long long b = 1;
      for (int j = 2; j * j <= tmp; j++){
        if (tmp % j == 0){
          int cnt = 0;
          while (tmp % j == 0){
            tmp /= j;
            cnt++;
          }
          for (int l = 0; l < k - cnt; l++){
            b *= j;
            if (b > 100000){
              b = 0;
              break;
            }
          }
        }
      }
      if (tmp > 1){
        for (int j = 0; j < k - 1; j++){
          b *= tmp;
          if (b > 100000){
            b = 0;
            break;
          }
        }
      }
      mp[a[i]]--;
      ans += mp[b];
    }
  }
  cout << ans << endl;
}