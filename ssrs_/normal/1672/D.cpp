#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> b(n);
    for (int j = 0; j < n; j++){
      cin >> b[j];
    }
    bool ok = true;
    int p = n - 1, q = n - 1;
    multiset<int> st;
    while (q >= 0){
      if (a[p] == b[q]){
        p--;
        q--;
      } else {
        bool ok2 = true;
        if (q == n - 1){
          ok2 = false;
        }
        if (b[q] != b[q + 1]){
          ok2 = false;
        }
        if (ok2){
          st.insert(b[q]);
          q--;
        } else {
          auto itr = st.find(a[p]);
          if (itr == st.end()){
            ok = false;
            break;
          }
          st.erase(itr);
          p--;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}