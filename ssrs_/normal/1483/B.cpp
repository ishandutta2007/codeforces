#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if (b == 0){
    return a;
  } else {
    return gcd(b, a % b);
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> next(n);
    for (int j = 0; j < n; j++){
      next[j] = (j + 1) % n;
    }
    queue<int> Q;
    for (int j = 0; j < n; j++){
      if (gcd(a[j], a[next[j]]) == 1){
        Q.push(j);
      }
    }
    vector<bool> used(n, false);
    vector<int> ans;
    while (!Q.empty()){
      int v = Q.front();
      Q.pop();
      if (!used[v]){
        ans.push_back(next[v]);
        if (v != next[v]){
          used[next[v]] = true;
          next[v] = next[next[v]];
          if (gcd(a[v], a[next[v]]) == 1){
            Q.push(v);
          }
        }
      }
    }
    int k = ans.size();
    cout << k;
    for (int j = 0; j < k; j++){
      cout << ' ' << ans[j] + 1;
    }
    cout << endl;
  }
}