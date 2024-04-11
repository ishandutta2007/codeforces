#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], i);
  }
  sort(P.rbegin(), P.rend());
  int sum = 0;
  for (int i = 0; i < k; i++){
    sum += P[i].first;
  }
  vector<int> use(k);
  for (int i = 0; i < k; i++){
    use[i] = P[i].second;
  }
  sort(use.begin(), use.end());
  vector<int> t(k);
  if (k == 1){
    t[0] = n;
  } else {
    t[0] = use[0] + 1;
    for (int i = 1; i < k - 1; i++){
      t[i] = use[i] - use[i - 1];
    }
    t[k - 1] = n - 1 - use[k - 2];
  }
  cout << sum << endl;
  for (int i = 0; i < k; i++){
    cout << t[i];
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}