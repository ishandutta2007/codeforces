#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> b[i];
  }
  set<long long> st;
  for (int i = 2; i * i <= a[0]; i++){
    if (a[0] % i == 0){
      st.insert(i);
      while (a[0] % i == 0){
        a[0] /= i;
      }
    }
  }
  if (a[0] != 1){
    st.insert(a[0]);
  }
  for (int i = 2; i * i <= b[0]; i++){
    if (b[0] % i == 0){
      st.insert(i);
      while (b[0] % i == 0){
        b[0] /= i;
      }
    }
  }
  if (b[0] != 1){
    st.insert(b[0]);
  }
  for (int i = 1; i < n; i++){
    set<long long> st2;
    for (long long x : st){
      long long x2 = __gcd(x, a[i]);
      if (x2 != 1){
        st2.insert(x2);
      }
      long long x3 = __gcd(x, b[i]);
      if (x3 != 1){
        st2.insert(x3);
      }
    }
    swap(st, st2);
  }
  if (st.empty()){
    cout << -1 << endl;
  } else {
    cout << *(st.begin()) << endl;
  }
}