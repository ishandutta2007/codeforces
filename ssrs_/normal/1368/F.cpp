#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int P = (int)sqrt(n);
  int B = n / P;
  vector<set<int>> st1(B);
  vector<set<int>> st2(B);
  map<int, int> mp;
  vector<vector<int>> num(B);
  for (int i = 0; i < n; i++){
    num[i % B].push_back(i);
  }
  int pos = 0;
  for (int i = 0; i < n; i++){
    st1[pos].insert(i + 1);
    mp[i + 1] = pos;
    num[pos].pop_back();
    if (num[pos].empty()){
      pos++;
    }
  }
  vector<int> sz(B, 0);
  for (int i = 1; i <= n; i++){
    sz[mp[i]]++;
  }
  int R = 0;
  int mx = 0;
  for (int i = 0; i < B; i++){
    R += st1[i].size() - 1;
    mx = max(mx, (int) st1[i].size() - 1);
  }
  R -= mx;
  int cnt = 0;
  while (cnt < R){
    int max_cnt = 0;
    for (int i = 0; i < B; i++){
      if (st2[i].size() > max_cnt){
        max_cnt = st2[i].size();
      }
    }
    int k = max_cnt + 1;
    if (cnt >= max_cnt * (B - 1)){
      k++;
    }
    vector<int> l;
    for (int i = 0; i < B; i++){
      vector<int> tmp;
      for (int x : st1[i]){
        if (st2[i].size() + 1 < k && st2[i].size() + 1 < sz[i]){
          l.push_back(x);
          tmp.push_back(x);
          st2[i].insert(x);
          cnt++;
        }
        if (l.size() == k){
          break;
        }
      }
      for (int x : tmp){
        st1[i].erase(x);
      }
      if (l.size() == k){
        break;
      }
    }
    k = l.size();
    cout << k;
    for (int i = 0; i < k; i++){
      cout << ' ' << l[i];
    }
    cout << endl;
    int x;
    cin >> x;
    if (x == -1){
      return 1;
    }
    for (int i = 0; i < k; i++){
      int b = mp[x];
      if (st2[b].count(x)){
        st2[b].erase(x);
        st1[b].insert(x);
        cnt--;
      }
      x++;
      if (x == n + 1){
        x = 1;
      }
    }
  }
  cout << 0 << endl;
}