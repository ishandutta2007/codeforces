#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s;
  cin >> n >> s;
  s--;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  multiset<int> st;
  for (int i = 0; i < n; i++){
    st.insert(a[i]);
  }
  int mex = 0;
  int ans = 0;
  if (a[s] != 0){
    ans++;
    st.erase(st.find(a[s]));
    st.insert(0);
    a[s] = 0;
  }
  for (int i = 0; i < n; i++){
    if (i != s && a[i] == 0){
      ans++;
      st.erase(st.find(a[i]));
      a[i] = mex;
      while (st.count(a[i])){
        a[i]++;
      }
      mex = a[i];
      st.insert(a[i]);
    }
  }
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  vector<int> L(n + 1, 0);
  for (int i = 0; i < n; i++){
    if (cnt[i] == 0){
      L[i + 1] = L[i] + 1;
    } else {
      L[i + 1] = L[i];
    }
  }
  vector<int> R(n + 1, 0);
  for (int i = n - 1; i >= 0; i--){
    R[i] = R[i + 1] + cnt[i];
  }
  int ans2 = n;
  for (int i = 1; i <= n; i++){
    ans2 = min(ans2, max(L[i], R[i]));
  }
  cout << ans + ans2 << endl;
}