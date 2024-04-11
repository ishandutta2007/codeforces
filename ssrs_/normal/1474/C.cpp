#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int j = 0; j < n * 2; j++){
      cin >> a[j];
    }
    bool ok = false;
    for (int j = 0; j < n * 2; j++){
      vector<int> b;
      for (int k = 0; k < n * 2; k++){
        if (j != k){
          b.push_back(a[k]);
        }
      }
      sort(b.begin(), b.end(), greater<int>());
      if (a[j] <= b[0]){
        vector<int> c;
        c.push_back(b[0]);
        multiset<int> st;
        for (int k = 1; k < n * 2 - 1; k++){
          if (st.find(b[k]) != st.end()){
            st.erase(st.find(b[k]));
          } else if (b[k] * 2 < c.back()){
            st.insert(-1);
            break;
          } else {
            st.insert(c.back() - b[k]);
            c.push_back(b[k]);
          }
        }
        if (st.empty()){
          cout << "YES" << endl;
          cout << a[j] + c[0] << endl;
          cout << c[0] << ' ' << a[j] << endl;
          for (int k = 0; k < n - 1; k++){
            cout << c[k + 1] << ' ' << c[k] - c[k + 1] << endl;
          }
          ok = true;
          break;
        }
      }
    }
    if (!ok){
      cout << "NO" << endl;
    }
  }
}