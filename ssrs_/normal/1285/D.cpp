#include <bits/stdc++.h>
using namespace std;
int dfs(vector<int> a, int d){
  if (d == -1){
    return 0;
  }
  int N = a.size();
  vector<vector<int>> b(2);
  for (int i = 0; i < N; i++){
    if (a[i] >> d & 1){
      b[1].push_back(a[i]);
    } else {
      b[0].push_back(a[i]);
    }
  }
  if (b[0].empty()){
    return dfs(b[1], d - 1);
  } else if (b[1].empty()){
    return dfs(b[0], d - 1);
  } else {
    return (1 << d) + min(dfs(b[0], d - 1), dfs(b[1], d - 1));
  }
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long ans = 0;
  cout << dfs(a, 29) << endl;
}