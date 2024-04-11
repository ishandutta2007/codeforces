#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    S[i + 1] = S[i] + a[i];
  }
  int ans = 0;
  set<long long> st;
  st.insert(0);
  for (int i = 1; i <= n; i++){
    if (st.count(S[i])){
      ans++;
      st.clear();
    }
    st.insert(S[i - 1]);
    st.insert(S[i]);
  }
  cout << ans << endl;
}