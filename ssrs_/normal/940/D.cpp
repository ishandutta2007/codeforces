#include <bits/stdc++.h>
using namespace std;
int INF = 1000000000;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  string s;
  cin >> s;
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    b[i] = s[i] - '0';
  }
  int l_min = -INF;
  int r_max = INF;
  for (int i = 4; i < n; i++){
    if (b[i - 1] == 0 && b[i] == 1){
      l_min = max(l_min, max({a[i - 4], a[i - 3], a[i - 2], a[i - 1], a[i]}) + 1);
    }
    if (b[i - 1] == 1 && b[i] == 0){
      r_max = min(r_max, min({a[i - 4], a[i - 3], a[i - 2], a[i - 1], a[i]}) - 1);
    }
  }
  cout << l_min << ' ' << r_max << endl;
}