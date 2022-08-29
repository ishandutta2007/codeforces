#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> c;
  int prev = 0;
  bool ok = true;
  while (1){
    set<int> st;
    set<int> st2;
    for (int i = prev; i < n; i++){
      if (a[i] > 0){
        if (st2.count(a[i])){
          break;
        } else {
          st.insert(a[i]);
          st2.insert(a[i]);
        }
      } else {
        if (st.count(-a[i])){
          st.erase(-a[i]);
        } else {
          ok = false;
          break;
        }
      }
      if (st.empty()){
        c.push_back(i - prev + 1);
        prev = i + 1;
        break;
      }
    }
    if (!st.empty()){
      ok = false;
    }
    if (!ok){
      break;
    }
    if (prev == n){
      break;
    }
  }
  if (!ok){
    cout << -1 << endl; 
  } else {
    int d = c.size();
    cout << d << endl;
    for (int i = 0; i < d; i++){
      cout << c[i];
      if (i < d - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}