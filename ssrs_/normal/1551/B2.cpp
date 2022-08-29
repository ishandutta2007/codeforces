#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<vector<int>> p(n);
    for (int j = 0; j < n; j++){
      p[a[j]].push_back(j);
    }
    int sum = 0;
    for (int j = 0; j < n; j++){
      sum += min((int) p[j].size(), k);
    }
    priority_queue<pair<int, int>> pq;
    for (int j = 0; j < n; j++){
      pq.push(make_pair(p[j].size(), j));
    }
    vector<int> c(n, 0);
    for (int j = 0; j < k; j++){
      int t = sum / k;
      vector<int> id;
      for (int l = 0; l < t; l++){
        int q = pq.top().second;
        pq.pop();
        c[p[q].back()] = j + 1;
        p[q].pop_back();
        id.push_back(q);
      }
      for (int l = 0; l < t; l++){
        if (!p[id[l]].empty()){
          pq.push(make_pair(p[id[l]].size(), id[l]));
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << c[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}