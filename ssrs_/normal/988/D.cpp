#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<long long> x(n);
  for (int i = 0; i < n; i++){
    cin >> x[i];
  }
  set<long long> st;
  for (int i = 0; i < n; i++){
    st.insert(x[i]);
  }
  bool ok = false;
  for (int d = 0; d <= 30; d++){
    long long p = 1 << d;
    for (long long x : st){
      if (st.count(x + p) && st.count(x + p * 2)){
        cout << 3 << endl;
        cout << x << ' ' << x + p << ' ' << x + p * 2 << endl;
        ok = true;
        break;
      }
    }
    if (ok){
      break;
    }
  }
  if (!ok){
    for (int d = 0; d <= 30; d++){
      long long p = 1 << d;
      for (long long x : st){
        if (st.count(x + p)){
          cout << 2 << endl;
          cout << x << ' ' << x + p << endl;
          ok = true;
          break;
        }
      }
      if (ok){
        break;
      }
    }
  }
  if (!ok){
    cout << 1 << endl;
    cout << *st.begin() << endl;
  }
}