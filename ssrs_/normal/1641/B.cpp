#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    deque<int> dq;
    for (int j = 0; j < n; j++){
      int a;
      cin >> a;
      dq.push_back(a);
    }
    int q = 0, d = 0;
    vector<int> p, c, T;
    int pos = 0;
    bool ok = true;
    while (!dq.empty()){
      int x = dq.front();
      dq.pop_front();
      pos++;
      vector<int> tmp;
      bool ok2 = false;
      while (!dq.empty()){
        int a = dq.front();
        dq.pop_front();
        pos++;
        if (a == x){
          ok2 = true;
          break;
        } else {
          tmp.push_back(a);
        }
      }
      if (!ok2){
        ok = false;
        break;
      }
      int cnt = tmp.size();
      for (int j = 0; j < cnt; j++){
        q++;
        p.push_back(pos + j);
        c.push_back(tmp[j]);
        dq.push_front(tmp[j]);
      }
      pos += cnt;
      d++;
      T.push_back(cnt * 2 + 2);
    }
    if (!ok){
      cout << -1 << endl;
    } else {
      cout << q << "\n";
      for (int j = 0; j < q; j++){
        cout << p[j] << ' ' << c[j] << "\n";
      }
      cout << d << "\n";
      for (int j = 0; j < d; j++){
        cout << T[j];
        if (j < d - 1){
          cout << ' ';
        }
      }
      cout << "\n";
    }
  }
}