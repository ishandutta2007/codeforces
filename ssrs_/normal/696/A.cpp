#include <bits/stdc++.h>
using namespace std;
string bit(long long x){
  string s = "";
  while (x > 0){
    s += x % 2 + '0';
    x /= 2;
  }
  reverse(s.begin(), s.end());
  return s;
}
long long num(string S){
  int N = S.size();
  long long ans = 0;
  for (int i = 0; i < N; i++){
    ans = ans * 2 + S[i] - '0';
  }
  return ans;
}
long long lca(long long x, long long y){
  string s = bit(x);
  string t = bit(y);
  while (s.size() > t.size()){
    s.pop_back();
  }
  while (s.size() < t.size()){
    t.pop_back();
  }
  while (s != t){
    s.pop_back();
    t.pop_back();
  }
  return num(s);
}
vector<long long> path(long long x, long long y){
  long long z = lca(x, y);
  vector<long long> ans;
  while (x != z){
    ans.push_back(x);
    x /= 2;
  }
  while (y != z){
    ans.push_back(y);
    y /= 2;
  }
  return ans;
}
int main(){
  int q;
  cin >> q;
  map<long long, long long> mp;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      long long v, u;
      int w;
      cin >> v >> u >> w;
      vector<long long> p = path(u, v);
      for (long long j : p){
        mp[j] += w;
      }
    }
    if (t == 2){
      long long v, u;
      cin >> v >> u;
      vector<long long> p = path(u, v);
      long long ans = 0;
      for (long long j : p){
        if (mp.count(j)){
          ans += mp[j];
        }
      }
      cout << ans << endl;
    }
  }
}