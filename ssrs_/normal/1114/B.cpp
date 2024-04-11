#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(a[i], i);
  }
  sort(P.begin(), P.end(), greater<pair<int, int>>());
  long long sum = 0;
  vector<int> b;
  for (int i = 0; i < m * k; i++){
    sum += P[i].first;
    b.push_back(P[i].second);
  }
  sort(b.begin(), b.end());
  vector<int> p(k - 1);
  for (int i = 0; i < k - 1; i++){
    p[i] = b[(i + 1) * m - 1];
  }
  cout << sum << endl;
  for (int i = 0; i < k - 1; i++){
    cout << p[i] + 1;
    if (i < k - 2){
      cout << ' ';
    }
  }
  cout << endl;
}