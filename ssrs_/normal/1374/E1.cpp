#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000;
int main(){
  int n, k;
  cin >> n >> k;
  vector<long long> t(n), a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> t[i] >> a[i] >> b[i];
  }
  int cnt_a = 0, cnt_b = 0;
  for (int i = 0; i < n; i++){
    cnt_a += a[i];
    cnt_b += b[i];
  }
  if (cnt_a < k || cnt_b < k){
    cout << -1 << endl;
  } else {
    vector<long long> both;
    vector<long long> alice;
    vector<long long> bob;
    for (int i = 0; i < n; i++){
      if (a[i] == 1 && b[i] == 1){
        both.push_back(t[i]);
      } else if (a[i] == 1){
        alice.push_back(t[i]);
      } else if (b[i] == 1){
        bob.push_back(t[i]);
      }
    }
    sort(both.begin(), both.end());
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());
    vector<long long> T;
    for (int i : both){
      T.push_back(i);
    }
    int c = min(alice.size(), bob.size());
    for (int i = 0; i < c; i++){
      T.push_back(alice[i] + bob[i]);
    }
    sort(T.begin(), T.end());
    long long ans = 0;
    for (int i = 0; i < k; i++){
      ans += T[i];
    }
    cout << ans << endl;
  }
}