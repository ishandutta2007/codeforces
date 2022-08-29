#include <bits/stdc++.h>
using namespace std;
const int INF = 1100000000;
bool dfs(vector<int> s, vector<tuple<int, int, int, int>> &R){
  int cnt = s.size();
  if (s.size() == 1){
    return true;
  }
  vector<tuple<int, int, int>> H(cnt);
  for (int i = 0; i < cnt; i++){
    H[i] = make_tuple(get<2>(R[s[i]]), get<0>(R[s[i]]), s[i]);
  }
  sort(H.begin(), H.end());
  int l = INF;
  for (int i = cnt - 2; i >= 0; i--){
    l = min(l, get<1>(H[i + 1]));
    if (get<0>(H[i]) <= l){
      vector<int> s1, s2;
      for (int j = 0; j <= i; j++){
        s1.push_back(get<2>(H[j]));
      }
      for (int j = i + 1; j < cnt; j++){
        s2.push_back(get<2>(H[j]));
      }
      return dfs(s1, R) && dfs(s2, R);
    }
  }
  vector<tuple<int, int, int>> V(cnt);
  for (int i = 0; i < cnt; i++){
    V[i] = make_tuple(get<3>(R[s[i]]), get<1>(R[s[i]]), s[i]);
  }
  sort(V.begin(), V.end());
  int d = INF;
  for (int i = cnt - 2; i >= 0; i--){
    d = min(d, get<1>(V[i + 1]));
    if (get<0>(V[i]) <= d){
      vector<int> s1, s2;
      for (int j = 0; j <= i; j++){
        s1.push_back(get<2>(V[j]));
      }
      for (int j = i + 1; j < cnt; j++){
        s2.push_back(get<2>(V[j]));
      }
      return dfs(s1, R) && dfs(s2, R);
    }
  }
  return false;
}
int main(){
  int n;
  cin >> n;
  vector<tuple<int, int, int, int>> R(n);
  for (int i = 0; i < n; i++){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    R[i] = make_tuple(a, b, c, d);
  }
  vector<int> s;
  for (int i = 0; i < n; i++){
    s.push_back(i);
  }
  bool ok = dfs(s, R);
  if (ok){
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}