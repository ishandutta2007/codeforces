#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> ca(n);
    for (int j = 0; j < n; j++){
      cin >> ca[j];
      ca[j]--;
    }
    vector<int> cb(n);
    for (int j = 0; j < n; j++){
      cin >> cb[j];
      cb[j]--;
    }
    vector<vector<int>> E(n);
    for (int j = 0; j < n; j++){
      E[ca[j]].push_back(cb[j]);
      E[cb[j]].push_back(ca[j]);
    }
    vector<bool> used(n, false);
    int cnt = 0;
    for (int j = 0; j < n; j++){
      if (!used[j]){
        used[j] = true;
        int V = 0;
        queue<int> Q;
        Q.push(j);
        while (!Q.empty()){
          int v = Q.front();
          Q.pop();
          V++;
          for (int w : E[v]){
            if (!used[w]){
              used[w] = true;
              Q.push(w);
            }
          }
        }
        cnt += V / 2;
      }
    }
    long long ans = 0;
    for (int j = 0; j < cnt; j++){
      ans += n - 1 - j;
      ans -= j;
    }
    ans *= 2;
    cout << ans << endl;
  }
}