#include <bits/stdc++.h>
using namespace std;
//https://ei1333.github.io/luzhiled/snippets/math/quotient-range.html
template< typename T >
vector< pair< pair< T, T >, T > > quotient_range(T N) {
  T M;
  vector< pair< pair< T, T >, T > > ret;
  for(M = 1; M * M <= N; M++) {
    ret.emplace_back(make_pair(M, M), N / M);
  }
  for(T i = M; i >= 1; i--) {
    T L = N / (i + 1) + 1;
    T R = N / i;
    if(L <= R && ret.back().first.second < L) ret.emplace_back(make_pair(L, R), N / L);
  }
  return ret;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  //imos
  vector<int> ans(n, 0);
  //1
  if (a[1] < a[0]){
    ans[0]++;
    ans[n - 1]--;
  }
  for (int i = 2; i < n; i++){
    vector<pair<pair<int, int>, int>> res = quotient_range(i - 1);
    /*
    cout << "i - 1 = " << i - 1 << endl;
    for (auto P : res){
      cout << "[" << P.first.first << "," << P.first.second << "]: " << P.second << ", ";
    }
    cout << endl;
    */
    for (auto P : res){
      int L = P.first.first;
      int R = P.first.second;
      L--;
      int p = P.second;
      if (a[i] < a[p]){
        ans[L]++;
        ans[R]--;
      }
    }
    if (a[i] < a[0]){
      ans[i - 1]++;
      ans[n - 1]--;
    }
  }
  for (int i = 1; i < n; i++){
    ans[i] += ans[i - 1];
  }
  for (int i = 0; i < n - 1; i++){
    cout << ans[i];
    if (i < n - 2){
      cout << ' ';
    }
  }
  cout << endl;
}