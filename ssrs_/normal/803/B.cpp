#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  set<int> st;
  for (int i = 0; i < n; i++){
    if (a[i] == 0){
      st.insert(i);
    }
  }
  for (int i = 0; i < n; i++){
    int ans = n;
    auto itr = st.lower_bound(i);
    if (itr != st.end()){
      ans = min(ans, *itr - i);
    }
    if (itr != st.begin()){
      itr--;
      ans = min(ans, i - *itr);
    }
    cout << ans;
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}