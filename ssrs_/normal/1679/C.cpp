#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  set<int> st1, st2;
  for (int i = 0; i <= n; i++){
    st1.insert(i);
    st2.insert(i);
  }
  vector<int> cnt1(n, 0), cnt2(n, 0);
  map<int, int> mp1, mp2;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      if (cnt1[x] == 0){
        st1.erase(x);
      }
      if (cnt2[y] == 0){
        st2.erase(y);
      }
      cnt1[x]++;
      cnt2[y]++;
    }
    if (t == 2){
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      cnt1[x]--;
      cnt2[y]--;
      if (cnt1[x] == 0){
        st1.insert(x);
      }
      if (cnt2[y] == 0){
        st2.insert(y);
      }
    }
    if (t == 3){
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      x1--;
      y1--;
      if (*st1.lower_bound(x1) >= x2 || *st2.lower_bound(y1) >= y2){
        cout << "Yes" << "\n";
      } else {
        cout << "No" << "\n";
      }
    }
  }
}