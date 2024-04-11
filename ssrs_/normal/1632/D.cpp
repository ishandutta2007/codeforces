#include <bits/stdc++.h>
using namespace std;
int gcd2(int x, int y){
  if (y == 0){
    return x;
  } else {
    return gcd2(y, x % y);
  }
}
template <typename T>
struct swag{
  function<T(T, T)> f;
  T E;
  stack<pair<T, T>> fr, bk;
  swag(function<T(T, T)> f, T E): f(f), E(E){
  }
  void push(T x){
    if (fr.empty()){
      fr.push(make_pair(x, x));
    } else {
      fr.push(make_pair(x, f(fr.top().second, x)));
    }
  }
  void pop(){
    if (bk.empty()){
      while (!fr.empty()){
        T x = fr.top().first;
        fr.pop();
        if (bk.empty()){
          bk.push(make_pair(x, x));
        } else {
          bk.push(make_pair(x, f(x, bk.top().second)));
        }
      }
    }
    bk.pop();
  }
  T get(){
    T ans1 = E;
    if (!fr.empty()){
      ans1 = fr.top().second;
    }
    T ans2 = E;
    if (!bk.empty()){
      ans2 = bk.top().second;
    }
    return f(ans2, ans1);
  }
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  swag<int> Q(gcd2, 0);
  vector<pair<int, int>> P;
  int r = 0;
  for (int i = 0; i < n; i++){
    while (r < n && (Q.get() == 0 || Q.get() > r - i)){
      Q.push(a[r]);
      r++;
    }
    if (Q.get() == r - i){
      P.push_back(make_pair(r, i));
    }
    Q.pop();
  }
  sort(P.begin(), P.end());
  int m = P.size();
  int c = 0;
  vector<int> pos;
  pos.push_back(1);
  for (int i = 0; i < m; i++){
    if (c <= P[i].second){
      pos.push_back(P[i].first);
      c = P[i].first;
    }
  }
  pos.push_back(n + 1);
  int cnt = pos.size();
  vector<int> ans(n);
  for (int i = 0; i < cnt - 1; i++){
    for (int j = pos[i] - 1; j < pos[i + 1] - 1; j++){
      ans[j] = i;
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}