#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int d(char c1, char c2){
  return min(abs(c1 - c2), 26 - abs(c1 - c2));
}
int d(string s1, string s2){
  int ans = 0;
  for (int i = 0; i < 4; i++){
    ans += d(s1[i], s2[i]);
  }
  return ans;
}
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  string g = "ACTG";
  int ans = INF;
  for (int i = 0; i <= n - 4; i++){
    string t = s.substr(i, 4);
    ans = min(ans, d(g, t));
  }
  cout << ans << endl;
}