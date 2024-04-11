#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> &a, int p, int s, int c){
  int N = a.size();
  if (p == N){
    if (s == 0 && c == 1){
      return true;
    } else {
      return false;
    }
  } else {
    bool ok = false;
    if (dfs(a, p + 1, s, c)){
      ok = true;
    }
    if (dfs(a, p + 1, s + a[p], 1)){
      ok = true;
    }
    if (dfs(a, p + 1, s - a[p], 1)){
      ok = true;
    }
    return ok;
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    if (dfs(a, 0, 0, 0)){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}