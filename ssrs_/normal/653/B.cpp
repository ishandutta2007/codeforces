#include <bits/stdc++.h>
using namespace std;
int dfs(string &S, int n, map<string, string> &mp){
  if (S.size() < n){
    int ans = 0;
    for (int i = 0; i < 6; i++){
      S.push_back('a' + i);
      ans += dfs(S, n, mp);
      S.pop_back();
    }
    return ans;
  } else {
    string T = S;
    for (int i = 0; i < n; i++){
      if (mp.count(T.substr(0, 2))){
        T = mp[T.substr(0, 2)] + T.substr(2);
      }
    }
    if (T == "a"){
      return 1;
    } else {
      return 0;
    }
  }
}
int main(){
  int n, q;
  cin >> n >> q;
  map<string, string> mp;
  for (int i = 0; i < q; i++){
    string a, b;
    cin >> a >> b;
    mp[a] = b;
  }
  string S = "";
  cout << dfs(S, n, mp) << endl;
}