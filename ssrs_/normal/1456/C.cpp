#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  sort(c.rbegin(), c.rend());
  priority_queue<long long> pq;
  for (int i = 0; i <= k; i++){
    pq.push(0);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    long long t = pq.top();
    pq.pop();
    sum += t;
    pq.push(t + c[i]);
  }
  cout << sum << endl;
}