#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(m, 0);
  vector<vector<int>> id(m);
  for (int i = 0; i < n; i++){
    cnt[a[i] % m]++;
    id[a[i] % m].push_back(i);
  }
  vector<int> id2;
  for (int i = 0; i < m; i++){
    for (int j : id[i]){
      id2.push_back(j);
    }
  }
  vector<int> S(m + 1, 0);
  for (int i = 0; i < m; i++){
    S[i + 1] = S[i] + cnt[i] - n / m;
  }
  int sr = min_element(S.begin(), S.end() - 1) - S.begin();
  int s = 0;
  for (int i = 0; i < sr; i++){
    s += cnt[i];
  }
  vector<int> r(n);
  for (int i = s; i < s + n; i++){
    r[id2[i % n]] = (sr + (i - s) / (n / m)) % m;
  }
  vector<int> ans = a;
  long long sum = 0;
  for (int i = 0; i < n; i++){
    int d = (r[i] - a[i] % m + m) % m;
    sum += d;
    ans[i] += d;
  }
  cout << sum << endl;
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}