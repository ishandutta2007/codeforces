#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
struct rectangle_set{
  map<int, int> mp;
  multiset<int> st;
  rectangle_set(){
    mp[-1] = INF * 2;
    mp[0] = 0;
    st.insert(0);
  }
  void add(int x, int y){
    bool upd = false;
    int nexty = INF, nextx = INF;
    while (true){
      auto itr = mp.lower_bound(x);
      itr--;
      if ((*itr).second > y){
        break;
      }
      upd = true;
      nextx = min(nextx, (*itr).first);
      nexty = min(nexty, (*itr).second);
      st.erase(st.find((*itr).first + (*itr).second));
      mp.erase(itr);
    }
    if (upd){
      mp[nextx] = y;
      st.insert(nextx + y);
      mp[x] = nexty;
      st.insert(x + nexty);
    }
  }
  int getmin(){
    return *st.begin();
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<int> x;
  for (int i = 0; i < n; i++){
    x.push_back(a[i]);
    x.push_back(b[i]);
    x.push_back(c[i]);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  int m = x.size();
  for (int i = 0; i < n; i++){
    a[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
    b[i] = lower_bound(x.begin(), x.end(), b[i]) - x.begin();
    c[i] = lower_bound(x.begin(), x.end(), c[i]) - x.begin();
  }
  vector<int> ap(m, INF), bp(m, INF), cp(m, INF);
  for (int i = n - 1; i >= 0; i--){
    ap[a[i]] = i;
    bp[b[i]] = i;
    cp[c[i]] = i;
  }
  rectangle_set st;
  for (int i = 0; i < m; i++){
    if (ap[i] == INF){
      st.add(bp[i] + 1, cp[i] + 1);
    }
  }
  int ans = st.getmin() + n;
  for (int i = n - 1; i >= 0; i--){
    if (ap[a[i]] == i){
      st.add(bp[a[i]] + 1, cp[a[i]] + 1);
    }
    ans = min(ans, st.getmin() + i);
  }
  cout << ans << endl;
}