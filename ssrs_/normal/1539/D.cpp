#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  vector<pair<long long, long long>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(b[i], a[i]);
  }
  sort(P.begin(), P.end(), greater<pair<long long, long long>>());
  for (int i = 0; i < n; i++){
    a[i] = P[i].second;
    b[i] = P[i].first;
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += a[i];
  }
  long long ans = sum * 2;
  long long R = sum;
  for (int i = 0; i < n; i++){
    if (b[i] < R){
      long long p = min(a[i], R - b[i]);
      R -= p;
      ans -= p;
    }
  }
  cout << ans << endl;
}