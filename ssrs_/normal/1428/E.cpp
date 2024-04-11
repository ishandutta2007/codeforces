#include <bits/stdc++.h>
using namespace std;
long long f(long long A, int N){
  long long q = A / N;
  long long r = A % N;
  return (q + 1) * (q + 1) * r + q * q * (N - r);
}
int main(){
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += a[i] * a[i];
  }
  priority_queue<tuple<long long, int, int>> pq;
  for (int i = 0; i < n; i++){
    if (a[i] > 1){
      pq.push(make_tuple(f(a[i], 1) - f(a[i], 2), a[i], 1));
    }
  }
  for (int i = 0; i < k - n; i++){
    long long sub = get<0>(pq.top());
    int num = get<1>(pq.top());
    int parts = get<2>(pq.top());
    pq.pop();
    ans -= sub;
    if (parts + 1 < num){
      long long sub2 = f(num, parts + 1) - f(num, parts + 2);
      pq.push(make_tuple(sub2, num, parts + 1));
    }
  }
  cout << ans << endl;
}