#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int j = 0; j < n; j++){
      cin >> s[j];
    }
    int L = t.size();
    vector<int> d(L + 1, -1);
    deque<tuple<int, int, int>> dq;
    dq.push_back(make_tuple(0, 0, 0));
    vector<int> pr(L + 1, -1);
    while (!dq.empty()){
      int c = get<0>(dq.front());
      int v = get<1>(dq.front());
      int p = get<2>(dq.front());
      dq.pop_front();
      if (d[v] == -1){
        d[v] = c;
        pr[v] = p;
        if (v > 0){
          if (d[v - 1] == -1){
            dq.push_front(make_tuple(c, v - 1, v));
          }
        }
        for (int j = 0; j < n; j++){
          int L2 = s[j].size();
          if (v + L2 <= L){
            if (t.substr(v, L2) == s[j] && d[v + L2] == -1){
              dq.push_back(make_tuple(c + 1, v + L2, v));
            }
          }
        }
      }
    }
    if (d[L] == -1){
      cout << -1 << endl;
    } else {
      int m = d[L];
      vector<int> w, p;
      for (int v = L; v != 0; v = pr[v]){
        if (pr[v] < v){
          int id;
          for (int j = 0; j < n; j++){
            if (t.substr(pr[v], v - pr[v]) == s[j]){
              id = j;
            }
          }
          w.push_back(id);
          p.push_back(pr[v]);
        }
      }
      cout << m << endl;
      for (int j = 0; j < m; j++){
        cout << w[j] + 1 << ' ' << p[j] + 1 << endl;
      }
    }
  }
}