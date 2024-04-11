#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> s(n), r(n);
  for (int i = 0; i < n; i++){
    cin >> s[i] >> r[i];
  }
  vector<tuple<int, int, int>> T(n);
  for (int i = 0; i < n; i++){
    T[i] = make_tuple(s[i], r[i], i);
  }
  sort(T.begin(), T.end(), greater<tuple<int, int, int>>());
  vector<int> id(n);
  for (int i = 0; i < n; i++){
    s[i] = get<0>(T[i]);
    r[i] = get<1>(T[i]);
    id[i] = get<2>(T[i]);
  }
  int mx = -1, ms = -1;
  vector<int> s2, r2, id2;
  vector<vector<int>> p;
  int n2 = 0;
  for (int i = 0; i < n; i++){
    if (r[i] > mx){
      mx = r[i];
      ms = s[i];
      s2.push_back(s[i]);
      r2.push_back(r[i]);
      id2.push_back(id[i]);
      p.push_back(vector<int>(0));
      n2++;
    } else if (r[i] == mx && s[i] == ms){
      p.back().push_back(id[i]);
    }
  }
  stack<int> st;
  st.push(0);
  if (n2 > 1){
    st.push(1);
  }
  for (int i = 2; i < n2; i++){
    while (st.size() >= 2){
      int b = st.top();
      st.pop();
      int a = st.top();
      st.pop();
      long long A = (long long) s2[i] * r2[a] * (r2[b] - r2[i]) * (s2[b] - s2[a]);
      long long B = (long long) s2[a] * r2[i] * (r2[a] - r2[b]) * (s2[i] - s2[b]);
      if (A <= B){
        st.push(a);
        st.push(b);
        break;
      } else {
        st.push(a);
      }
    }
    st.push(i);
  }
  vector<int> ans;
  while (!st.empty()){
    int x = st.top();
    st.pop();
    ans.push_back(id2[x]);
    for (int y : p[x]){
      ans.push_back(y);
    }
  }
  sort(ans.begin(), ans.end());
  int cnt = ans.size();
  for (int i = 0; i < cnt; i++){
    cout << ans[i] + 1;
    if (i < cnt - 1){
      cout << ' ';
    }
  }
  cout << endl;
}