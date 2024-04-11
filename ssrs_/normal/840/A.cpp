#include <bits/stdc++.h>
using namespace std;
int main(){
  int m;
  cin >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  vector<pair<int, int>> b(m);
  for (int i = 0; i < m; i++){
    int tmp;
    cin >> tmp;
    b[i] = make_pair(tmp, i);
  }
  sort(b.begin(), b.end());
  vector<int> ans(m);
  for (int i = 0; i < m; i++){
    int pos = b[i].second;
    ans[pos] = a[i];
  }
  for (int i = 0; i < m; i++){
    cout << ans[i];
    if (i < m - 1){
      cout << ' ';
    }
  }
  cout << endl;
}