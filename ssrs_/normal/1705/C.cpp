#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<long long> l(c), r(c);
    for (int j = 0; j < c; j++){
      cin >> l[j] >> r[j];
      l[j]--;
    }
    vector<long long> sz(c + 1);
    sz[0] = s.size();
    for (int j = 0; j < c; j++){
      sz[j + 1] = sz[j] + (r[j] - l[j]);
    }
    for (int j = 0; j < q; j++){
      long long k;
      cin >> k;
      k--;
      for (int p = c - 1; p >= 0; p--){
        if (k >= sz[p]){
          k = k - sz[p] + l[p];
        }
      }
      cout << s[k] << endl;
    }
  }
}