#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &A){
  int N = A.size();
  if (N == 0){
    return true;
  }
  vector<vector<int>> E(N);
  vector<int> pr(30, -1);
  for (int i = 0; i < N; i++){
    for (int j = 0; j < 30; j++){
      if ((A[i] >> j & 1) == 1){
        if (pr[j] != -1){
          E[i].push_back(pr[j]);
          E[pr[j]].push_back(i);
        }
        pr[j] = i;
      }
    }
  }
  vector<bool> used(N, false);
  used[0] = true;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (!used[w]){
        used[w] = true;
        Q.push(w);
      }
    }
  }
  return used == vector<bool>(N, true);
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
    vector<int> b, pos;
    int zero = 0;
    for (int j = 0; j < n; j++){
      if (a[j] == 0){
        zero++;
      } else {
        pos.push_back(j);
        b.push_back(a[j]);
      }
    }
    int cnt = b.size();
    bool ok0 = check(b);
    if (ok0){
      int ans = zero;
      if (zero > 0 && !b.empty()){
        bool odd = false;
        for (int j = 0; j < cnt; j++){
          if (b[j] % 2 == 1){
            odd = true;
          }
        }
        if (!odd){
          ans++;
          for (int j = 0; j < n; j++){
            if (a[j] > 0){
              a[j]++;
              break;
            }
          }
        }
      }
      for (int j = 0; j < n; j++){
        if (a[j] == 0){
          a[j]++;
        }
      }
      cout << ans << endl;
      for (int j = 0; j < n; j++){
        cout << a[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      bool ok1 = false;
      int p = -1, s = 0;
      for (int j = 0; j < cnt; j++){
        if (b[j] % 2 == 0){
          b[j]--;
          if (check(b)){
            ok1 = true;
            p = j;
            s = -1;
          }
          b[j] += 2;
          if (check(b)){
            ok1 = true;
            p = j;
            s = 1;
          }
          b[j]--;
        }
      }
      int ans = 0;
      if (ok1){
        ans++;
        a[pos[p]] += s;
      } else {
        int mx = 0;
        for (int j = 0; j < cnt; j++){
          mx = max(mx, __builtin_ctz(b[j]));
        }
        vector<int> A;
        for (int j = 0; j < n; j++){
          if (a[j] > 0){
            if (__builtin_ctz(a[j]) == mx){
              A.push_back(j);
            }
          }
        }
        ans += 2;
        a[A[0]]++;
        a[A[1]]--;
      }
      for (int j = 0; j < n; j++){
        if (a[j] == 0){
          a[j] = 1;
          ans++;
        }
      }
      cout << ans << endl;
      for (int j = 0; j < n; j++){
        cout << a[j];
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}