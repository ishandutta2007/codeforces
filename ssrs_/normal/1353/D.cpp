#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> p(1, -1);
    vector<int> val(1, n);
    vector<int> L(n, -1);
    vector<int> R(n, -1);
    int pos = 0;
    while (1){
      if (val[pos] % 2 == 0){
        R[pos] = p.size();
        p.push_back(pos);
        val.push_back(val[pos] / 2);
        if (val[pos] > 2){
          L[pos] = p.size();
          p.push_back(pos);
          val.push_back(val[pos] / 2 - 1);
        }
        pos++;
      } else if (val[pos] != 1){
        L[pos] = p.size();
        p.push_back(pos);
        val.push_back(val[pos] / 2);
        R[pos] = p.size();
        p.push_back(pos);
        val.push_back(val[pos] / 2);
        pos++;
      } else {
        pos++;
      }
      if (pos == p.size()){
        break;
      }
    }
    vector<int> num(n, -1);
    int nxt = 0;
    stack<pair<int, int>> S;
    S.push(make_pair(0, 0));
    while (!S.empty()){
      int v = S.top().first;
      int cnt = S.top().second;
      if (cnt == 0){
        S.top().second++;
        if (L[v] != -1){
          S.push(make_pair(L[v], 0));
        }
      } else if (cnt == 1){
        num[v] = nxt;
        nxt++;
        S.top().second++;
        if (R[v] != -1){
          S.push(make_pair(R[v], 0));
        }
      } else {
        S.pop();
      }
    }
    vector<pair<int, int>> tmp(n);
    for (int j = 0; j < n; j++){
      tmp[j] = make_pair(val[j], -num[j]);
    }
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      a[-tmp[j].second] = j + 1;
    }
    for (int j = 0; j < n; j++){
      cout << a[j];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}