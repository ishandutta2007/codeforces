#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  long long s;
  cin >> n >> s;
  if (s < n * 2 - 1 || s > (long long) n * (n + 1) / 2){
    cout << "No" << endl;
  } else {
    int fv = 0, tv = n - 1;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      vector<int> d(n);
      d[0] = 1;
      for (int i = 1; i < n; i++){
        d[i] = d[(i - 1) / mid] + 1;
      }
      long long sum = 0;
      for (int i = 0; i < n; i++){
        sum += d[i];
      }
      if (sum <= s){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    vector<int> d(n);
    d[0] = 1;
    for (int i = 1; i < n; i++){
      d[i] = d[(i - 1) / tv] + 1;
    }
    int tv2 = 1, fv2 = n + 1;
    while (fv2 - tv2 > 1){
      int mid = (tv2 + fv2) / 2;
      long long sum = 0;
      for (int i = 0; i < mid; i++){
        sum += d[i];
      }
      long long A = d[mid - 1] + 1;
      long long B = d[mid - 1] + n - mid;
      sum += (A + B) * (n - mid) / 2;
      if (sum >= s){
        tv2 = mid;
      } else {
        fv2 = mid;
      }
    }
    long long sum = 0;
    for (int i = 0; i < tv2; i++){
      sum += d[i];
    }
    long long A = d[tv2 - 1] + 1;
    long long B = d[tv2 - 1] + n - tv2;
    sum += (A + B) * (n - tv2) / 2;
    for (int i = tv2; i < n; i++){
      d[i] = d[i - 1] + 1;
    }
    for (int i = 0; i < sum - s; i++){
      d[n - 1 - i]--;
    }
    vector<vector<int>> id(n);
    for (int i = 0; i < n; i++){
      id[d[i] - 1].push_back(i);
    }
    vector<int> p(n, -1);
    for (int i = 1; i < n; i++){
      int cnt = id[i].size();
      for (int j = 0; j < cnt; j++){
        int v = id[i][j];
        p[v] = id[i - 1][j / tv];
      }
    }
    cout << "Yes" << endl;
    for (int i = 1; i < n; i++){
      cout << p[i] + 1;
      if (i < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}