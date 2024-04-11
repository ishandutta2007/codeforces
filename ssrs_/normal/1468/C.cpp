#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  set<int> st1;
  map<int, int> M;
  set<pair<int, int>> st2;
  int id = 1;
  vector<int> s;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int m;
      cin >> m;
      M[id] = m;
      st1.insert(id);
      st2.insert(make_pair(m, -id));
      id++;
    }
    if (t == 2){
      int ans = (*st1.begin());
      s.push_back(ans);
      st1.erase(ans);
      st2.erase(make_pair(M[ans], -ans));
    }
    if (t == 3){
      int ans = -(*prev(st2.end())).second;
      s.push_back(ans);
      st1.erase(ans);
      st2.erase(make_pair(M[ans], -ans));
    }
  }
  int cnt = s.size();
  for (int i = 0; i < cnt; i++){
    cout << s[i];
    if (i < cnt - 1){
      cout << ' ';
    }
  }
  cout << endl;
}