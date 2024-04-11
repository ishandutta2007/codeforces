#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<int> b(k);
    for (int j = 0; j < k; j++){
      cin >> b[j];
      b[j]--;
    }
    vector<int> p(n);
    for (int j = 0; j < n; j++){
      p[a[j]] = j;
    }
    for (int j = 0; j < k; j++){
      b[j] = p[b[j]];
    }
    vector<bool> in_b(n, false);
    for (int j = 0; j < k; j++){
      in_b[b[j]] = true;
    }
    set<int> st;
    for (int j = 0; j < n; j++){
      st.insert(j);
    }
    long long ans = 1;
    for (int j = 0; j < k; j++){
      auto itr1 = st.find(b[j]);
      int cnt = 0;
      if (itr1 != st.begin()){
        auto itr2 = prev(itr1);
        if (!in_b[*itr2]){
          cnt++;
        }
      }
      if (itr1 != prev(st.end())){
        auto itr3 = next(itr1);
        if (!in_b[*itr3]){
          cnt++;
        }
      }
      ans *= cnt;
      ans %= MOD;
      in_b[b[j]] = false;
    }
    cout << ans << endl;
  }
}