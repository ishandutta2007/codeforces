#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  multiset<int> st;
  map<int, int> mp;
  for (int i = 0; i <= n; i++){
    st.insert(i);
    mp[i]++;
  }
  for (int i = 0; i < n; i++){
    if (st.count(a[i])){
      st.erase(a[i]);
    }
    mp[a[i]]--;
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    b[i] = *(st.begin());
    mp[a[i]]++;
    if (mp[a[i]] > 0){
      st.insert(a[i]);
    }
    st.erase(st.lower_bound(b[i]));
    mp[b[i]]--;
  }
  for (int i = 0; i < n; i++){
    cout << b[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}