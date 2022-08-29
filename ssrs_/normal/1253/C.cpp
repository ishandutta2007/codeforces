#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<long long> S(n + 1);
  S[0] = 0;
  for (int i = 0; i < n; i++){
    if (i < m){
      S[i + 1] = a[i];
    } else {
      S[i + 1] = S[i + 1 - m] + a[i];
    }
  }
  vector<long long> ans(n);
  ans[0] = S[1];
  for (int i = 1; i < n; i++){
    ans[i] = ans[i - 1] + S[i + 1];
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}