#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++){
    cin >> d[i];
  }
  vector<long long> L(n + 1);
  L[0] = 0;
  for (int i = 0; i < n; i++){
    L[i + 1] = L[i] + d[i];
  }
  vector<long long> R(n + 1);
  R[n] = 0;
  for (int i = n - 1; i >= 0; i--){
    R[i] = R[i + 1] + d[i];
  }
  long long mx = -1;
  set<long long> st;
  for (int i = 0; i <= n; i++){
    st.insert(R[i]);
  }
  for (int i = 0; i < n; i++){
    if (st.count(L[i])){
      mx = max(mx, L[i]);
    }
    st.erase(R[i]);
  }
  cout << mx << endl;
}