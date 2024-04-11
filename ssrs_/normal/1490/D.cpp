#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &a, vector<int> &d, int l, int r, int c){
  int p = max_element(a.begin() + l, a.begin() + r) - a.begin();
  d[p] = c;
  if (l < p){
    dfs(a, d, l, p, c + 1);
  }
  if (p < r - 1){
    dfs(a, d, p + 1, r, c + 1);
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
    vector<int> d(n);
    dfs(a, d, 0, n, 0);
    for (int j = 0; j < n; j++){
      cout << d[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}