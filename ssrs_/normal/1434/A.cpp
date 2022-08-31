#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  vector<int> a(6);
  for (int i = 0; i < 6; i++){
    cin >> a[i];
  }
  sort(a.rbegin(), a.rend());
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  sort(b.begin(), b.end());
  vector<vector<int>> f(n, vector<int>(6));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < 6; j++){
      f[i][j] = b[i] - a[j];
    }
  }
  set<tuple<int, int, int>> st;
  for (int i = 0; i < n; i++){
    st.insert(make_tuple(f[i][0], i, 0));
  }
  int ans = INF;
  while (1){
    ans = min(ans, get<0>(*st.rbegin()) - get<0>(*st.begin()));
    int id = get<1>(*st.begin());
    int s = get<2>(*st.begin());
    if (s == 5){
      break;
    } else {
      st.erase(st.begin());
      st.insert(make_tuple(f[id][s + 1], id, s + 1));
    }
  }
  cout << ans << endl;
}