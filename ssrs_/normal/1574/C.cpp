#include <bits/stdc++.h>
using namespace std;
const long long INF = 2000000000000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long s = 0;
  for (int i = 0; i < n; i++){
    s += a[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++){
    long long x, y;
    cin >> x >> y;
    vector<long long> C;
    auto itr1 = lower_bound(a.begin(), a.end(), x);
    if (itr1 != a.end()){
      C.push_back(*itr1);
    }
    if (itr1 != a.begin()){
      C.push_back(*prev(itr1));
    }
    auto itr2 = lower_bound(a.begin(), a.end(), y - s);
    if (itr2 != a.end()){
      C.push_back(*itr2);
    }
    if (itr2 != a.begin()){
      C.push_back(*prev(itr2));
    }
    long long ans = INF;
    for (long long A : C){
      ans = min(ans, max(x - A, (long long) 0) + max(y - s + A, (long long) 0));
    }
    cout << ans << "\n";
  }
}