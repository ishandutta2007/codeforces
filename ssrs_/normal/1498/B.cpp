#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, W;
    cin >> n >> W;
    vector<int> w(n);
    for (int j = 0; j < n; j++){
      cin >> w[j];
    }
    sort(w.begin(), w.end(), greater<int>());
    multiset<int> st;
    for (int j = 0; j < n; j++){
      auto itr = st.lower_bound(w[j]);
      if (itr != st.end()){
        int tmp = *itr;
        st.erase(itr);
        st.insert(tmp - w[j]);
      } else {
        st.insert(W - w[j]);
      }
    }
    cout << st.size() << endl;
  }
}