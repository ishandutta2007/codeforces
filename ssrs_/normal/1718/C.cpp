#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    int n2 = n;
    vector<int> f;
    for (int j = 2; j <= n2; j++){
      if (n2 % j == 0){
        f.push_back(j);
        while (n2 % j == 0){
          n2 /= j;
        }
      }
    }
    int cnt = f.size();
    vector<vector<long long>> sum(cnt);
    for (int j = 0; j < cnt; j++){
      sum[j] = vector<long long>(n / f[j], 0);
      for (int k = 0; k < n; k++){
        sum[j][k % (n / f[j])] += a[k];
      }
      for (int k = 0; k < n / f[j]; k++){
        sum[j][k] *= n / f[j];
      }
    }
    multiset<long long> st;
    for (int j = 0; j < cnt; j++){
      for (int k = 0; k < n / f[j]; k++){
        st.insert(sum[j][k]);
      }
    }
    for (int j = 0; j <= q; j++){
      cout << *prev(st.end()) << "\n";
      if (j < q){
        int p, x;
        cin >> p >> x;
        p--;
        for (int k = 0; k < cnt; k++){
          int r = p % (n / f[k]);
          st.erase(st.find(sum[k][r]));
          sum[k][r] += (long long) (x - a[p]) * (n / f[k]);
          st.insert(sum[k][r]);
        }
        a[p] = x;
      }
    }
  }
}