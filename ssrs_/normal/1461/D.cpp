#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    sort(a.begin(), a.end());
    vector<long long> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j] + a[j];
    }
    set<long long> st;
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, n));
    while (!Q.empty()){
      int L = Q.front().first;
      int R = Q.front().second;
      Q.pop();
      st.insert(S[R] - S[L]);
      if (R - L > 1){
        int mid = (a[L] + a[R - 1]) / 2;
        int p = upper_bound(a.begin(), a.end(), mid) - a.begin();
        if (p != L && p != R){
          Q.push(make_pair(L, p));
          Q.push(make_pair(p, R));
        }
      }
    }
    for (int j = 0; j < q; j++){
      int s;
      cin >> s;
      if (st.count(s)){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}