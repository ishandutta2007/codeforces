#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> pr(26, -1);
  vector<int> x(n);
  for (int i = 0; i < n; i++){
    vector<pair<int, int>> P;
    for (int j = 0; j < 26; j++){
      if (pr[j] != -1){
        P.push_back(make_pair(pr[j], j));
      }
    }
    sort(P.begin(), P.end(), greater<pair<int, int>>());
    int tv = 0, fv = P.size() + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      cout << "? 2 " << P[mid - 1].first + 1 << ' ' << i + 1 << endl;
      int res;
      cin >> res;
      if (res == mid + 1){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    if (tv < P.size()){
      x[i] = P[tv].second;
    } else {
      for (int j = 0; j < 26; j++){
        if (pr[j] == -1){
          x[i] = j;
          break;
        }
      }
    }
    pr[x[i]] = i;
  }
  vector<char> ch(26);
  for (int i = 0; i < 26; i++){
    if (pr[i] != -1){
      cout << "? 1 " << pr[i] + 1 << endl;
      cin >> ch[i];
    }
  }
  string ans;
  for (int i = 0; i < n; i++){
    ans += ch[x[i]];
  }
  cout << "! " << ans << endl;
}