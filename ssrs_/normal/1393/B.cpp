#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(100001, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  multiset<int> st;
  for (int i = 0; i <= 100000; i++){
    st.insert(cnt[i]);
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    char c;
    int x;
    cin >> c >> x;
    st.erase(st.find(cnt[x]));
    if (c == '+'){
      cnt[x]++;
    }
    if (c == '-'){
      cnt[x]--;
    }
    st.insert(cnt[x]);
    int A = *prev(st.end());
    int B = *prev(st.end(), 2);
    int C = *prev(st.end(), 3);
    if (A >= 8 || A >= 6 && B >= 2 || A >= 4 && B >= 4 || A >= 4 && B >= 2 && C >= 2){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}