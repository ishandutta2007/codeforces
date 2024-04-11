#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q, x;
  cin >> q >> x;
  set<long long> st;
  vector<long long> C(x);
  for (int i = 0; i < x; i++){
    st.insert(i);
    C[i] = i;
  }
  for (int i = 0; i < q; i++){
    int y;
    cin >> y;
    y %= x;
    st.erase(C[y]);
    C[y] += x;
    st.insert(C[y]);
    cout << *st.begin() << "\n";
  }
}