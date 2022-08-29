#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long psum = 0, nsum = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (a[i] >= 0){
      psum += a[i];
      ans++;
    } else {
      nsum -= a[i];
      ans++;
      pq.push(a[i]);
      while (nsum > psum){
        int x = pq.top();
        pq.pop();
        ans--;
        nsum += x;
      }
    }
  }
  cout << ans << endl;
}