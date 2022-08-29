#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, q;
  cin >> n >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  set<int> st1;
  multiset<int> st2;
  for (int i = 0; i < n; i++){
    st1.insert(p[i]);
  }
  for (int i = 0; i < n - 1; i++){
    st2.insert(p[i + 1] - p[i]);
  }
  if (!st2.empty()){
    cout << *st1.rbegin() - *st1.begin() - *st2.rbegin() << endl;
  } else {
    cout << *st1.rbegin() - *st1.begin() << endl;
  }
  for (int i = 0; i < q; i++){
    int t, x;
    cin >> t >> x;
    if (t == 0){
      auto itr1 = st1.lower_bound(x);
      bool flg = true;
      int L, R;
      if (itr1 != st1.begin()){
        L = *prev(itr1);
        st2.erase(st2.find(x - L));
      } else {
        flg = false;
      }
      auto itr2 = st1.upper_bound(x);
      if (itr2 != st1.end()){
        R = *itr2;
        st2.erase(st2.find(R - x));
      } else {
        flg = false;
      }
      if (flg){
        st2.insert(R - L);
      }
      st1.erase(x);
    }
    if (t == 1){
      auto itr1 = st1.lower_bound(x);
      bool flg = true;
      int L, R;
      if (itr1 != st1.begin()){
        L = *prev(itr1);
        st2.insert(x - L);
      } else {
        flg = false;
      }
      auto itr2 = st1.upper_bound(x);
      if (itr2 != st1.end()){
        R = *itr2;
        st2.insert(R - x);
      } else {
        flg = false;
      }
      if (flg){
        st2.erase(st2.find(R - L));
      }
      st1.insert(x);
    }
    int ans = 0;
    if (!st1.empty()){
      ans += *st1.rbegin() - *st1.begin();
    }
    if (!st2.empty()){
      ans -= *st2.rbegin();
    }
    cout << ans << endl;
  }
}