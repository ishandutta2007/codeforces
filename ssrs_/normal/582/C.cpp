#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<int, vector<int>> mp;
  for (int i = 1; i < n; i++){
    mp[gcd(n, i)].push_back(i);
  }
  long long ans = 0;
  for (auto P : mp){
    int g = P.first;
    vector<int> s = P.second;
    int m = s.size();
    vector<int> mx(g, 0);
    for (int i = 0; i < n; i++){
      mx[i % g] = max(mx[i % g], a[i]);
    }
    vector<bool> ok(n);
    int st = -1;
    for (int i = 0; i < n; i++){
      if (a[i] >= mx[i % g]){
        ok[i] = true;
      } else {
        ok[i] = false;
        st = i;
      }
    }
    /*
    cout << "g = " << g << endl;
    for (int i = 0; i < n; i++){
      cout << ok[i] << ' ';
    }
    cout << endl;
    */
    if (st == -1){
      ans += (long long) m * n;
    } else {
      vector<int> c;
      c.push_back(0);
      for (int i = st; i < st + n; i++){
        if (ok[i % n]){
          c.back()++;
        } else {
          if (c.back() > 0){
            c.push_back(0);
          }
        }
      }
      if (c.back() == 0){
        c.pop_back();
      }
      int cnt = c.size();
      /*
      for (int i = 0; i < cnt; i++){
        cout << c[i] << ' ';
      }
      cout << endl;
      */
      vector<long long> da(n + 1, 0);
      vector<long long> db(n + 1, 0);
      for (int i = 0; i < cnt; i++){
        int len = c[i];
        da[1]--;
        db[1] += len + 1;
        da[len + 1]++;
        db[len + 1] -= len + 1;
      }
      for (int i = 1; i <= n; i++){
        da[i] += da[i - 1];
        db[i] += db[i - 1];
      }
      for (int i = 0; i < m; i++){
        ans += da[s[i]] * s[i] + db[s[i]];
      }
    }
  }
  cout << ans << endl;
}