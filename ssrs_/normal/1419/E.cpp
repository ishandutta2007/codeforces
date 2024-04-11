#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
  if (b == 0){
    return a;
  } else {
    return gcd(b, a % b);
  }
}
vector<int> prime_factor(int n){
  vector<int> ans;
  for (int j = 2; j * j <= n; j++){
    if (n % j == 0){
      ans.push_back(j);
      while (n % j == 0){
        n /= j;
      }
    }
  }
  if (n > 1){
    ans.push_back(n);
  }
  return ans;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> f;
    for (int j = 1; j * j <= n; j++){
      if (n % j == 0){
        if (j > 1){
          f.push_back(j);
        }
        if (j * j < n){
          f.push_back(n / j);
        }
      }
    }
    sort(f.begin(), f.end());
    int m = f.size();
    if (m == 3 && gcd(f[0], f[1]) == 1){
      cout << f[0] << ' ' << f[1] << ' ' << f[2] << endl;
      cout << 1 << endl;
    } else {
      map<int, int> mp;
      for (int j = 0; j < m; j++){
        mp[f[j]] = j;
      }
      vector<int> pf = prime_factor(n);
      int cnt = pf.size();
      set<int> st;
      for (int j = 0; j < cnt - 1; j++){
        st.insert(pf[j] * pf[j + 1]);
      }
      if (cnt > 1){
        st.insert(pf[0] * pf[cnt - 1]);
      }
      vector<int> ans;
      ans.push_back(n);
      vector<bool> used(m, false);
      used[m - 1] = true;
      for (int j = 0; j < cnt; j++){
        ans.push_back(pf[j]);
        used[mp[pf[j]]] = true;
        for (int k = 0; k < m; k++){
          if (!used[k] && !st.count(f[k]) && f[k] % pf[j] == 0){
            used[k] = true;
            ans.push_back(f[k]);
          }
        }
        if (j < cnt - 1){
          int next = pf[j] * pf[j + 1];
          ans.push_back(next);
          used[mp[next]] = true;
        } else {
          int next = pf[j] * pf[0];
          ans.push_back(next);
          used[mp[next]] = true;
        }
      }
      for (int j = 0; j < m; j++){
        cout << ans[j];
        if (j < m - 1){
          cout << ' ';
        }
      }
      cout << endl;
      cout << 0 << endl;
    }
  }
}