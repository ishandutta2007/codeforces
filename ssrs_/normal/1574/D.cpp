#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
    a[i] = vector<int>(c[i]);
    for (int j = 0; j < c[i]; j++){
      cin >> a[i][j];
    }
  }
  int m;
  cin >> m;
  vector<vector<int>> b(m, vector<int>(n));
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      cin >> b[i][j];
      b[i][j]--;
    }
  }
  set<vector<int>> st;
  for (int i = 0; i < m; i++){
    st.insert(b[i]);
  }
  int s = 0;
  vector<int> t(n);
  for (int i = 0; i < n; i++){
    t[i] = c[i] - 1;
    s += a[i][t[i]];
  }
  set<vector<int>> used;
  used.insert(t);
  priority_queue<pair<int, vector<int>>> pq;
  pq.push(make_pair(s, t));
  while (!pq.empty()){
    int sum = get<0>(pq.top());
    vector<int> c = get<1>(pq.top());
    pq.pop();
    if (st.count(c) == 0){
      for (int i = 0; i < n; i++){
        cout << c[i] + 1;
        if (i < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
      break;
    } else {
      for (int i = 0; i < n; i++){
        if (c[i] > 0){
          vector<int> c2 = c;
          c2[i]--;
          if (used.count(c2) == 0){
            used.insert(c2);
            int sum2 = sum - a[i][c[i]] + a[i][c2[i]];
            pq.push(make_pair(sum2, c2));
          }
        }
      }
    }
  }
}