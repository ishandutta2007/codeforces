#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000001;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += c[i];
  }
  int tv = INF;
  int fv = sum / n - 1;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    long long sum2 = 0;
    for (int i = 0; i < n; i++){
      sum2 += max(c[i] - mid, 0);
    }
    if (sum2 <= k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  int tv2 = 0;
  int fv2 = sum / n + 1;
  while (fv2 - tv2 > 1){
    int mid = (tv2 + fv2) / 2;
    long long sum2 = 0;
    for (int i = 0; i < n; i++){
      sum2 += max(mid - c[i], 0);
    }
    if (sum2 <= k){
      tv2 = mid;
    } else {
      fv2 = mid;
    }
  }
  if (tv == tv2){
    if (sum % n == 0){
      cout << 0 << endl;
    } else {
      cout << 1 << endl;
    }
  } else {
    cout << tv - tv2 << endl;
  }
}