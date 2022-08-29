#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> h(n);
    for (int j = 0; j < n; j++){
      cin >> h[j];
    }
    sort(h.begin(), h.end());
    if (n == 2){
      cout << h[0] << ' ' << h[1] << endl;
    } else {
      multiset<int> st;
      for (int j = 0; j < n; j++){
        st.insert(h[j]);
      }
      int mx = -1, pos = -1;
      int mn = INF;
      bool m = false;
      for (int j = 0; j < n - 1; j++){
        if (h[j + 1] - h[j] < mn){
          mn = h[j + 1] - h[j];
          mx = -1;
        }
        if (h[j + 1] - h[j] <= mn){
          int x = n - 3;
          st.erase(st.find(h[j]));
          st.erase(st.find(h[j + 1]));
          bool m2 = false;
          if (*st.begin() >= h[j] && *prev(st.end()) <= h[j + 1]){
            x++;
            m2 = true;
          }
          if (x > mx){
            mx = x;
            pos = j;
            m = m2;
          }
          st.insert(h[j]);
          st.insert(h[j + 1]);
        }
      }
      cout << h[pos];
      if (m){
        for (int j = 0; j < n; j++){
          if (j != pos && j != pos + 1){
            cout << ' ' << h[j];
          }
        }
      } else {
        for (int j = pos + 2; j < n; j++){
          cout << ' ' << h[j];
        }
        for (int j = 0; j < pos; j++){
          cout << ' ' << h[j];
        }
      }
      cout << ' ' << h[pos + 1] << endl;
    }
  }
}